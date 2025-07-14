import os
import csv
import pandas as pd
from vllm import LLM, SamplingParams
from vllm.sampling_params import GuidedDecodingParams
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, mean_squared_error
from sklearn.metrics import classification_report
import json

# --- CONFIGURATION ---
DATA_DIR = "/projappl/project_2014646/shreya/data/data"
PAIRS_CSV = "/projappl/project_2014646/shreya/pairs.csv"
GROUND_TRUTH_CSV = "/projappl/project_2014646/shreya/ground_truth.csv"

LLMS = [
    "microsoft/phi-4"# < vllm model name
]

mody_name = "phi-4"

# --- LOAD PAIRS AND GROUND TRUTH ---
pairs_df = pd.read_csv(PAIRS_CSV)
ground_truth_df = pd.read_csv(GROUND_TRUTH_CSV)
ground_truth_map = dict(zip(ground_truth_df['pair-id'], ground_truth_df['similar']))

# --- CODE TRUNCATION FOR CONTEXT FITTING ---
def truncate_code(code, max_lines=50):
    lines = code.splitlines()
    return '\n'.join(lines[:max_lines]) if len(lines) > max_lines else code

# --- ENSEMBLE ASSESSMENT ---
def ensemble_assessment(code1, code2, model_name, n=3):
    predictions = []
    for _ in range(n):
        results, predicted_type, predicted_sim = rag_similarity_assessment(code1, code2, model_name)
        predictions.append((results, predicted_type, predicted_sim))
    # Majority voting on predicted_sim
    sim_votes = [pred[2] for pred in predictions]
    final_sim = max(set(sim_votes), key=sim_votes.count)
    # Most frequent predicted_type
    type_votes = [pred[1] for pred in predictions]
    final_type = max(set(type_votes), key=type_votes.count)
    # Average results for reporting
    avg_results = {t: sum(pred[0][t] for pred in predictions) / n for t in ["Type-1", "Type-2", "Type-3", "Type-4"]}
    return avg_results, final_type, final_sim

# --- THRESHOLD-BASED SIMILARITY DECISION ---
def determine_similarity(results):
    if results['Type-4'] > 0.25:
        return 'Type-4', 1
    else:
        return 'Non-clone', 0

# --- PROMPT V2 WITH STEP-BY-STEP REASONING AND EXAMPLES ---
def rag_similarity_assessment(code1, code2, model_name):
    prompt = f"""You are a code similarity expert. Analyze the following code pair step by step for clone detection.

Definitions:
- Type-1: Identical except for whitespace, comments, layout.
- Type-2: Identical except for variable/function names (plus Type-1 differences).
- Type-3: Similar, but with some statements added/removed/modified (plus Type-2 differences).
- Type-4: Syntactically different but functionally identical (same outputs for same inputs).

Examples:
Type-1: 'int a=5;' vs 'int a = 5; // set a'
Type-2: 'int a=5;' vs 'int b=5;'
Type-3: 'int a=5; print(a);' vs 'int a=5;'
Type-4: 'for(int i=0;i<5;i++)sum+=i;' vs 'sum = sum_of_first_n(5);'

Step-by-step:
1. Are the outputs always identical for all inputs? (Type-4)
2. Are they identical except for whitespace/comments? (Type-1)
3. Are names changed but structure identical? (Type-2)
4. Are there statement-level edits? (Type-3)
Explain your reasoning for each type and provide a confidence score (0-1).

Target Code:
{code1}

Similar Code:
{code2}

Respond ONLY with a JSON object with the following keys: Type-1, Type-2, Type-3, Type-4, each with a confidence score between 0 and 1.
"""
    
    # Call VLLM to get the response
    llm = LLM(model=LLMS[0])
    guided_decoding_params = GuidedDecodingParams(json={
        "type": "object",
        "json_schema": {
            "Type-1": {"type": "number", "minimum": 0, "maximum": 1},
            "Type-2": {"type": "number", "minimum": 0, "maximum": 1},
            "Type-3": {"type": "number", "minimum": 0, "maximum": 1},
            "Type-4": {"type": "number", "minimum": 0, "maximum": 1},
        },
        "required": ["Type-1", "Type-2", "Type-3", "Type-4"]
    }
                                                  )
    sampling_params = SamplingParams(guided_decoding=guided_decoding_params)
    outputs = llm.generate(
        prompts="Classify this sentiment: vLLM is wonderful!",
        sampling_params=sampling_params,
    )
    # Parse the response
    try:
        results = outputs[0].outputs[0].text
    except Exception:
        # Fallback: handle parsing error
        results = {"Type-1": -1, "Type-2": -1, "Type-3": -1, "Type-4": -1}

    predicted_type, predicted_sim = determine_similarity(results)
    return results, predicted_type, predicted_sim

# --- MAIN WORKFLOW ---
for iteration in range(1):
    all_truth = []
    all_preds = []
    output = f"/projappl/project_2014646/shreya/results/RAG_vs_CodeNet_binary_results_{mody_name}iteration_{iteration}.csv"
    with open(output, 'w', newline='') as outfile:
        writer = csv.writer(outfile)
        writer.writerow([
            'PairID', 'File1', 'File2', 'Type-1', 'Type-2', 'Type-3', 'Type-4',
            'PredictedType', 'PredictedSimilar', 'GroundTruthSimilar', 'ModelName'
        ])
        for idx, row in pairs_df.head(10).iterrows():
            file1_path = os.path.join(DATA_DIR, row['file1'])
            file2_path = os.path.join(DATA_DIR, row['file2'])
            pair_id = row['pair-id']
            try:
                with open(file1_path, 'r', encoding='utf-8', errors='ignore') as f1, \
                    open(file2_path, 'r', encoding='utf-8', errors='ignore') as f2:
                    code1 = truncate_code(f1.read())
                    code2 = truncate_code(f2.read())
            except Exception as e:
                print(f"Skipping pair {pair_id} due to file read error: {e}")
                continue

            ground_truth_sim = ground_truth_map.get(pair_id, "Unknown")
            if ground_truth_sim == "Unknown":
                continue
            ground_truth_sim = int(ground_truth_sim)
            for model_name in LLMS:
                results, predicted_type, predicted_sim = ensemble_assessment(code1, code2, model_name, n=3)
                writer.writerow([
                    pair_id, row['file1'], row['file2'],
                    results['Type-1'], results['Type-2'], results['Type-3'], results['Type-4'],
                    predicted_type, predicted_sim, ground_truth_sim, model_name
                ])
                all_truth.append(ground_truth_sim)
                all_preds.append(predicted_sim)

    # --- EVALUATION METRICS ---
    if all_truth and all_preds:
        acc = accuracy_score(all_truth, all_preds)
        prec = precision_score(all_truth, all_preds)
        rec = recall_score(all_truth, all_preds)
        f1 = f1_score(all_truth, all_preds)
        mse = mean_squared_error(all_truth, all_preds)
        with open(f'/projappl/project_2014646/shreya/results/metrics_{mody_name}_iteration_{iteration}.txt', 'w') as f:
            print(f"Accuracy: {acc:.2f}, Precision: {prec:.2f}, Recall: {rec:.2f}, F1-Score: {f1:.2f}, MSE: {mse:.2f}\n", file=f)
            print(classification_report(all_truth, all_preds), file=f)

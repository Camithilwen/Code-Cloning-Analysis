# /// script
# dependencies = [
#   "pandas",
#   "scikit-learn",
#   "lmstudio",
# ]
# ///

import os
import csv
import pandas as pd
import lmstudio as lms
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, mean_squared_error
from sklearn.metrics import classification_report

# --- CONFIGURATION ---
DATA_DIR = "./Project_CodeNet_experimentation_dataset/data"
PAIRS_CSV = "./Project_CodeNet_experimentation_dataset/pairs.csv"
GROUND_TRUTH_CSV = "./Project_CodeNet_experimentation_dataset/ground_truth.csv"
OUTPUT_DIR = "./"

## @var LLMS
#  @brief List of model names to use for clone detection.
LLMS = [
    "mistralai/codestral-22b-v0.1"
]

# --- LOAD PAIRS AND GROUND TRUTH ---
pairs_df = pd.read_csv(PAIRS_CSV)
ground_truth_df = pd.read_csv(GROUND_TRUTH_CSV)
ground_truth_map = dict(zip(ground_truth_df['pair-id'], ground_truth_df['similar']))

# --- CODE TRUNCATION FOR CONTEXT FITTING ---
def truncate_code(code, max_lines=50):
    '''! Truncates code to a limited number of lines for prompt fitting.

 @param code Full code string.
 @param max_lines Maximum number of lines to retain.
 @return Truncated code string.'''
    lines = code.splitlines()
    return '\n'.join(lines[:max_lines]) if len(lines) > max_lines else code

# --- ENSEMBLE ASSESSMENT ---
def ensemble_assessment(code1, code2, model_name, n=3):
    '''!  Performs multiple assessments and aggregates predictions using voting.

 @param code1 First code string.
 @param code2 Second code string.
 @param model_name The name of the LLM model to use.
 @param thr Threshold for similarity.
 @param n Number of repeated assessments for ensemble.
 @return Tuple of (average type scores, majority predicted type, majority binary similarity).
    '''
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
    '''! Determines the predicted type and binary similarity from score dictionary.
    
 @param results Dictionary mapping clone types to similarity scores.
 @return Tuple of (predicted type, binary similarity: 1 if above threshold, else 0).'''
    if results['Type-4'] > 0.25:
        return 'Type-4', 1
    else:
        return 'Non-clone', 0

# --- PROMPT-AWARE ASSESSMENT ---
def rag_similarity_assessment(code1, code2, model_name):
    '''! Sends a prompt to the LLM to classify clone type and score similarities.

 @param code1 First code snippet to evaluate.
 @param code2 Second code snippet to evaluate.
 @param model_name Name of the language model to query.
 @param thr Threshold for determining clone similarity.
 @return Tuple of (type score dictionary, predicted type, binary similarity).'''
    model = lms.llm(model_name)
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
"""

    schema = {
        "type": "object",
        "properties": {
            "Type-1": {"type": "number", "minimum": 0, "maximum": 1},
            "Type-2": {"type": "number", "minimum": 0, "maximum": 1},
            "Type-3": {"type": "number", "minimum": 0, "maximum": 1},
            "Type-4": {"type": "number", "minimum": 0, "maximum": 1},
        },
        "required": ["Type-1", "Type-2", "Type-3", "Type-4"]
    }
    response = model.respond(prompt, response_format=schema)
    results = response.parsed
    predicted_type, predicted_sim = determine_similarity(results)
    return results, predicted_type, predicted_sim

# --- MAIN WORKFLOW ---
## @brief Executes evaluation over prompts and saves results and metrics.
## @var iteration
# @brief This is the number of times you want to run the testing.
for i in range(1):
    iteration = 1
    all_truth = []
    all_preds = []
    output = f"{OUTPUT_DIR}/RAG_vs_CodeNet_binary_results_mistral_codestral22b_iteration_{iteration}.csv"
    with open(output, 'w', newline='') as outfile:
        writer = csv.writer(outfile)
        writer.writerow([
            'PairID', 'File1', 'File2', 'Type-1', 'Type-2', 'Type-3', 'Type-4',
            'PredictedType', 'PredictedSimilar', 'GroundTruthSimilar', 'ModelName'
        ])
        for idx, row in pairs_df.iloc[8320:].iterrows():
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
    ## @brief Calculate and write evaluation metrics for the threshold.
    if all_truth and all_preds:
        acc = accuracy_score(all_truth, all_preds)
        prec = precision_score(all_truth, all_preds)
        rec = recall_score(all_truth, all_preds)
        f1 = f1_score(all_truth, all_preds)
        mse = mean_squared_error(all_truth, all_preds)

        # 
        with open(f'./metricsv2_{iteration}.txt', 'w') as f:
            print(f"Accuracy: {acc:.2f}, Precision: {prec:.2f}, Recall: {rec:.2f}, F1-Score: {f1:.2f}, MSE: {mse:.2f}\n", file=f)
            print(classification_report(all_truth, all_preds), file=f)

import os
import csv
import pandas as pd
from ollama import chat
from pydantic import BaseModel, Field, ValidationError
from typing import Dict
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, classification_report

# --- CONFIGURATION ---
DATA_DIR = "/projappl/project_2014646/shreya/data/data"
PAIRS_CSV = "/projappl/project_2014646/shreya/pairs.csv"
GROUND_TRUTH_CSV = "/projappl/project_2014646/shreya/ground_truth.csv"
OUTPUT_CSV = "/projappl/project_2014646/shreya/results/RAG_vs_CodeNet_binary_results_LLAMA.csv"
LLMS = ["llama3.1:8b"]

# --- PYDANTIC MODEL FOR STRUCTURED OUTPUT ---
class CloneScores(BaseModel):
    type_1: float = Field(..., alias="Type-1", ge=0, le=1)
    type_2: float = Field(..., alias="Type-2", ge=0, le=1)
    type_3: float = Field(..., alias="Type-3", ge=0, le=1)
    type_4: float = Field(..., alias="Type-4", ge=0, le=1)
    class Config:
        allow_population_by_field_name = True

# --- LOAD PAIRS AND GROUND TRUTH ---
pairs_df = pd.read_csv(PAIRS_CSV)
ground_truth_df = pd.read_csv(GROUND_TRUTH_CSV)
ground_truth_map = dict(zip(ground_truth_df['pair-id'], ground_truth_df['similar']))

# --- TYPE TO BINARY SIMILARITY ---
def type_to_binary(predicted_type):
    return 1 if predicted_type in ["Type-1", "Type-4"] else 0

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
    # Majority voting
    sim_votes = [pred[2] for pred in predictions]
    final_sim = max(set(sim_votes), key=sim_votes.count)
    type_votes = [pred[1] for pred in predictions]
    final_type = max(set(type_votes), key=type_votes.count)
    avg_results = {t: sum(pred[0][t] for pred in predictions) / n for t in ["Type-1", "Type-2", "Type-3", "Type-4"]}
    return avg_results, final_type, final_sim

# --- THRESHOLD-BASED SIMILARITY DECISION ---
def determine_similarity(results: Dict[str, float]):
    if results.get('Type-4', 0) > 0.7:
        return "Type-4", 1
    elif results.get('Type-1', 0) > 0.85:
        return "Type-1", 1
    else:
        return "Non-clone", 0

# --- STRUCTURED SIMILARITY ASSESSMENT WITH PYDANTIC ---
def rag_similarity_assessment(code1, code2, model_name):
    prompt = f"""You are a code similarity expert. Analyze the following code pair for clone detection.
Return JSON with confidence scores (0-1) for each clone type.

Definitions:
- Type-1: Identical except for whitespace/comments/layout
- Type-2: Identical except for renamed identifiers
- Type-3: Similar with statements added/removed/modified
- Type-4: Syntactically different but functionally identical

Target Code:
{code1}

Similar Code:
{code2}

Output Format (JSON):
{{
  "Type-1": <confidence_score>,
  "Type-2": <confidence_score>,
  "Type-3": <confidence_score>,
  "Type-4": <confidence_score>
}}
"""
    try:
        response = chat(
            messages=[{'role': 'user', 'content': prompt}],
            model=model_name,
            format=CloneScores.model_json_schema(),
        )
        scores = CloneScores.model_validate_json(response.message.content)
        results = {
            'Type-1': scores.type_1,
            'Type-2': scores.type_2,
            'Type-3': scores.type_3,
            'Type-4': scores.type_4,
        }
    except (ValidationError, Exception) as e:
        print(f"Error parsing model output: {e}")
        results = {"Type-1": 0, "Type-2": 0, "Type-3": 0, "Type-4": 0}

    predicted_type, predicted_sim = determine_similarity(results)
    return results, predicted_type, predicted_sim

# --- MAIN WORKFLOW WITH PROGRESS TRACKING ---
all_truth = []
all_preds = []

with open(OUTPUT_CSV, 'w', newline='') as outfile:
    writer = csv.writer(outfile)
    writer.writerow([
        'PairID', 'File1', 'File2', 'Type-1', 'Type-2', 'Type-3', 'Type-4',
        'PredictedType', 'PredictedSimilar', 'GroundTruthSimilar', 'ModelName'
    ])
    total_pairs = len(pairs_df)
    processed = 0

    for idx, row in pairs_df.iterrows():
        file1_path = os.path.join(DATA_DIR, row['file1'])
        file2_path = os.path.join(DATA_DIR, row['file2'])
        pair_id = row['pair-id']

        try:
            with open(file1_path, 'r', encoding='utf-8', errors='ignore') as f1, \
                 open(file2_path, 'r', encoding='utf-8', errors='ignore') as f2:
                code1 = truncate_code(f1.read())
                code2 = truncate_code(f2.read())
        except Exception as e:
            print(f"Skipping pair {pair_id} due to file error: {e}")
            continue

        ground_truth_sim = ground_truth_map.get(pair_id)
        if ground_truth_sim in ["Unknown", None]:
            continue
        ground_truth_sim = int(ground_truth_sim)

        for model_name in LLMS:
            try:
                results, predicted_type, predicted_sim = ensemble_assessment(code1, code2, model_name, n=3)
                writer.writerow([
                    pair_id, row['file1'], row['file2'],
                    results.get('Type-1', 0), results.get('Type-2', 0),
                    results.get('Type-3', 0), results.get('Type-4', 0),
                    predicted_type, predicted_sim, ground_truth_sim, model_name
                ])
                all_truth.append(ground_truth_sim)
                all_preds.append(predicted_sim)
            except Exception as e:
                print(f"Error processing pair {pair_id}: {e}")

        processed += 1
        if processed % 10 == 0:
            print(f"Processed {processed}/{total_pairs} pairs ({processed/total_pairs:.1%})")

# --- EVALUATION METRICS ---
if all_truth and all_preds:
    acc = accuracy_score(all_truth, all_preds)
    prec = precision_score(all_truth, all_preds)
    rec = recall_score(all_truth, all_preds)
    f1 = f1_score(all_truth, all_preds)

    metrics_path = '/projappl/project_2014646/shreya/results/metricsv2.txt'
    with open(metrics_path, 'w') as f:
        f.write(f"Total Pairs: {len(all_truth)}\n")
        f.write(f"Accuracy: {acc:.4f}\nPrecision: {prec:.4f}\nRecall: {rec:.4f}\nF1: {f1:.4f}\n\n")
        f.write("Classification Report:\n")
        f.write(classification_report(all_truth, all_preds))

    print(f"Evaluation metrics saved to {metrics_path}")
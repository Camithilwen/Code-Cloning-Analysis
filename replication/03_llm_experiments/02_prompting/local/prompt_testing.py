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
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, classification_report

# --- CONFIGURATION ---
## @var DATA_DIR
#  @brief Path to the directory containing code files for similarity comparison.
DATA_DIR = "./Project_CodeNet_experimentation_dataset/data"

## @var PAIRS_CSV
#  @brief CSV file containing file pairs to compare.
PAIRS_CSV = "./Project_CodeNet_experimentation_dataset/pairs.csv"

## @var GROUND_TRUTH_CSV
#  @brief CSV file containing ground truth similarity labels for file pairs.
GROUND_TRUTH_CSV = "./Project_CodeNet_experimentation_dataset/ground_truth.csv"

## @var OUTPUT_CSV
# @brief The output CSV name.
OUTPUT_CSV = "./RAG_vs_CodeNet_binary_results_scoder_simple_prompts3-1.csv"

## @var METRICS_TXT
# @brief The metrics file name.
METRICS_TXT = "./metricsv2p3-1.txt"

## @var LLMS
#  @brief List of model names to use for clone detection.
LLMS = [
    "starcoder2-15b-instruct-v0.1"
]

##@var PROMPTS
# @brief Name of all prompts to be tested on.
PROMPTS = [
    # Prompt 1
    """Definitions:
    - Type-1: Identical except for whitespace, comments, layout.
    - Type-2: Identical except for variable/function names (plus Type-1 differences).
    - Type-3: Similar, but with some statements added/removed/modified (plus Type-2 differences).
    - Type-4: Syntactically different but functionally identical (same outputs for same inputs).
    Analyze the following two code snippets and determine whether they are clones, regardless of
    the programming language. Respond with 'yes' if the code snippets are clones or 'no' if not for
    each category of Type-1, Type-2, Type-3, and Type-4.
    Snippet 1:
    {code1}
    Snippet 2:
    {code2}
    """,
    # Prompt 2
    """
    Definitions:
    - Type-1: Identical except for whitespace, comments, layout.
    - Type-2: Identical except for variable/function names (plus Type-1 differences).
    - Type-3: Similar, but with some statements added/removed/modified (plus Type-2 differences).
    - Type-4: Syntactically different but functionally identical (same outputs for same inputs).
    Analyze the following two code snippets for code clone detection, regardless of the programming language. You should first report which lines of code are more similar. Then based on the
    report, please answer whether these two codes are a clone pair. The response should be 'yes'
    or 'no' for each Type.
    Snippet 1:
    {code1}
    Snippet 2:
    {code2}
    """,
    # Prompt 3
    """You are a code similarity expert. Analyze the following code pair step by step for clone detection.

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
Explain your reasoning for each type and provide a 'yes' or 'no' for each category.

Target Code:
{code1}

Similar Code:
{code2}
"""
]

# --- LOAD DATA ---
## @var pairs_df
#  @brief DataFrame of file pairs to compare.
pairs_df = pd.read_csv(PAIRS_CSV)

## @var ground_truth_df
#  @brief DataFrame containing ground truth similarity labels.
ground_truth_df = pd.read_csv(GROUND_TRUTH_CSV)

## @var ground_truth_map
#  @brief Dictionary mapping pair IDs to binary similarity values.
ground_truth_map = dict(zip(ground_truth_df['pair-id'], ground_truth_df['similar']))

# --- ENSEMBLE ASSESSMENT ---
def ensemble_assessment(code1, code2, model_name, prompt, n=3):
    '''! Performs multiple assessments and aggregates predictions using voting.

 @param code1 First code string.
 @param code2 Second code string.
 @param model_name The name of the LLM model to use.
 @param thr Threshold for similarity.
 @param n Number of repeated assessments for ensemble.
 @return Tuple of (average type scores, majority predicted type, majority binary similarity).
 '''
    predictions = []
    for _ in range(n):
        results, predicted_type, predicted_sim = rag_similarity_assessment(code1, code2, model_name, prompt)
        predictions.append((results, predicted_type, predicted_sim))
    # Majority voting on predicted_sim
    sim_votes = [pred[2] for pred in predictions]
    final_sim = max(set(sim_votes), key=sim_votes.count)
    # Most frequent predicted_type
    type_votes = [pred[1] for pred in predictions]
    final_type = max(set(type_votes), key=type_votes.count)
    # Average results for reporting
    average_res = dict()
    for t in ["Type-1", "Type-2", "Type-3", "Type-4"]:
        sum_yes = 0
        for pred in predictions:
            n = pred[0][t]
            print(f'n: {n}')
            if n == 'yes' or n=='Yes' or 'yes' in n or 'Yes' in n:
                n = 1
            else:
                n = 0
            sum_yes += n
        try:
            average_res[t] = sum_yes / n
        except ZeroDivisionError:
            average_res[t] = 0
    return average_res, final_type, final_sim

# --- THRESHOLD-BASED SIMILARITY DECISION ---
def determine_similarity(results):
    '''!  Determines the predicted type and binary similarity from score dictionary.

 @param results Dictionary mapping clone types to similarity scores.
 @param min_threshold Minimum similarity score to consider as a valid clone.
 @return Tuple of (predicted type, binary similarity: 1 if above threshold, else 0).'''
    if 'yes' in list(results.values()):
        if list(results.keys())[list(results.values()).index('yes')] == 'Type-4':
            return 'Type-4', 1
        else:
            return 'Non-clone', 0
    else:
        return 'Non-clone', 0

# --- PROMPT-AWARE ASSESSMENT ---
def rag_similarity_assessment(code1, code2, model_name, prompt):
    '''!  Sends a prompt to the LLM to classify clone type and score similarities.
    
 @param code1 First code snippet to evaluate.
 @param code2 Second code snippet to evaluate.
 @param model_name Name of the language model to query.
 @param thr Threshold for determining clone similarity.
 @return Tuple of (type score dictionary, predicted type, binary similarity).
 '''
    model = lms.llm(model_name)
    # Format the prompt with the code snippets
    prompt_filled = prompt.format(code1=code1, code2=code2)
    schema = {
    "type": "object",
    "properties": {
        "Type-1": {"type": "string", "enum": ["yes", "no"]},
        "Type-2": {"type": "string", "enum": ["yes", "no"]},
        "Type-3": {"type": "string", "enum": ["yes", "no"]},
        "Type-4": {"type": "string", "enum": ["yes", "no"]}
    },
    "required": ["Type-1", "Type-2", "Type-3", "Type-4"]
}

    response = model.respond(prompt_filled, response_format=schema)
    results = response.parsed
    predicted_type, predicted_sim = determine_similarity(results)
    return results, predicted_type, predicted_sim

# --- MAIN WORKFLOW ---
## @brief Executes evaluation over prompts and saves results and metrics.
results_by_prompt = {i: {'truth': [], 'preds': []} for i in range(len(PROMPTS))}

with open(OUTPUT_CSV, 'w', newline='') as outfile:
    writer = csv.writer(outfile)
    writer.writerow([
        'PromptID', 'PairID', 'File1', 'File2', 'Type-1', 'Type-2', 'Type-3', 'Type-4',
        'PredictedType', 'PredictedSimilar', 'GroundTruthSimilar', 'ModelName'
    ])
    for prompt_id, prompt in enumerate(PROMPTS):
        print(f"Processing Prompt {prompt_id+1}...")
        ## @brief The value in .head() is the number of rows that will be gone over. I 
        # recommend 60 if you have under 30 minutes and 1000 if you leave it on over night.
        for idx, row in pairs_df.head(60).iterrows():
            file1_path = os.path.join(DATA_DIR, row['file1'])
            file2_path = os.path.join(DATA_DIR, row['file2'])
            pair_id = row['pair-id']
            try:
                with open(file1_path, 'r', encoding='utf-8', errors='ignore') as f1, \
                     open(file2_path, 'r', encoding='utf-8', errors='ignore') as f2:
                    code1 = f1.read()
                    code2 = f2.read()
            except Exception as e:
                print(f"Skipping pair {pair_id} due to file read error: {e}")
                continue
            ground_truth_sim = ground_truth_map.get(pair_id, "Unknown")
            if ground_truth_sim == "Unknown":
                continue
            ground_truth_sim = int(ground_truth_sim)
            for model_name in LLMS:
                results, predicted_type, predicted_sim = ensemble_assessment(code1, code2, model_name, prompt, n=3)
                writer.writerow([
                    prompt_id, pair_id, row['file1'], row['file2'],
                    results['Type-1'], results['Type-2'], results['Type-3'], results['Type-4'],
                    predicted_type, predicted_sim, ground_truth_sim, model_name
                ])
                results_by_prompt[prompt_id]['truth'].append(ground_truth_sim)
                results_by_prompt[prompt_id]['preds'].append(predicted_sim)

# --- EVALUATION METRICS ---
## @brief Calculate and write evaluation metrics for the prompt.
with open(METRICS_TXT, 'w') as f:
    for prompt_id in range(len(PROMPTS)):
        truth = results_by_prompt[prompt_id]['truth']
        preds = results_by_prompt[prompt_id]['preds']
        if truth and preds:
            acc = accuracy_score(truth, preds)
            prec = precision_score(truth, preds, zero_division=0)
            rec = recall_score(truth, preds, zero_division=0)
            f1s = f1_score(truth, preds, zero_division=0)
            print(f"\n--- Metrics for Prompt {prompt_id+1} ---", file=f)
            print(f"Accuracy: {acc:.2f}, Precision: {prec:.2f}, Recall: {rec:.2f}, F1: {f1s:.2f}", file=f)
            print(classification_report(truth, preds, zero_division=0), file=f)
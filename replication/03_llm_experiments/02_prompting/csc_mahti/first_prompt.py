# /// script
# dependencies = [
#   "pandas",
#   "scikit-learn",
#   "pydantic",
#   "ollama",
# ]
# ///


import os
import csv
import pandas as pd
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, mean_squared_error
from sklearn.metrics import classification_report
import json
from pydantic import Field
from enum import Enum
from typing import List
from llama_index.llms.ollama import Ollama
from llama_index.core.bridge.pydantic import BaseModel

# --- CONFIGURATION ---
## @var DATA_DIR
#  @brief Path to the directory containing code files for similarity comparison.
DATA_DIR = "./data/data"

## @var PAIRS_CSV
#  @brief CSV file containing file pairs to compare.
PAIRS_CSV = "./pairs.csv"

## @var GROUND_TRUTH_CSV
#  @brief CSV file containing ground truth similarity labels for file pairs.
GROUND_TRUTH_CSV = "./ground_truth.csv"

## @var LLMS
#  @brief List of model names to use for clone detection.
LLMS = [
    "llama3.1:latest"
]

## @brief Defines the Confidence class, which is used to determine the structured ouput. 
class Confidence(BaseModel):
    type1: str
    type2: str
    type3: str
    type4: str

##@var PROMPTS
# @brief The first prompt we tested on.
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
    Respond ONLY with a JSON object with the following keys: type1, type2, type3, type4, each with either "yes" or "no" for each key.
    Snippet 1:
    {code1}
    Snippet 2:
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

# -- JSON MAPPER --
## @fn safe_parse_response(response)
#  @brief Translates the given response from the model into the proper dictionary format.
#  @param response The RAG output.
def safe_parse_response(response):
    import json
    print(type(response))
    json_response = json.loads(response.text)
    print(f'json: {json_response}')
    pdantic_results = response.raw
    print(f'pydantic: {pdantic_results}')
    try:
        results = {"Type-1": pdantic_results.type1, "Type-2": pdantic_results.type2, 
                "Type-3": pdantic_results.type3, "Type-4": pdantic_results.type4}
        return results
    except Exception as e:
        print("Parsing error 1: ", e)
        try:
            results = {"Type-1": json_response["type1"], "Type-2": json_response["type2"], 
                "Type-3": json_response["type3"], "Type-4": json_response["type4"]}
            return results
        except Exception as e:
            print("Parsing error 2: ", e)
            return {"Type-1": "no", "Type-2": "no", "Type-3": "no", "Type-4": "no"} 

## @fn ensemble_assessment(code1, code2, model_name, thr, n=3)
#  @brief Performs multiple assessments and aggregates predictions using voting.
#  @param code1 First code string.
#  @param code2 Second code string.
#  @param model_name The name of the LLM model to use.
#  @param thr Threshold for similarity.
#  @param n Number of repeated assessments for ensemble.
#  @return Tuple of (average type scores, majority predicted type, majority binary similarity).
def ensemble_assessment(code1, code2, model_name, prompt, n=3):
    predictions = []
    for _ in range(n):
        results, predicted_type, predicted_sim = rag_similarity_assessment(code1, code2, model_name, prompt)
        predictions.append((results, predicted_type, predicted_sim))
    # Majority voting on predicted_sim
    sim_votes = [pred[2] for pred in predictions]
    final_sim = max(set(sim_votes), key=sim_votes.count)
    print("sim votes: ", sim_votes)
    print("final_sim: ", final_sim)
    # Most frequent predicted_type
    type_votes = [pred[1] for pred in predictions]
    final_type = max(set(type_votes), key=type_votes.count)
    print("type_votes: ", type_votes)
    print("final_type: ", final_type)
    # Average results for reporting
    average_res = dict()
    for t in ["Type-1", "Type-2", "Type-3", "Type-4"]:
        sum_yes = 0
        for pred in predictions:
            n = pred[0][t]
            # print(f'n: {n}')
            if n == 'yes' or n=='Yes' or 'yes' in n or 'Yes' in n:
                n = 1
            else:
                n = 0
            sum_yes += n
        try:
            average_res[t] = sum_yes / n
        except ZeroDivisionError:
            average_res[t] = 0
    print("average res", average_res)
    for key, value in average_res.items():
        if value == 0:
            average_res[key] = "no"
        else:
            average_res[key] = "yes"
    print("average res", average_res)
    return average_res, final_type, final_sim

## @fn determine_similarity(results, min_threshold=0.1)
#  @brief Determines the predicted type and binary similarity from score dictionary.
#  @param results Dictionary mapping clone types to similarity scores.
#  @param min_threshold Minimum similarity score to consider as a valid clone.
#  @return Tuple of (predicted type, binary similarity: 1 if above threshold, else 0).
def determine_similarity(results):
    if 'yes' in list(results.values()):
        if list(results.keys())[list(results.values()).index('yes')] == 'Type-4':
            return 'Type-4', 1
        else:
            return 'Non-clone', 0
    else:
        return 'Non-clone', 0

# --- PROMPT-AWARE ASSESSMENT ---
## @fn rag_similarity_assessment(code1, code2, model_name, thr)
#  @brief Sends a prompt to the LLM to classify clone type and score similarities.
#  @param code1 First code snippet to evaluate.
#  @param code2 Second code snippet to evaluate.
#  @param model_name Name of the language model to query.
#  @param thr Threshold for determining clone similarity.
#  @return Tuple of (type score dictionary, predicted type, binary similarity).
def rag_similarity_assessment(code1, code2, model_name, prompt):
    # Format the prompt with the code snippets
    prompt_filled = prompt.format(code1=code1, code2=code2)

    llm = Ollama(model="llama3.1:latest", request_timeout=120.0)
    sllm = llm.as_structured_llm(Confidence)
    response = sllm.complete(prompt)

    print(f'Output: {response}\n')
    results = safe_parse_response(response)
    print('results:', results)

    predicted_type, predicted_sim = determine_similarity(results)
    print("preds: ", predicted_type, predicted_sim)
    return results, predicted_type, predicted_sim

# --- MAIN WORKFLOW ---
## @brief Executes evaluation over prompts and saves results and metrics.
results_by_prompt = {i: {'truth': [], 'preds': []} for i in range(len(PROMPTS))}

## @var iteration
# @brief This is the number of times you want to run the testing.
for iteration in range(1):
    output = f"./results/prompt_first_results_{LLMS[0]}_iteration_{iteration}.csv"
    with open(output, 'w', newline='') as outfile:
        writer = csv.writer(outfile)
        writer.writerow([
            'PromptID', 'PairID', 'File1', 'File2', 'Type-1', 'Type-2', 'Type-3', 'Type-4',
            'PredictedType', 'PredictedSimilar', 'GroundTruthSimilar', 'ModelName'
        ])
        for prompt_id, prompt in enumerate(PROMPTS):
            print(f"Processing Prompt {prompt_id+1}...")
            for idx, row in pairs_df.iterrows():
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
    ## @brief Calculate and write evaluation metrics for the threshold.
    metrics_output = f'./results/prompt_first{LLMS[0]}_iteration_{iteration}.txt'
    with open(metrics_output, 'w') as f:
        for prompt_id in range(len(PROMPTS)):
            truth = results_by_prompt[prompt_id]['truth']
            preds = results_by_prompt[prompt_id]['preds']
            if truth and preds:
                acc = accuracy_score(truth, preds)
                prec = precision_score(truth, preds, zero_division=0)
                rec = recall_score(truth, preds, zero_division=0)
                f1s = f1_score(truth, preds, zero_division=0)
                mse = mean_squared_error(truth, preds, zero_division=0)
                print(f"\n--- Metrics for Prompt {prompt_id+1} ---", file=f)
                print(f"Accuracy: {acc:.2f}, Precision: {prec:.2f}, Recall: {rec:.2f}, F1: {f1s:.2f}, MSE: {mse:.2f}\n", file=f)
                print(classification_report(truth, preds, zero_division=0), file=f)
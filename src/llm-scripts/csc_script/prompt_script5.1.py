import os
import csv
import pandas as pd
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, classification_report, mean_squared_error
import json
import ollama
import re

# --- CONFIGURATION ---
DATA_DIR = "/projappl/project_2014646/shreya/data/data"
PAIRS_CSV = "/projappl/project_2014646/shreya/pairs.csv"
GROUND_TRUTH_CSV = "/projappl/project_2014646/shreya/ground_truth.csv"

LLMS = [
    "deepseek-r1:14b"
]

# --- PROMPTS ---
PROMPTS = [
    # Prompt 1
    """Definitions:
    - Type-1: Identical except for whitespace, comments, layout.
    - Type-2: Identical except for variable/function names (plus Type-1 differences).
    - Type-3: Similar, but with some statements added/removed/modified (plus Type-2 differences).
    - Type-4: Syntactically different but functionally identical (same outputs for same inputs).
    
    Analyze the following two code snippets and determine whether they are clones, regardless of
    the programming language. 
    
    Snippet 1:
    {code1}
    
    Snippet 2:
    {code2}
    
    IMPORTANT: Respond with ONLY a valid JSON object in this exact format:
    {{"Type-1": "yes", "Type-2": "no", "Type-3": "no", "Type-4": "no"}}
    
    Replace "yes"/"no" with your assessment for each type. Do not include any other text.
    """,
    
    # Prompt 2
    """Definitions:
    - Type-1: Identical except for whitespace, comments, layout.
    - Type-2: Identical except for variable/function names (plus Type-1 differences).
    - Type-3: Similar, but with some statements added/removed/modified (plus Type-2 differences).
    - Type-4: Syntactically different but functionally identical (same outputs for same inputs).
    
    Analyze the following two code snippets for code clone detection, regardless of the programming language. 
    First identify which lines of code are similar, then determine if these are clone pairs.
    
    Snippet 1:
    {code1}
    
    Snippet 2:
    {code2}
    
    IMPORTANT: Respond with ONLY a valid JSON object in this exact format:
    {{"Type-1": "yes", "Type-2": "no", "Type-3": "no", "Type-4": "no"}}
    
    Replace "yes"/"no" with your assessment for each type. Do not include any other text.
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

    Target Code:
    {code1}

    Similar Code:
    {code2}
    
    IMPORTANT: Respond with ONLY a valid JSON object in this exact format:
    {{"Type-1": "yes", "Type-2": "no", "Type-3": "no", "Type-4": "no"}}
    
    Replace "yes"/"no" with your assessment for each type. Do not include any other text.
    """
]

# --- LOAD PAIRS AND GROUND TRUTH ---
pairs_df = pd.read_csv(PAIRS_CSV)
ground_truth_df = pd.read_csv(GROUND_TRUTH_CSV)
ground_truth_map = dict(zip(ground_truth_df['pair-id'], ground_truth_df['similar']))

# --- CODE TRUNCATION FOR CONTEXT FITTING ---
def truncate_code(code, max_lines=50):
    lines = code.splitlines()
    return '\n'.join(lines[:max_lines]) if len(lines) > max_lines else code

# --- IMPROVED JSON PARSING ---
def parse_json_response(response_text):
    """
    Enhanced JSON parsing with multiple fallback strategies for yes/no responses
    """
    # First, try direct JSON parsing
    try:
        result = json.loads(response_text.strip())
        # Validate that all required keys exist and have yes/no values
        if all(key in result for key in ["Type-1", "Type-2", "Type-3", "Type-4"]):
            # Normalize values to "yes" or "no"
            for key in result:
                if isinstance(result[key], str):
                    result[key] = result[key].lower().strip()
                    if result[key] not in ["yes", "no"]:
                        result[key] = "yes" if "yes" in result[key] else "no"
            return result
    except json.JSONDecodeError:
        pass
    
    # Try to extract JSON from text using regex
    json_patterns = [
        r'\{[^{}]*"Type-1"[^{}]*\}',  # Simple JSON object
        r'\{.*?"Type-1".*?\}',        # More flexible JSON
        r'\{.*\}',                    # Any JSON-like structure
    ]
    
    for pattern in json_patterns:
        matches = re.findall(pattern, response_text, re.DOTALL)
        for match in matches:
            try:
                result = json.loads(match)
                if all(key in result for key in ["Type-1", "Type-2", "Type-3", "Type-4"]):
                    # Normalize values
                    for key in result:
                        if isinstance(result[key], str):
                            result[key] = result[key].lower().strip()
                            result[key] = "yes" if "yes" in result[key] else "no"
                    return result
            except json.JSONDecodeError:
                continue
    
    # Try to parse structured text line by line
    lines = response_text.split('\n')
    result = {}
    
    for line in lines:
        line = line.strip().lower()
        for type_name in ["type-1", "type-2", "type-3", "type-4"]:
            if type_name in line:
                # Look for yes/no in the line
                if "yes" in line:
                    result[type_name.replace("-", "-").title()] = "yes"
                elif "no" in line:
                    result[type_name.replace("-", "-").title()] = "no"
    
    # If we found all required keys, return the result
    if len(result) == 4:
        return result
    
    # Try regex patterns for each type
    type_patterns = {
        "Type-1": r"type-?1.*?(?:yes|no)",
        "Type-2": r"type-?2.*?(?:yes|no)",
        "Type-3": r"type-?3.*?(?:yes|no)",
        "Type-4": r"type-?4.*?(?:yes|no)"
    }
    
    result = {}
    for type_name, pattern in type_patterns.items():
        matches = re.findall(pattern, response_text.lower(), re.IGNORECASE)
        if matches:
            result[type_name] = "yes" if "yes" in matches[0] else "no"
    
    if len(result) == 4:
        return result
    
    # Final fallback: return default values
    print(f"Failed to parse JSON response: {response_text[:200]}...")
    return {"Type-1": "no", "Type-2": "no", "Type-3": "no", "Type-4": "no"}

# --- ENSEMBLE ASSESSMENT ---
def ensemble_assessment(code1, code2, model_name, prompt, n=3):
    predictions = []
    for i in range(n):
        try:
            results, predicted_type, predicted_sim = rag_similarity_assessment(code1, code2, model_name, prompt)
            predictions.append((results, predicted_type, predicted_sim))
            print(f"Ensemble {i+1}: {predicted_type}, sim={predicted_sim}")
        except Exception as e:
            print(f"Error in ensemble assessment {i+1}: {e}")
            # Add default prediction
            default_results = {"Type-1": "no", "Type-2": "no", "Type-3": "no", "Type-4": "no"}
            predictions.append((default_results, "Non-clone", 0))
    
    if not predictions:
        # Complete fallback
        default_results = {"Type-1": "no", "Type-2": "no", "Type-3": "no", "Type-4": "no"}
        return default_results, "Non-clone", 0
    
    # Majority voting on predicted_sim
    sim_votes = [pred[2] for pred in predictions]
    final_sim = max(set(sim_votes), key=sim_votes.count)
    
    # Most frequent predicted_type
    type_votes = [pred[1] for pred in predictions]
    final_type = max(set(type_votes), key=type_votes.count)
    
    # Calculate average results - convert yes/no to 1/0 for averaging
    average_res = {}
    for t in ["Type-1", "Type-2", "Type-3", "Type-4"]:
        yes_count = 0
        valid_predictions = 0
        
        for pred in predictions:
            if t in pred[0]:
                valid_predictions += 1
                response = pred[0][t]
                if isinstance(response, str):
                    response = response.lower().strip()
                    if response == 'yes' or 'yes' in response:
                        yes_count += 1
                elif response == 1:  # Handle numeric responses
                    yes_count += 1
        
        if valid_predictions > 0:
            average_res[t] = yes_count / valid_predictions
        else:
            average_res[t] = 0
    
    return average_res, final_type, final_sim

# --- THRESHOLD-BASED SIMILARITY DECISION ---
def determine_similarity(results):
    """
    Determine if codes are similar based on clone type results
    """
    # Check if any type has "yes"
    for type_name, response in results.items():
        if isinstance(response, str):
            response = response.lower().strip()
            if response == "yes" or "yes" in response:
                if type_name == "Type-4":
                    return "Type-4", 1
                else:
                    return f"{type_name}", 1
    
    return "Non-clone", 0

# --- PROMPT-AWARE ASSESSMENT ---
def rag_similarity_assessment(code1, code2, model_name, prompt):
    # Truncate code to fit context
    code1 = truncate_code(code1)
    code2 = truncate_code(code2)
    
    # Format the prompt with the code snippets
    prompt_filled = prompt.format(code1=code1, code2=code2)
    
    try:
        # Call Ollama to get the response
        result = ollama.generate(
            model=model_name,
            prompt=prompt_filled,
            options={
                "temperature": 0.1,  # Lower temperature for more consistent output
                "top_p": 0.9,
                "num_predict": 150   # Limit response length
            }
        )
        response_text = result['response']
        
        # Debug output
        print(f"Raw response: {response_text}")
        
        # Parse the response using improved parser
        results = parse_json_response(response_text)
        
        # Ensure all required keys exist
        for key in ["Type-1", "Type-2", "Type-3", "Type-4"]:
            if key not in results:
                results[key] = "no"
        
        predicted_type, predicted_sim = determine_similarity(results)
        return results, predicted_type, predicted_sim
        
    except Exception as e:
        print(f"Error in rag_similarity_assessment: {e}")
        # Return default values
        results = {"Type-1": "no", "Type-2": "no", "Type-3": "no", "Type-4": "no"}
        return results, "Non-clone", 0

# --- MAIN WORKFLOW ---
results_by_prompt = {i: {'truth': [], 'preds': []} for i in range(len(PROMPTS))}

for iteration in range(1):  # Reduced for testing
    print(f"Starting iteration {iteration}")
    output = f"/projappl/project_2014646/shreya/results/RAG_vs_CodeNet_prompt_results_ds14b_iteration_{iteration}.csv"
    
    with open(output, 'w', newline='') as outfile:
        writer = csv.writer(outfile)
        writer.writerow([
            'PromptID', 'PairID', 'File1', 'File2', 'Type-1', 'Type-2', 'Type-3', 'Type-4',
            'PredictedType', 'PredictedSimilar', 'GroundTruthSimilar', 'ModelName'
        ])
        
        for prompt_id, prompt in enumerate(PROMPTS):
            print(f"Processing Prompt {prompt_id+1}...")
            
            # Process a subset for testing
            for idx, row in pairs_df.head(100).iterrows():  # Reduced for testing
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
                    print(f"Processing pair {pair_id} with prompt {prompt_id+1}")
                    results, predicted_type, predicted_sim = ensemble_assessment(code1, code2, model_name, prompt, n=3)
                    
                    writer.writerow([
                        prompt_id, pair_id, row['file1'], row['file2'],
                        results['Type-1'], results['Type-2'], results['Type-3'], results['Type-4'],
                        predicted_type, predicted_sim, ground_truth_sim, model_name
                    ])
                    
                    results_by_prompt[prompt_id]['truth'].append(ground_truth_sim)
                    results_by_prompt[prompt_id]['preds'].append(predicted_sim)

    # --- EVALUATION METRICS ---
    metrics_output = f'/projappl/project_2014646/shreya/results/metrics_ds14b_prompt_iteration_{iteration}.txt'
    with open(metrics_output, 'w') as f:
        print(f"Iteration {iteration} Results:", file=f)
        
        for prompt_id in range(len(PROMPTS)):
            truth = results_by_prompt[prompt_id]['truth']
            preds = results_by_prompt[prompt_id]['preds']
            
            if truth and preds:
                acc = accuracy_score(truth, preds)
                prec = precision_score(truth, preds, zero_division=0)
                rec = recall_score(truth, preds, zero_division=0)
                f1s = f1_score(truth, preds, zero_division=0)
                mse = mean_squared_error(truth, preds)
                
                print(f"\n--- Metrics for Prompt {prompt_id+1} ---", file=f)
                print(f"Accuracy: {acc:.2f}, Precision: {prec:.2f}, Recall: {rec:.2f}, F1: {f1s:.2f}, MSE: {mse:.2f}\n", file=f)
                print(classification_report(truth, preds, zero_division=0), file=f)
                
                print(f"Prompt {prompt_id+1} - Accuracy: {acc:.2f}, F1: {f1s:.2f}")
            else:
                print(f"Prompt {prompt_id+1} - No valid predictions generated", file=f)
                print(f"Prompt {prompt_id+1} - No valid predictions generated")

print("Processing complete!")
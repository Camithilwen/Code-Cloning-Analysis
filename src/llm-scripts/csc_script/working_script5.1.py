import os
import csv
import pandas as pd
import ollama
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, mean_squared_error
from sklearn.metrics import classification_report
import json
import re

# --- CONFIGURATION ---
DATA_DIR = "/projappl/project_2014646/shreya/data/data"
PAIRS_CSV = "/projappl/project_2014646/shreya/pairs.csv"
GROUND_TRUTH_CSV = "/projappl/project_2014646/shreya/ground_truth.csv"

LLMS = [
    "deepseek-r1:14b"# < ollama model name
]

# --- LOAD PAIRS AND GROUND TRUTH ---
pairs_df = pd.read_csv(PAIRS_CSV)
ground_truth_df = pd.read_csv(GROUND_TRUTH_CSV)
ground_truth_map = dict(zip(ground_truth_df['pair-id'], ground_truth_df['similar']))

# --- TYPE TO BINARY SIMILARITY ---
def type_to_binary(predicted_type):
    return 1 if predicted_type in ["Type-4"] else 0

# --- CODE TRUNCATION FOR CONTEXT FITTING ---
def truncate_code(code, max_lines=50):
    lines = code.splitlines()
    return '\n'.join(lines[:max_lines]) if len(lines) > max_lines else code

# --- IMPROVED JSON PARSING ---
def parse_json_response(response_text):
    """
    Enhanced JSON parsing with multiple fallback strategies
    """
    # First, try direct JSON parsing
    try:
        return json.loads(response_text.strip())
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
                    return result
            except json.JSONDecodeError:
                continue
    
    # Try to parse line by line for structured output
    lines = response_text.split('\n')
    result = {}
    for line in lines:
        for type_name in ["Type-1", "Type-2", "Type-3", "Type-4"]:
            if type_name in line:
                # Extract number from line
                numbers = re.findall(r'(\d*\.?\d+)', line)
                if numbers:
                    try:
                        score = float(numbers[0])
                        if 0 <= score <= 1:
                            result[type_name] = score
                    except ValueError:
                        pass
    
    # If we found all required keys, return the result
    if len(result) == 4:
        return result
    
    # Final fallback: return default values
    print(f"Failed to parse JSON response: {response_text[:200]}...")
    return {"Type-1": 0.0, "Type-2": 0.0, "Type-3": 0.0, "Type-4": 0.0}

# --- ENSEMBLE ASSESSMENT ---
def ensemble_assessment(code1, code2, model_name, n=3):
    predictions = []
    for i in range(n):
        try:
            results, predicted_type, predicted_sim = rag_similarity_assessment(code1, code2, model_name)
            predictions.append((results, predicted_type, predicted_sim))
            print(f"Ensemble {i+1}: {predicted_type}, sim={predicted_sim}")
        except Exception as e:
            print(f"Error in ensemble assessment {i+1}: {e}")
            # Add default prediction
            default_results = {"Type-1": 0.0, "Type-2": 0.0, "Type-3": 0.0, "Type-4": 0.0}
            predictions.append((default_results, "Non-clone", 0))
    
    if not predictions:
        # Complete fallback
        default_results = {"Type-1": 0.0, "Type-2": 0.0, "Type-3": 0.0, "Type-4": 0.0}
        return default_results, "Non-clone", 0
    
    # Majority voting on predicted_sim
    sim_votes = [pred[2] for pred in predictions]
    final_sim = max(set(sim_votes), key=sim_votes.count)
    
    # Most frequent predicted_type
    type_votes = [pred[1] for pred in predictions]
    final_type = max(set(type_votes), key=type_votes.count)
    
    # Average results for reporting
    avg_results = {}
    for t in ["Type-1", "Type-2", "Type-3", "Type-4"]:
        scores = [pred[0][t] for pred in predictions if t in pred[0]]
        avg_results[t] = sum(scores) / len(scores) if scores else 0.0
    
    return avg_results, final_type, final_sim

# --- THRESHOLD-BASED SIMILARITY DECISION ---
def determine_similarity(results):
    if results['Type-4'] > 0.25:
        return 'Type-4', 1
    else:
        return 'Non-clone', 0

# --- IMPROVED PROMPT WITH CLEARER INSTRUCTIONS ---
def rag_similarity_assessment(code1, code2, model_name):
    prompt = f"""You are a code similarity expert. Analyze the following code pair for clone detection.

Clone Types:
- Type-1: Identical except for whitespace, comments, layout
- Type-2: Identical except for variable/function names (plus Type-1 differences)
- Type-3: Similar, but with some statements added/removed/modified (plus Type-2 differences)
- Type-4: Syntactically different but functionally identical (same outputs for same inputs)

Code 1:
```
{code1}
```

Code 2:
```
{code2}
```

IMPORTANT: You must respond with ONLY a valid JSON object in this exact format:
{{"Type-1": 0.0, "Type-2": 0.0, "Type-3": 0.0, "Type-4": 0.0}}

Replace the 0.0 values with your confidence scores between 0 and 1 for each type.
Do not include any other text, explanations, or formatting.
"""

    try:
        # Call Ollama to get the response
        result = ollama.generate(
            model=model_name,
            prompt=prompt,
            options={
                "temperature": 0.1,  # Lower temperature for more consistent output
                "top_p": 0.9,
                "num_predict": 100   # Limit response length
            }
        )
        response_text = result['response']
        
        # Debug output
        print(f"Raw response: {response_text}")
        
        # Parse the response using improved parser
        results = parse_json_response(response_text)
        
        # Ensure all values are valid floats between 0 and 1
        for key in ["Type-1", "Type-2", "Type-3", "Type-4"]:
            if key not in results:
                results[key] = 0.0
            else:
                try:
                    results[key] = float(results[key])
                    results[key] = max(0.0, min(1.0, results[key]))  # Clamp to [0,1]
                except (ValueError, TypeError):
                    results[key] = 0.0
        
        predicted_type, predicted_sim = determine_similarity(results)
        return results, predicted_type, predicted_sim
        
    except Exception as e:
        print(f"Error in rag_similarity_assessment: {e}")
        # Return default values
        results = {"Type-1": 0.0, "Type-2": 0.0, "Type-3": 0.0, "Type-4": 0.0}
        return results, "Non-clone", 0

# --- MAIN WORKFLOW ---
for iteration in range(5):
    all_truth = []
    all_preds = []
    output = f"/projappl/project_2014646/shreya/results/RAG_vs_CodeNet_binary_results_{LLMS[0]}_iteration_{iteration}.csv"
    
    with open(output, 'w', newline='') as outfile:
        writer = csv.writer(outfile)
        writer.writerow([
            'PairID', 'File1', 'File2', 'Type-1', 'Type-2', 'Type-3', 'Type-4',
            'PredictedType', 'PredictedSimilar', 'GroundTruthSimilar', 'ModelName'
        ])
        
        for idx, row in pairs_df.head(1000).iterrows():
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
                print(f"Processing pair {pair_id} with {model_name}")
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
        prec = precision_score(all_truth, all_preds, zero_division=0)
        rec = recall_score(all_truth, all_preds, zero_division=0)
        f1 = f1_score(all_truth, all_preds, zero_division=0)
        mse = mean_squared_error(all_truth, all_preds)
        
        metrics_file = f'/projappl/project_2014646/shreya/results/metrics_{LLMS[0]}_iteration_{iteration}.txt'
        with open(metrics_file, 'w') as f:
            print(f"Iteration {iteration} Results:", file=f)
            print(f"Accuracy: {acc:.2f}, Precision: {prec:.2f}, Recall: {rec:.2f}, F1-Score: {f1:.2f}, MSE: {mse:.2f}\n", file=f)
            print(classification_report(all_truth, all_preds), file=f)
        
        print(f"Iteration {iteration} - Accuracy: {acc:.2f}, F1: {f1:.2f}")
    else:
        print(f"Iteration {iteration} - No valid predictions generated")
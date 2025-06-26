import os
import csv
import pandas as pd
import lmstudio as lms
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score
from sklearn.metrics import classification_report

# --- CONFIGURATION ---
DATA_DIR = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/Project_CodeNet_experimentation_dataset/data"
PAIRS_CSV = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/Project_CodeNet_experimentation_dataset/pairs.csv"
GROUND_TRUTH_CSV = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/Project_CodeNet_experimentation_dataset/ground_truth.csv"

LLMS = [
    "mistralai/codestral-22b-v0.1"
]

thresholds = [0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95]

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

# --- ENSEMBLE ASSESSMENT ---
def ensemble_assessment(code1, code2, model_name, thr, n=3):
    predictions = []
    for _ in range(n):
        results, predicted_type, predicted_sim = rag_similarity_assessment(code1, code2, model_name, thr)
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
def determine_similarity(results, min_threshold=0.1):
    # Sort by score, then by type severity
    type_priority = {"Type-4": 4, "Type-3": 3, "Type-2": 2, "Type-1": 1}
    sorted_types = sorted(results.items(), key=lambda x: (x[1], type_priority[x[0]]), reverse=True)
    max_type, max_score = sorted_types[0]
    if max_score >= min_threshold:
        return max_type, 1
    else:
        return "Non-clone", 0


# --- PROMPT V2 WITH STEP-BY-STEP REASONING AND EXAMPLES ---
def rag_similarity_assessment(code1, code2, model_name, thr):
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

    # examples = """
    # Examples:

    # Type-1:
    # Code 1: 'int a=5;'
    # Code 2: 'int a = 5; // set a'

    # Type-2:
    # Code 1: 'int a=5;'
    # Code 2: 'int b=5;'

    # Type-3:
    # Code 1: 'int a=5; print(a);'
    # Code 2: 'int a=5;'

    # Type-4:
    # Code 1: 'for(int i=0;i<5;i++)sum+=i;'
    # Code 2: 'sum = sum_of_first_n(5);'

    # Additional Examples:

    # Type-1:
    # Code 1: 'for i in range(5): print(i)'
    # Code 2: 'for i in range(5): print(i) #loop'

    # Type-2:
    # Code 1: 'def add(x, y): return x + y'
    # Code 2: 'def sum(a, b): return a + b'

    # Type-3:
    # Code 1: 'if x > 0: print("Positive")'
    # Code 2: 'if x >= 0: print("Positive")'

    # Type-4:
    # Code 1: 'result = [x*2 for x in lst]'
    # Code 2: 'result = list(map(lambda x: x*2, lst))'

    # Type-1:
    # Code 1: 'while(count<10) count++;'
    # Code 2: 'while (count < 10) count++; // loop count'

    # Type-2:
    # Code 1: 'int maxVal = 100;'
    # Code 2: 'int max_value = 100;'

    # Type-3:
    # Code 1: 'print("Hello")'
    # Code 2: 'print("Hello World")'

    # Type-4:
    # Code 1: 'def factorial(n): return 1 if n==0 else n*factorial(n-1)'
    # Code 2: 'def fact(n): res=1\n for i in range(1,n+1): res*=i\n return res'

    # Type-1:
    # Code 1: 'x = 10 # set x'
    # Code 2: 'x=10'

    # Type-2:
    # Code 1: 'String name = "Alice";'
    # Code 2: 'String personName = "Alice";'

    # Type-3:
    # Code 1: 'a = 5\nb = 10\nprint(a+b)'
    # Code 2: 'a = 5\nprint(a)'

    # Type-4:
    # Code 1: 'sum = 0\nfor i in range(5): sum += i'
    # Code 2: 'sum = sum(range(5))'

    # Step-by-step reasoning:

    # 1. Are the outputs always identical for all inputs? (Type-4)
    # 2. Are they identical except for whitespace/comments? (Type-1)
    # 3. Are variable/function names changed but structure identical? (Type-2)
    # 4. Are there statement-level edits? (Type-3)

    # Explain your reasoning for each type and provide a confidence score (0-1).

    # Definitions:

    # - Type-1: Output-identical after removing whitespace/comments
    # - Type-2: Identical except for variable/function names (plus Type-1 differences)
    # - Type-3: Similar, but with some statements added/removed/modified (plus Type-2 differences)
    # - Type-4: Syntactically different but functionally identical (same outputs for same inputs)

    # Target Code:
    # {code1}

    # Similar Code:
    # {code2}
    # """

    # prompt = examples.format(code1=code1, code2=code2)

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
    predicted_type, predicted_sim = determine_similarity(results, thr)
    return results, predicted_type, predicted_sim

# --- MAIN WORKFLOW ---
for thr in thresholds:
    all_truth = []
    all_preds = []
    output = f"/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_mistral_{thr}.csv"
    with open(output, 'w', newline='') as outfile:
        writer = csv.writer(outfile)
        writer.writerow([
            'PairID', 'File1', 'File2', 'Type-1', 'Type-2', 'Type-3', 'Type-4',
            'PredictedType', 'PredictedSimilar', 'GroundTruthSimilar', 'ModelName'
        ])
        for idx, row in pairs_df.head(50).iterrows():
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
                results, predicted_type, predicted_sim = ensemble_assessment(code1, code2, model_name, thr, n=3)
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
        with open(f'/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/metricsv2_{thr}.txt', 'w') as f:
            print(f"Accuracy: {acc:.2f}, Precision: {prec:.2f}, Recall: {rec:.2f}, F1-Score: {f1:.2f}\n", file=f)
            print(classification_report(all_truth, all_preds), file=f)

import os
import csv
import pandas as pd
import lmstudio as lms

# --- CONFIGURATION ---
DATA_DIR = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/Project_CodeNet_experimentation_dataset/data"  # Set this to the root of your CodeNet code files
PAIRS_CSV = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/Project_CodeNet_experimentation_dataset/pairs.csv"
GROUND_TRUTH_CSV = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/Project_CodeNet_experimentation_dataset/ground_truth.csv"
OUTPUT_CSV = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results.csv"

LLMS = [
    "mistralai/codestral-22b-v0.1"
    # "deepseek/deepseek-r1-0528-qwen3-8b"
]

# --- LOAD PAIRS AND GROUND TRUTH ---
pairs_df = pd.read_csv(PAIRS_CSV)
ground_truth_df = pd.read_csv(GROUND_TRUTH_CSV)
ground_truth_map = dict(zip(ground_truth_df['pair-id'], ground_truth_df['similar']))

# --- TYPE TO BINARY SIMILARITY ---
def type_to_binary(predicted_type):
    return 1 if predicted_type in ["Type-1", "Type-4"] else 0

# --- LLM RAG ASSESSMENT ---
def rag_similarity_assessment(code1, code2, model_name):
    model = lms.llm(model_name)
    prompt = f'''Given the target code and a similar code file, assess the degree of similarity and provide a score (0-1) with explanation for each Type (Type-1, Type-2, Type-3, and Type-4), 
    given the following definitions:
    Type-1 or identical code fragments represent the same code except for white space, comments, and layout.
    Type-2 or lexical code snippets represent identical clone pairs except for differences in variables or function names with Type-1 clone differences.
    Type-3 or syntactically represent similar code fragments that differ at the statement level. The code fragments differ in some lines with removed or added of some lines in addition to type-2 clone differences.
    Type-4 or semantic code clone represents code snippets that perform the same functionality but the implementation is different. In global they are syntactically dissimilar.
    Target Code:\n{code1}\n\nSimilar Code:\n{code2}\n'''

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
    predicted_type = max(results, key=lambda t: results[t])
    predicted_sim = type_to_binary(predicted_type)
    return results, predicted_type, predicted_sim

# --- MAIN WORKFLOW ---
with open(OUTPUT_CSV, 'w', newline='') as outfile:
    writer = csv.writer(outfile)
    writer.writerow([
        'PairID', 'File1', 'File2', 'Type-1', 'Type-2', 'Type-3', 'Type-4',
        'PredictedType', 'PredictedSimilar', 'GroundTruthSimilar', 'ModelName'
    ])
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
        for model_name in LLMS:
            results, predicted_type, predicted_sim = rag_similarity_assessment(code1, code2, model_name)
            writer.writerow([
                pair_id, row['file1'], row['file2'],
                results['Type-1'], results['Type-2'], results['Type-3'], results['Type-4'],
                predicted_type, predicted_sim, ground_truth_sim, model_name
            ])

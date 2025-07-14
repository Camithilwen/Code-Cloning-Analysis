import pandas as pd
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, classification_report
import os
import csv
from sentence_transformers import SentenceTransformer
from sklearn.metrics.pairwise import cosine_similarity

os.environ['HF_HOME'] = '/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/hf-cache'
os.environ['TRANSFORMERS_CACHE'] = '/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/hf-cache'
os.environ['HF_DATASETS_CACHE'] = '/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/hf-cache'

# look at 638 entries and record how well it does on the dataset
# -- CONFIGURATION --
DATA_DIR = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/Project_CodeNet_experimentation_dataset/data"
PAIRS_CSV = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/Project_CodeNet_experimentation_dataset/pairs.csv"
GROUND_TRUTH_CSV = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/Project_CodeNet_experimentation_dataset/ground_truth.csv"
OUTPUT_CSV = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/naive-comparison/NAIVE_vs_CodeNet_binary_results_all.csv"

# -- EMBEDDING PAIRS --
# --- LOAD PAIRS AND GROUND TRUTH ---
pairs_df = pd.read_csv(PAIRS_CSV)
ground_truth_df = pd.read_csv(GROUND_TRUTH_CSV)
ground_truth_map = dict(zip(ground_truth_df['pair-id'], ground_truth_df['similar']))
model = SentenceTransformer("jinaai/jina-embeddings-v2-base-code", trust_remote_code=True)
all_truth = []
all_preds = []

def get_similarity(code1, code2):
    sentences = [
        code1, code2
    ]
    embedding1 = model.encode(sentences[0]).reshape(-1, 1)
    embedding2 = model.encode(sentences[1]).reshape(-1, 1)

    # similarities.shape # Determine threshold
    sim_score = model.similarity(embedding1, embedding2)[0][0]

    if sim_score < 0.00031: # thresh det by bonferroni correction
        return 0
    else:
        return 1


def truncate_code(code, max_lines=50):
    lines = code.splitlines()
    return '\n'.join(lines[:max_lines]) if len(lines) > max_lines else code

with open(OUTPUT_CSV, 'a', newline='') as outfile:
    writer = csv.writer(outfile)
    # writer.writerow([
    #     'PairID', 'File1', 'File2', 
    #     'PredictedSimilar', 'GroundTruthSimilar',
    # ])
    for idx, row in pairs_df.iloc[1001:].iterrows():
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
        predicted_sim = get_similarity(code1, code2)
        writer.writerow([
            pair_id, row['file1'], row['file2'],
            predicted_sim, ground_truth_sim
        ])
        all_truth.append(ground_truth_sim)
        all_preds.append(predicted_sim)

# --- EVALUATION METRICS ---
if all_truth and all_preds:
    acc = accuracy_score(all_truth, all_preds)
    prec = precision_score(all_truth, all_preds)
    rec = recall_score(all_truth, all_preds)
    f1 = f1_score(all_truth, all_preds)
    with open('/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/naive-comparison/metricsv2.txt', 'w') as f:
        print(f"Accuracy: {acc:.2f}, Precision: {prec:.2f}, Recall: {rec:.2f}, F1-Score: {f1:.2f}\n", file=f)
        print(classification_report(all_truth, all_preds), file=f)
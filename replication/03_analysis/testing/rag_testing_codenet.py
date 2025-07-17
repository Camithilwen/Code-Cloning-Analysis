import numpy as np
from pymilvus import Collection, MilvusClient
import lmstudio as lms
import csv
import pandas as pd

# --- CONFIGURATION ---
MAX_TARGET_FILE_ID = 10000
TOP_K = 1
RUN_NUM = 1
DIR_NAME = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing"
DB_PATH = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/dev/data/embeddings3.db"
CLONE_LABELS_CSV = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/Project_CodeNet_experimentation_dataset/ground_truth.csv"
CLONE_PAIRS_CSV = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/Project_CodeNet_experimentation_dataset/pairs.csv"

PAIRS_DF = pd.read_csv(CLONE_PAIRS_CSV)

LLMS = [
    "mistralai/codestral-22b-v0.1",
]

collection_pairs = [["PriA", "FrkA"], ["PriB", "FrkB"], ["PriC", 'FrkC']]

# --- LOAD CLONE LABELS ---
def load_codenet_clone_labels(labels_csv, pairs_csv):
    clone_labels = {}
    with open(pairs_csv, "r") as f:
        reader = csv.DictReader(f)
        for row in reader:
            key = (row["file1"], row["file2"])
            id = row["pair-id"]
            # 'similar' column: 1 for similar, 0 for not similar
            clone_labels[key] = int(PAIRS_DF.loc[(PAIRS_DF['pair-id']==id)].values[0][0] )
    return clone_labels

# --- MILVUS EXTRACTION ---
def get_all_embeddings_from_all_collections(db_path, col_pair):
    try:
        client = MilvusClient(uri=DB_PATH)
        print(f"✓ Connected to Milvus database")
    except Exception as e:
        print(f"✗ Failed to connect to database: {e}")
    all_embeddings = []
    try:
        collection_names = col_pair
        print(f"✓ Loaded collections")
    except Exception as e:
        print(f"✗ Failed to list collections: {e}")
        return []
    for collection_name in collection_names:
        try:
            results = client.query(
                collection_name=collection_name,
                output_fields=["id", "content", "vector"],
                limit=10000
            )
            all_embeddings.extend(
                [(r["id"], r["content"], np.array(r["vector"]), collection_name) for r in results]
            )
        except Exception as e:
            print(f"✗ Failed to query collection {collection_name}: {e}")
    print(f"✓ Loaded {len(all_embeddings)} embeddings from {len(collection_names)} collections.")
    return all_embeddings

def get_code_and_embedding_by_id(all_embeddings, file_id):
    for row in all_embeddings:
        if row[0] == file_id:
            return row[1], row[2], row[3]
    raise ValueError(f"File ID {file_id} not found in any collection.")

# --- SIMILARITY SEARCH ---
def find_top_k_similar(target_embedding, all_embeddings, target_file_id, target_collection, top_k):
    similarities = []
    for file_id, code, emb, collection_name in all_embeddings:
        if file_id == target_file_id and collection_name == target_collection:
            continue
        sim = float(np.dot(target_embedding, emb) / (np.linalg.norm(target_embedding) * np.linalg.norm(emb)))
        similarities.append((sim, file_id, code, collection_name))
    similarities.sort(reverse=True)
    return similarities[:top_k]

# --- TYPE TO BINARY SIMILARITY ---
def type_to_binary(predicted_type):
    return 1 if predicted_type in ["Type-1", "Type-4"] else 0

# --- LLM RAG ASSESSMENT & COMPARISON ---
def rag_similarity_assessment(target_code, similar_codes, model_name, target_fid, target_col, codenet_clone_labels, results_writer):
    model = lms.llm(model_name)
    context = "\n\n".join([f"Similar Code {i+1} (from {col}):\n{code}" for i, (_, _, code, col) in enumerate(similar_codes)])

    prompt = f'''Given the target code and its most similar code files, assess the degree of similarity and provide a score (0-1) with explanation for each Type (Type-1, Type-2, Type-3, and Type-4), 
        given the following definitions:
        Type-1 or identical code fragments represent the same code except for white 
        space, comments, 
        and layout. Type-2 or lexical code snippets represent identical clone pairs 
        except for differences in variables or function names with Type-1 clone 
        differences. Type-3 or syntactically represent similar code fragments 
        that differ at the statement level. The code fragments differ in some 
        lines with removed or added of some lines in addition to type-2 clone 
        differences. Type-4 or semantic code clone represents code snippets that 
        perform the same functionality but the implementation is different. In 
        global they are syntactically dissimilar.
        Target Code:\n{target_code}\n\n{context}\n'''

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

    for i, (sim, file_id, code, col) in enumerate(similar_codes):
        key = (target_fid, file_id)
        ground_truth = codenet_clone_labels.get(key, "Unknown")
        predicted_type = max(results, key=lambda t: results[t])
        predicted_sim = type_to_binary(predicted_type)

        results_writer.writerow([
            target_fid, file_id, results['Type-1'], results['Type-2'], results['Type-3'], results['Type-4'],
            predicted_type, predicted_sim, ground_truth, model_name, target_col, col
        ])

# --- MAIN WORKFLOW ---
def main():
    codenet_clone_labels = load_codenet_clone_labels(CLONE_LABELS_CSV, CLONE_PAIRS_CSV)
    with open(f"{DIR_NAME}/RAG_vs_CodeNet_binary_results.csv", 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow([
            'TargetFileID', 'SimilarFileID', 'Type-1', 'Type-2', 'Type-3', 'Type-4',
            'PredictedType', 'PredictedSimilar', 'GroundTruthSimilar', 'ModelName', 'TargetCollection', 'SimilarCollection'
        ])
        for col_pair in collection_pairs:
            all_embeddings = get_all_embeddings_from_all_collections(DB_PATH, col_pair)
            for target_fid, _, _, target_collection in all_embeddings:
                try:
                    target_code, target_embedding, target_collection = get_code_and_embedding_by_id(all_embeddings, target_fid)
                    top_k_similar = find_top_k_similar(target_embedding, all_embeddings, target_fid, target_collection, TOP_K)
                    for model_name in LLMS:
                        rag_similarity_assessment(
                            target_code, top_k_similar, model_name, target_fid, target_collection,
                            codenet_clone_labels, writer
                        )
                except ValueError as e:
                    print(e)

if __name__ == "__main__":
    main()

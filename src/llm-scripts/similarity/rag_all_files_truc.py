import numpy as np
from pymilvus import connections, Collection, MilvusClient, utility
import lmstudio as lms
import json
import os
import pandas as pd
import csv

# --- CONFIGURATION ---
MAX_TARGET_FILE_ID = 50
TOP_K = 3
RUN_NUM = 1 # increment to avoid rewriting files
DIR_NAME = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/similarity/rag-result-files/TFID∀-PriA"
DB_PATH = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/dev/data/embeddings3.db"
id_index = 0

# with open(f"{DIR_NAME}/RAG_all_v2.csv", 'w', newline='') as file:
#     writer = csv.writer(file)
#     writer.writerow(['FileID', 'Type-1', 'Type-2', 'Type-3', 'Type-4', 'ModelName'])

LLMS = [
    # "mistralai/codestral-22b-v0.1",
    # "deepseek/deepseek-r1-0528-qwen3-8b",
    "starcoder2-15b-instruct-v0.1",
    # "qwen/qwen3-8b"
]

# --- MILVUS EXTRACTION ---
def get_all_embeddings_from_all_collections(db_path):
    try:
        # client = MilvusClient(uri="/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/dev/data/embeddings.db")
        client = MilvusClient(uri=DB_PATH)
        print(f"✓ Connected to Milvus database")
    except Exception as e:
        print(f"✗ Failed to connect to database: {e}")
    all_embeddings = []
    try:
        collection_names = ["PriA", "FrkA"] # client.list_collections()
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
            # Add collection name for traceability
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
            return row[1], row[2], row[3]  # code, embedding, collection_name
    raise ValueError(f"File ID {file_id} not found in any collection.")

# --- SIMILARITY SEARCH ---
def find_top_k_similar(target_embedding, all_embeddings, target_file_id, target_collection, top_k):
    similarities = []
    for file_id, code, emb, collection_name in all_embeddings:
        # Optionally skip same file in same collection
        if file_id == target_file_id and collection_name == target_collection:
            continue
        sim = float(np.dot(target_embedding, emb) / (np.linalg.norm(target_embedding) * np.linalg.norm(emb)))
        similarities.append((sim, file_id, code, collection_name))
    similarities.sort(reverse=True)
    return similarities[:top_k]

# --- LLM RAG ASSESSMENT ---
def rag_similarity_assessment(target_code, similar_codes, model_name, target_fid):
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

    with open(f"{DIR_NAME}/RAG_all_v2.csv", 'a') as f:
        writer = csv.writer(f)
        writer.writerow([target_fid, results['Type-1'], results['Type-2'], results['Type-3'], results['Type-4'], model_name])

# --- MAIN WORKFLOW ---
def main():
    all_embeddings = get_all_embeddings_from_all_collections(DB_PATH)
    for target_fid in range(1, MAX_TARGET_FILE_ID+1):
        try:
            target_code, target_embedding, target_collection = get_code_and_embedding_by_id(all_embeddings, target_fid)
            top_k_similar = find_top_k_similar(target_embedding, all_embeddings, target_fid, target_collection, TOP_K)
            for model_name in LLMS:
                rag_similarity_assessment(target_code, top_k_similar, model_name, target_fid)
        except ValueError as e:
            print(e)

if __name__ == "__main__":
    main()
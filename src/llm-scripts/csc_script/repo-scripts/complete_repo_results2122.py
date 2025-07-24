import numpy as np
from pymilvus import Collection, MilvusClient
import ollama
import csv
import pandas as pd
import os
import json
import time

start = time.time()

# --- CONFIGURATION ---
DONE = ['Micro-demo.db', 'Spring-netflix.db', 'qbike.db', 'Micro-ewolff.db']
FILE_NAMES = ['Google-demo.db', 'paulc4-demo.db', 'Micro-ref.db', 
               'jaeger.db', 'Spring-movie.db', 'Blog.db', 'Lakeside.db', 'Micro-consul.db', 
              'apollo.db', 'Robot-shop.db', 'sitewhere.db', 'E-commerce.db', 'Spring-micro.db', 'Micro-comp.db', 
              'Ftgo-application.db', 'eShop.db', 'Cqrs.db', 'MusicStore.db', 'piggymetrics.db']
MAX_TARGET_FILE_ID = 10000
TOP_K = 1
RUN_NUM = 1
DIR_NAME = "/projappl/project_2014646/shreya/repo_results"
DB_PATH = "/projappl/project_2014646/shreya/DB_Paths"
FILES_MIN = 8
FILES_MAX = 9
FILES = f'{FILE_NAMES[FILES_MIN]}_{FILE_NAMES[FILES_MAX]}'
LLMS = [
    "devstral:24b",
]

collection_pairs = [["fork_M1", "primary_M1"], ["fork_M2", "primary_M2"], ["fork_M3", "primary_M3"]]

# --- MILVUS EXTRACTION ---
def get_all_embeddings_from_all_collections(db_path, col_pair):
    try:
        client = MilvusClient(uri=db_path)  # Use parameter db_path
        print(f"✓ Connected to Milvus database")
    except Exception as e:
        print(f"✗ Failed to connect to database: {e}")
        return []
    all_embeddings = []
    collection_names = col_pair
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
    for sims in similarities:
        if 'pri' in sims[3]:
            return sims
    # return similarities[:top_k]

# --- LLM RAG ASSESSMENT & COMPARISON ---

def determine_similarity(results):
    type_priority = {"Type-4": 4, "Type-3": 3, "Type-2": 2, "Type-1": 1}
    sorted_types = sorted(results.items(), key=lambda x: (x[1], type_priority[x[0]]), reverse=True)
    max_type, max_score = sorted_types[0]
    return max_type
    

def rag_similarity_assessment(target_code, similar_codes, model_name, target_fid, target_col, results_writer, db_name):
    def assess_pair(code1, code2, model_name):
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

Respond ONLY with a JSON object with the following keys: Type-1, Type-2, Type-3, Type-4, each with a confidence score between 0 and 1.
"""

        # Call Ollama to get the response
        result = ollama.generate(
            model=model_name,
            prompt=prompt
        )
        response_text = result['response']
        try:
            results = json.loads(response_text)
        except Exception:
            # Fallback: handle parsing error
            results = {"Type-1": -1, "Type-2": -1, "Type-3": -1, "Type-4": -1}
        return results
    
    results = assess_pair(target_code, similar_codes[2], model_name)
    predicted_type = determine_similarity(results)

    results_writer.writerow([
        target_fid, similar_codes[1], 
        results['Type-1'], results['Type-2'], results['Type-3'], results['Type-4'],
        predicted_type, model_name, target_col, similar_codes[3], db_name
    ])

# --- MAIN WORKFLOW ---
def main():
    # change at 
    with open(f"{DIR_NAME}/milvus_rag_results_{FILES}.csv", 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow([
            'TargetFileID', 'SimilarFileID', 'Type-1', 'Type-2', 'Type-3', 'Type-4',
            'PredictedType', 'ModelName', 'TargetCollection', 'SimilarCollection', 'Database'
        ])
        for db_name in FILE_NAMES[FILES_MIN:FILES_MAX+1]:
            print(f'Analyzing {db_name}...')
            for col_pair in collection_pairs:
                all_embeddings = get_all_embeddings_from_all_collections(f'{DB_PATH}/{db_name}', col_pair)
                for target_fid, _, _, target_collection in all_embeddings:
                    try:
                        target_code, target_embedding, target_collection = get_code_and_embedding_by_id(all_embeddings, target_fid)
                        top_k_similar = find_top_k_similar(target_embedding, all_embeddings, target_fid, target_collection, TOP_K)
                        
                        for model_name in LLMS:
                            rag_similarity_assessment(
                                target_code, top_k_similar, model_name, target_fid, target_collection, writer, db_name
                            )
                    except ValueError as e:
                        print(e)

if __name__ == "__main__":
    main()
    end = time.time()
    print(end - start)

import numpy as np
from pymilvus import MilvusClient
import lmstudio as lms
import csv
import os

# --- CONFIGURATION ---
TOP_K = 1
RUN_NUM = 1
DIR_NAME = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/similarity/rag-result-files/TFID∀-PriB"
DB_PATH = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/dev/data/embeddings3.db"

# with open(f"{DIR_NAME}/RAG_all_colX.csv", 'w', newline='') as file:
#     writer = csv.writer(file)
#     writer.writerow(['FileID', 'Type-1', 'Type-2', 'Type-3', 'Type-4', 'ModelName', 'Collection'])

LLMS = [
    # "mistralai/codestral-22b-v0.1",
    # "deepseek/deepseek-r1-0528-qwen3-8b",
     "starcoder2-15b-instruct-v0.1",
]

collection_pairs = [["PriA", "FrkA"], ["PriB", "FrkB"], ["PriC", 'FrkC']]

# --- MILVUS EXTRACTION ---
def get_collection_embeddings(db_path, collection_name):
    try:
        client = MilvusClient(uri=DB_PATH)
        results = client.query(
            collection_name=collection_name,
            output_fields=["id", "content", "vector"],
            limit=10000
        )
        return [(r["id"], r["content"], np.array(r["vector"]), collection_name) for r in results]
    except Exception as e:
        print(f"✗ Failed to query collection {collection_name}: {e}")
        return []

# --- SIMILARITY SEARCH ---
def find_most_similar(target_embedding, search_embeddings):
    max_sim = -1
    best_match = None
    for emb_tuple in search_embeddings:
        emb = emb_tuple[2]
        sim = float(np.dot(target_embedding, emb) / (np.linalg.norm(target_embedding) * np.linalg.norm(emb)))
        if sim > max_sim:
            max_sim = sim
            best_match = emb_tuple
    return best_match

# --- LLM RAG ASSESSMENT ---
def rag_similarity_assessment(target_code, similar_code, model_name, target_fid, target_col):
    model = lms.llm(model_name)
    context = f"Similar Code (from {similar_code[3]}):\n{similar_code[1]}"

    prompt = f'''Given the target code and its most similar code file, assess the degree of similarity and provide a score (0-1) with explanation for each Type (Type-1, Type-2, Type-3, and Type-4), 
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

    with open(f"{DIR_NAME}/RAG_all_colX.csv", 'a') as f:
        writer = csv.writer(f)
        writer.writerow([target_fid, results['Type-1'], results['Type-2'], results['Type-3'], results['Type-4'], model_name, target_col])

# --- MAIN WORKFLOW ---
def main():
    for pri_col, frk_col in collection_pairs:
        # get embeddings for both collections
        pri_embeddings = get_collection_embeddings(DB_PATH, pri_col)
        frk_embeddings = get_collection_embeddings(DB_PATH, frk_col)
        
        print(f"Processing {frk_col} vs {pri_col}: {len(frk_embeddings)} files in Frk, {len(pri_embeddings)} files in Pri")
        
        # for each file in Frk[X] collection
        for frk_emb in frk_embeddings:
            target_fid = frk_emb[0]
            target_code = frk_emb[1]
            target_embedding = frk_emb[2]
            target_collection = frk_emb[3]
            
            # find most similar in corresponding Pri[X] collection --> relating the fork back to its "base" repo
            similar_pri = find_most_similar(target_embedding, pri_embeddings)
            
            if similar_pri:
                for model_name in LLMS:
                    rag_similarity_assessment(
                        target_code, 
                        similar_pri, 
                        model_name, 
                        target_fid, 
                        target_collection
                    )
            else:
                print(f"No similar found for {target_fid} in {pri_col}")

if __name__ == "__main__":
    main()

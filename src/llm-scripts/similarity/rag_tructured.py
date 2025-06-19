# rag_code_similarity.py
## add in structured queries

import numpy as np
from pymilvus import connections, Collection, MilvusClient
import lmstudio as lms
import json
import os

# --- CONFIGURATION ---
COLLECTION_NAME = "PriA"
TARGET_FILE_ID = 1
TOP_K = 3
RUN_NUM = 1 # increment to avoid rewriting files
DIR_NAME = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/similarity/rag-result-files/TFID1-PriA2"
DB_PATH = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/dev/data/embeddings3.db"

# LLM_MODEL = "bigcode/starcoder2-15b"
LLMS = [
    #    "deepseek/deepseek-r1-0528-qwen3-8b",
        "starcoder2-15b-instruct-v0.1",
    #    "qwen/qwen3-8b"
    #    "mistralai/codestral-22b-v0.1"
        ]

# --- MILVUS EXTRACTION ---
def get_all_embeddings(collection_name):
    # connections.connect("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/dev/data/embeddings.db", host="localhost", port="8080")
    # collection = Collection(collection_name)
    # all entities (for large collections, use pagination)
    try:
        # client = MilvusClient(uri="/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/dev/data/embeddings.db")
        client = MilvusClient(uri=DB_PATH)
        print(f"✓ Connected to Milvus database")
    except Exception as e:
        print(f"✗ Failed to connect to database: {e}")
    results = client.query(collection_name=collection_name, output_fields=["id", "content", "vector"], limit=10000)
    # {'id': ..., 'content': ..., 'vector': [...]}
    return [(r["id"], r["content"], np.array(r["vector"])) for r in results]

def get_code_and_embedding_by_id(all_embeddings, file_id):
    for row in all_embeddings:
        if row[0] == file_id:
            return row[1], row[2]
    raise ValueError(f"File ID {file_id} not found.")

# --- SIMILARITY SEARCH ---
def find_top_k_similar(target_embedding, all_embeddings, target_file_id, top_k):
    similarities = []
    for file_id, code, emb in all_embeddings:
        if file_id == target_file_id:
            continue
        sim = float(np.dot(target_embedding, emb) / (np.linalg.norm(target_embedding) * np.linalg.norm(emb)))
        similarities.append((sim, file_id, code))
    similarities.sort(reverse=True)
    return similarities[:top_k]

# --- LLM RAG ASSESSMENT ---
def rag_similarity_assessment(target_code, similar_codes, model_name):
    # client = Qwen(base_url="http://127.0.0.1:1234", api_key="lm-studio")
    model = lms.llm(model_name)
    ## do the client thing here since model.[...] doesn't work
    context = "\n\n".join([f"Similar Code {i+1}:\n{code}" for i, (_, _, code) in enumerate(similar_codes)])

    messages = [
        {"role": "system", "content": "Given the target code and its most similar "
        "code files, assess the degree of similarity and provide a score (0-1) "
        "with explanation for each Type (Type-1, Type-2, Type-3, and Type-4), "
        "given the following definitions:"
        "Type-1 or identical code fragments represent the same code except for white "
        "space, comments, "
        "and layout. Type-2 or lexical code snippets represent identical clone pairs "
        "except for differences in variables or function names with Type-1 clone "
        "differences. Type-3 or syntactically represent similar code fragments "
        "that differ at the statement level. The code fragments differ in some "
        "lines with removed or added of some lines in addition to type-2 clone"
        "differences. Type-4 or semantic code clone represents code snippets that "
        "perform the same functionality but the implementation is different. In "
        "global they are syntactically dissimilar."},
        {"role": "user", "content": f"Target Code:\n{target_code}\n\n{context}\n"}
    ]

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
            "Type-1": {"type": "integer"},
            "Type-2": {"type": "integer"},
            "Type-3": {"type": "integer"},
            "Type-4": {"type": "integer"},
        },
        "required": ["Type-1", "Type-2", "Type-3", "Type-4"]
    }

    # Get response from AI
    response = model.respond(prompt, response_format=schema)

    # Parse and display the results
    results = response.parsed

    if '/' in model_name:
        try:
            os.mkdir(f"{DIR_NAME}/STR/{model_name.split('/')[0]}")
        except FileExistsError:
            pass
        with open(f"{DIR_NAME}/STR/{model_name}_structured_results_{RUN_NUM}.txt", 'w') as f:
            print(results, file=f)
    else: # it's starcoder
        try:
            os.mkdir(f"{DIR_NAME}/STR/starcoder")
        except FileExistsError:
            pass
        with open(f"{DIR_NAME}/STR/starcoder/{model_name}_structured_results_{RUN_NUM}.txt", 'w') as f:
            print(results, file=f)

# --- MAIN WORKFLOW ---
def main():
    all_embeddings = get_all_embeddings(COLLECTION_NAME)
    target_code, target_embedding = get_code_and_embedding_by_id(all_embeddings, TARGET_FILE_ID)
    top_k_similar = find_top_k_similar(target_embedding, all_embeddings, TARGET_FILE_ID, TOP_K)
    for model_name in LLMS:
        rag_similarity_assessment(target_code, top_k_similar, model_name)
    # print("RAG Similarity Assessment:\n", rag_result)

if __name__ == "__main__":
    main()

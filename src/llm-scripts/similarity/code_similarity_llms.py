import sqlite3
import json
import numpy as np
from vllm import LLM, SamplingParams
from pymilvus import MilvusClient, Collection

# --- CONFIGURATION ---
DB_PATH = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/dev/data/embeddings.db"
TABLE_NAME = "PriA"        # e.g. "PriA", "FrkB"
FILE_IDS = (1, 2)          # the two file IDs to compare (i chose randomly)
OUTPUT_JSON = "similarity_results.json"

LLM_MODELS = [
    "meta-llama/Llama-3-8B-Instruct",
    "mistralai/Mistral-7B-Instruct-v0.2",
    "bigcode/starcoder2-15b"
]

EMBED_MODEL = "intfloat/e5-mistral-7b-instruct"

def get_schema_and_print_rows(db_path, table_name, file_ids):
    conn = sqlite3.connect(db_path)
    conn.text_factory = bytes
    cur = conn.cursor()
    # print schema
    cur.execute(f"PRAGMA table_info('{table_name}');")
    schema = cur.fetchall()
    print("Table schema:")
    for col in schema:
        print(col)
    # print rows for the file IDs
    for file_id in file_ids:
        cur.execute(f"SELECT * FROM {table_name} WHERE id=?", (file_id,))
        row = cur.fetchone()
        print(f"Row for id={file_id}: {row}")
    conn.close()

def get_code_or_embedding_from_db(db_path, table_name, file_ids):
    client = MilvusClient(uri="/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/dev/data/embeddings.db")
    collection = Collection("PriA")
    results = client.query(expr="", output_fields=["id", "content", "vector"])
    # {'id': ..., 'content': ..., 'vector': [...]}
    return [(r["id"], r["content"], np.array(r["vector"])) for r in results]

def get_embeddings(codes, embed_model):
    llm = LLM(model=embed_model, task="embed")
    outputs = llm.embed(codes)
    embeddings = [np.array(output.outputs.embedding) for output in outputs]
    return embeddings

def compute_embedding_similarity(emb1, emb2):
    similarity = float(np.dot(emb1, emb2) / (np.linalg.norm(emb1) * np.linalg.norm(emb2)))
    return similarity

def llm_qualitative_similarity(code1, code2, model_name):
    llm = LLM(model=model_name)
    prompt = (
        "Compare the following two code files for similarity. "
        "Provide a similarity score (0-1) and a brief explanation.\n\n"
        f"Code 1:\n{code1}\n\nCode 2:\n{code2}\n"
    )
    sampling_params = SamplingParams(temperature=0.3, top_p=0.95)
    outputs = llm.generate([prompt], sampling_params)
    return outputs[0].outputs[0].text.strip()

def main():
    try:
        codes, vectors = get_code_or_embedding_from_db(DB_PATH, TABLE_NAME, FILE_IDS)
    except ValueError as e:
        print(e)
        print("\nPrinting schema and rows for debugging:")
        get_schema_and_print_rows(DB_PATH, TABLE_NAME, FILE_IDS)
        return

    results = {}
    if codes:
        # If we have code, generate embeddings at runtime
        emb1, emb2 = get_embeddings([codes[0], codes[1]], EMBED_MODEL)
        results['embedding_similarity'] = compute_embedding_similarity(emb1, emb2)
        llm_results = []
        for model in LLM_MODELS:
            analysis = llm_qualitative_similarity(codes[0], codes[1], model)
            llm_results.append({
                "model": model,
                "analysis": analysis
            })
        results['llm_analyses'] = llm_results
    elif vectors:
        # if we have vectors, just do embedding similarity
        emb1, emb2 = vectors
        results['embedding_similarity'] = compute_embedding_similarity(emb1, emb2)
        results['llm_analyses'] = ["No code available for LLM qualitative analysis."]
    else:
        print("Neither code nor embedding could be extracted for the provided IDs.")
        return

    with open(OUTPUT_JSON, "w") as f:
        json.dump(results, f, indent=2)
    print(f"Results saved to {OUTPUT_JSON}")

if __name__ == "__main__":
    main()

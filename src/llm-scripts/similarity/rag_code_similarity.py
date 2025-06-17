# rag_code_similarity.py

import numpy as np
# from vllm import LLM, SamplingParams
from pymilvus import connections, Collection, MilvusClient
# from huggingface_hub import login
import lmstudio as lms

# login(token = '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')

# --- CONFIGURATION ---
COLLECTION_NAME = "PriA"  # PriA
TARGET_FILE_ID = 1        # file to compare
TOP_K = 3                 # # of similar files to retrieve

# LLM_MODEL = "bigcode/starcoder2-15b"

# --- MILVUS EXTRACTION ---
def get_all_embeddings(collection_name):
    # connections.connect("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/dev/data/embeddings.db", host="localhost", port="8080")
    # collection = Collection(collection_name)
    # all entities (for large collections, use pagination)
    try:
        client = MilvusClient(uri="/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/dev/data/embeddings.db")
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
    # llm = LLM(model=model_name)

    model = lms.llm("deepseek/deepseek-r1-0528-qwen3-8b")

    context = "\n\n".join([f"Similar Code {i+1}:\n{code}" for i, (_, _, code) in enumerate(similar_codes)])
    prompt = (
        "Given the target code and its most similar code files, "
        "assess the degree of similarity and provide a score (0-1) with explanation.\n\n"
        f"Target Code:\n{target_code}\n\n{context}\n"
    )
    # sampling_params = SamplingParams(temperature=0.3, top_p=0.95)
    result = model.respond(prompt)

    return result

# --- MAIN WORKFLOW ---
def main():
    all_embeddings = get_all_embeddings(COLLECTION_NAME)
    target_code, target_embedding = get_code_and_embedding_by_id(all_embeddings, TARGET_FILE_ID)
    top_k_similar = find_top_k_similar(target_embedding, all_embeddings, TARGET_FILE_ID, TOP_K)
    rag_result = rag_similarity_assessment(target_code, top_k_similar, "deepseek/deepseek-r1-0528-qwen3-8b")
    print("RAG Similarity Assessment:\n", rag_result)

if __name__ == "__main__":
    main()

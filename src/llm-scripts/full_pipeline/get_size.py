import numpy as np
from pymilvus import Collection, MilvusClient

# --- CONFIGURATION ---
MAX_TARGET_FILE_ID = 300
TOP_K = 1
RUN_NUM = 1
DIR_NAME = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/full_pipeline"
DB_PATH = "/Users/shreyanakum/Documents/NSF@Oulu/EmbeddingResults"

LLMS = [
    "mistralai/codestral-22b-v0.1",
]

collection_pairs = [["fork_M3", "primary_M3"]]

db_path  = f'/Users/shreyanakum/Documents/NSF@Oulu/EmbeddingResults/apollo.db'

try:
    client = MilvusClient(uri=db_path)
    print(f"✓ Connected to Milvus database")
except Exception as e:
    print(f"✗ Failed to connect to database: {e}")
all_embeddings = []
collection_names = collection_pairs[0]
for collection_name in collection_names:
    try:
        results = client.query(
            collection_name=collection_name,
            output_fields=["id", "content", "vector"],
            limit=5000
        )
        print(results)
    except Exception as e:
        print(f"✗ Failed to query collection {collection_name}: {e}")
print(f"✓ Loaded {len(all_embeddings)} embeddings from {len(collection_names)} collections.")
# /// script
# dependencies = [
#    "pymilvus",
# ]
# ///
from pymilvus import MilvusClient

client = MilvusClient(uri="./data/embeddings.db")
query = client.get(collection_name="PriA", ids=[0, 1, 2])
print(query)

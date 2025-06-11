# /// script
# dependencies = [
#   "GitPython",
#    "embed",
#    "torch",
#    "transformers",
#    "peft",
#    "pymilvus",
#    "numpy",
# ]
# ///
#
# storing version requirements for reference
# !pip install GitPython
# !pip install embed
# !pip install torch
# !pip install transformers==4.46.0
# !pip install peft==0.10.0
# !pip install --upgrade pymilvus
# !pip install numpy==2.0.0
# !curl -LsSf https://astral.sh/uv/install.sh | sh

#Imports
from embed import BatchedInference
from concurrent.futures import Future

#huggingface authentication
import os
from huggingface_hub import login

login(os.getenv(HF_TOKEN))

#Define custom embedding function
register = BatchedInference(
        model_id=[
            "jinaai/jina-embeddings-v2-base-code",
            #"voyageai/voyage-code-3", #not open source--requires separate api key
            "Salesforce/codet5p-110m-embedding",
            "codesage/codesage-large-v2"
        ],
        engine="torch",
        device="cuda",
    )

#Milvus setup
from pymilvus import MilvusClient
milvus_client = MilvusClient(uri="./milvus_demo.db")

#Define collection names and drop if present
collections = ["PriA", "PriB", "PriC", "FrkA", "FrkB", "FrkC"]
for idx in collections:
    if milvus_client.has_collection(idx):
        milvus_client.drop_collection(idx)

#Create new collections
for idx in collections:
    milvus_client.create_collection(
        collection_name=idx,
        metric_type="COSINE",
        consistency_level="Strong",
    )

#Define loading function for repository data
#aiming to successfully store embeddings at first. But want to figure out how to
#store the relevant file contents for each file as metadata on the vector as well, so it can be used in visualization

def load(dir, db, model):
    import os
    for root, dirs, files in os.walk(dir):
        for dir in dirs:
            load(dir, db, model)
        for file in files:
            future: "Future" = register.embed(
                sentences=file, model_id=model
            )
            milvus_client.insert(collection_name=db, data=future.result())

#Pull down repositories
from git import Repo

#embed repositories
primary = Repo.clone_from({"https://github.com/cowsay-org/cowsay"}, "./data/primary")
fork = Repo.clone_from({"https://github.com/cowsay-org/homebrew-cowsay"}, "./data/fork")

load("./data/primary", "PriA", "jina-embeddings-v2-base-code")

register.stop()

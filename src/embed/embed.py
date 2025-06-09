# ---
# jupyter:
#   jupytext:
#     formats: ipynb,py:percent
#     text_representation:
#       extension: .py
#       format_name: percent
#       format_version: '1.3'
#       jupytext_version: 1.17.1
#   kernelspec:
#     display_name: Python 3
#     name: python3
# ---

# %%

#System installs
!pip install GitPython
!pip install embed
!pip install torch
!pip install transformers
!pip install --upgrade pymilvus

# %%
#Imports
from embed import BatchedInference
from concurrent.futures import Future


#Define custom embedding function
    register = BatchedInference(
        model_id=[
            "jina-embeddings-v2-base-code",
            "voyage-code-3",
            "codesage-large-v2"
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
/*aiming to successfully store embeddings at first. But want to figure out how to
store the relevant file contents for each file as metadata on the vector as well, so it can be used in visualization
*/
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

#Embed repositories
primary = Repo.clone_from({repo_url}, ./data/primary)
fork = Repo.clone_from({repo_url}, ./data/fork)

load("./data/primary", "PriA", "jina-embeddings-v2-base-code")

# %%
#Destroy local storage
!rm -rf ./repo

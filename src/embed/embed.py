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

# %% id="CU0kDis-Rs3I" outputId="85b52138-ee07-46b0-9d79-7316193e3d30" colab={"base_uri": "https://localhost:8080/", "height": 1000}
#System installs
# !pip install GitPython
# !pip install embed
# !pip install torch
# !pip install transformers==4.46.0
# !pip install peft==0.10.0
# !pip install --upgrade pymilvus
# !pip install numpy==2.0.0


# %% id="bM0PSGoFanJQ" outputId="aac9ccaf-41ac-4b1c-c473-c4ed012e23e3" colab={"base_uri": "https://localhost:8080/"}
# !huggingface-cli login

# %% id="Rg2H0ysvlINy"

# %% id="091b9480" outputId="b65b173f-fe17-4fc4-a200-19469f3fc339" colab={"base_uri": "https://localhost:8080/", "height": 1000}
#Imports
from embed import BatchedInference
from concurrent.futures import Future


# #!export INFINITY_DISABLE_OPTIMUM="TRUE"
# #!export INFINITY_DISABLE_COMPILE="TRUE"
# !export INFINITY_BETTERTRANSFORMER="no-bettertransformer"


#Define custom embedding function
register = BatchedInference(
        model_id=[
            "jinaai/jina-embeddings-v2-base-code",
            "voyageai/voyage-code-3",
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



# %% id="6z2q8uP7RuyA"
# !rm -rf ./repo

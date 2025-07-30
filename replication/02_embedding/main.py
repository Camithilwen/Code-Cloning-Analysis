# /// script
# dependencies = [
#   "GitPython",
#   "torch",
#   "transformers>=4.21.0",
#   "sentence-transformers",
#   "pymilvus",
#   "numpy",
#   "einops",
# ]
# ///

import os
import gc
import time
import torch
import numpy as np
from pathlib import Path
from sentence_transformers import SentenceTransformer
from git import Repo
import shutil
from pymilvus import MilvusClient
from huggingface_hub import login
import warnings
warnings.filterwarnings('ignore')

## @var Environment Variable HF_TOKEN
#  Huggingface authentication
login(token=os.getenv("HF_TOKEN"))

## @var dictionary repos
#  Global repository dictionary, initialized as empty.
repos = {}

class EmbeddingModelManager:
    """!
    Embedding Model Management Class

    Defines, loads, manages, and cleans up the repository embedding process.
    """

    def __init__(self):
        """!Defines embedding models and configures CUDA if a compatible GPU is present.
        CPU will be used in lieu of an available GPU.

        @param self Object pointer
        @param self.model_configs Contains embedding model configuration in JSON format.
        @param dimension Final size of vector embeddings.
        @param id Locally defined short ID for each model.
        @oaram trust_remote_code Boolean Required for the huggingface API to retrieve models with remotely defined code.
        @param max_seq_length Sequencing variable used during data chunking.
        @param self.current_model SentenceTransformer object containing an embedding model. Initialized to None.
        @param self.current_model_name String holding the model name.
        @oaram self.device cuda OR cpu"""
        self.model_configs = {
            "jinaai/jina-embeddings-v2-base-code": {
                "dimension": 768,
                "id": "jina",
                "trust_remote_code": False,
                "max_seq_length": 512
            },
            "nomic-ai/CodeRankEmbed": {
                "dimension": 256,
                "id": "sfr2br",
                "trust_remote_code": True,
                "max_seq_length": 256
            },
            "codesage/codesage-large-v2": {
                "dimension": 1024,
                "id": "codesage",
                "trust_remote_code": True,
                "max_seq_length": 512
            }
        }


        self.current_model = None
        self.current_model_name = None
        self.device = "cuda" if torch.cuda.is_available() else "cpu"

        if torch.cuda.is_available():
            torch.cuda.set_per_process_memory_fraction(0.85)  # Reserve 15% for system
            os.environ['PYTORCH_CUDA_ALLOC_CONF'] = 'expandable_segments:True'

        print(f"Using device: {self.device}")
        if self.device == "cuda":
            print(f"GPU Memory: {torch.cuda.get_device_properties(0).total_memory / 1e9:.1f} GB")

    def aggressive_cleanup(self):
        """! Performs aggressive interpreter and torch memory cleanup between model loads.
        """
        if self.current_model is not None:
            del self.current_model
            self.current_model = None
            self.current_model_name = None

        # Aggressive cleanup
        gc.collect()
        if torch.cuda.is_available():
            torch.cuda.empty_cache()
            torch.cuda.synchronize()

        # Brief pause to ensure cleanup
        time.sleep(1)

    def load_model(self, model_name):
        """!
        Loads model and verifies embedding dimensions.
        @return An embedding model as a SentenceTransformer object.
        """
        if self.current_model_name == model_name and self.current_model is not None:
            return self.current_model

        ## Aggressive cleanup before loading new model
        self.aggressive_cleanup()

        print(f"Loading model: {model_name}")
        config = self.model_configs[model_name]

        try:
            ## Load with specific configurations for each model
            model_kwargs = {
                'device': self.device,
                'trust_remote_code': config['trust_remote_code']
            }

            model = SentenceTransformer(model_name, **model_kwargs)

            ## Set maximum sequence length to prevent memory overflow
            if hasattr(model, 'max_seq_length'):
                model.max_seq_length = config['max_seq_length']

            ## Test with minimal sample to verify dimensions
            test_embedding = model.encode(["test"], show_progress_bar=False)
            actual_dim = len(test_embedding[0])

            ## Update dimension in config
            self.model_configs[model_name]["dimension"] = actual_dim
            print(f"Model {model_name} loaded successfully. Dimension: {actual_dim}")

            self.current_model = model
            self.current_model_name = model_name

            return model

        except Exception as e:
            print(f"Error loading model {model_name}: {e}")
            self.aggressive_cleanup()
            return None

    def chunk_text(self, text, max_length=500):
        """!
        Chunks long text files to prevent memory overflow while preserving content.
        @return Overlapping chunks to maintain context.
        """
        if len(text) <= max_length:
            return [text]

        chunks = []
        ## 50 character overlap to maintain context
        overlap = 50

        for i in range(0, len(text), max_length - overlap):
            chunk = text[i:i + max_length]
            ## Only adds non-empty chunks
            if chunk.strip():
                chunks.append(chunk)

        return chunks

    def embed_texts(self, texts, model_name, batch_size=8):
        """!
        Generates embeddings with aggressive memory management and chunking.
        Small batch sizes intended for use with a P100 GPU through Kaggle.
        @return Lists containing complete embeddings and raw text metadata.
        """
        model = self.load_model(model_name)
        if model is None:
            return None

        try:
            ## Total list of embeddings
            all_embeddings = []

            ## List of raw text metadata
            processed_texts = []

            ## Process and chunk texts first
            for text in texts:
                chunks = self.chunk_text(text)
                processed_texts.extend(chunks)

            print(f"Processing {len(processed_texts)} text chunks (from {len(texts)} original files)")

            ## Process in very small batches for P100
            for i in range(0, len(processed_texts), batch_size):
                batch = processed_texts[i:i + batch_size]

                try:
                    batch_embeddings = model.encode(
                        batch,
                        convert_to_numpy=True,
                        show_progress_bar=False,
                        ## Smaller internal batches prevent memory overrun
                        batch_size=min(4, len(batch))
                    )
                    all_embeddings.extend(batch_embeddings)

                    ## Memory cleanup between batches
                    if i % (batch_size * 4) == 0:
                        gc.collect()
                        if torch.cuda.is_available():
                            torch.cuda.empty_cache()

                    if i % (batch_size * 2) == 0:
                        print(f"Processed {i + len(batch)}/{len(processed_texts)} chunks")

                except Exception as e:
                    print(f"Error in batch {i}: {e}")
                    ## Skip this batch but continue processing
                    continue

            return all_embeddings, processed_texts

        except Exception as e:
            print(f"Error generating embeddings: {e}")
            return None, None

    def get_dimension(self, model_name):
        """! Gets the embedding dimension for a specific model."""
        return self.model_configs.get(model_name, {}).get("dimension", 768)

    def cleanup(self):
        """! Cleans up loaded models and frees GPU memory."""
        self.aggressive_cleanup()
        print("Model cleanup completed.")

class RepositoryEmbedder:
    """!
    Repository processor class with chunk-aware storage and metadata preservation.
    Handles repository pairs as separate Milvus instances.
    @param self Object pointer.
    @param self.repos clone of the global repository list.
    @param self.code_extensions A set of 30 common file extensions to microservices projects.
    @param self.models A list of github URLs for the embedding models in use.
    @param model_manager an EmbeddingModelManager instance.
    """

    def __init__(self, model_manager):
        self.model_manager = model_manager
        self.repos = repos

        # File extension store
        self.code_extensions = {
            '.py', '.js', '.java', '.cpp', '.c', '.h', '.cs', '.php',
            '.rb', '.go', '.rs', '.swift', '.kt', '.ts', '.jsx', '.tsx',
            '.md', '.txt', '.csv', '.json', '.xml', '.yml', '.yaml',
            '.sql', '.sh', '.bat', '.html', '.css', '.scss', '.less'
        }

        # Model configurations
        self.models = [
            "jinaai/jina-embeddings-v2-base-code",
            "nomic-ai/CodeRankEmbed",
            "codesage/codesage-large-v2"
        ]

    def group_repositories_into_pairs(self):
        """!
        Group repositories into primary-fork pairs based on naming convention.
        @return A list of tuples: (pair_name, primary_repo, fork_repo)
        """
        pairs = []
        processed = set()

        for repo_name in self.repos.keys():
            if repo_name in processed:
                continue

            if repo_name.endswith('-primary'):
                ## Looks for corresponding fork
                base_name = repo_name[:-8]
                fork_name = f"{base_name}-fork"

                if fork_name in self.repos:
                    pairs.append((base_name, repo_name, fork_name))
                    processed.add(repo_name)
                    processed.add(fork_name)
                    print(f"Found pair: {base_name} -> {repo_name} + {fork_name}")
                else:
                    print(f"Warning: No fork found for {repo_name}")

            elif repo_name.endswith('-fork'):
                ## Looks for corresponding primary
                base_name = repo_name[:-5]
                primary_name = f"{base_name}-primary"

                if primary_name in self.repos and primary_name not in processed:
                    pairs.append((base_name, primary_name, repo_name))
                    processed.add(repo_name)
                    processed.add(primary_name)
                    print(f"Found pair: {base_name} -> {primary_name} + {repo_name}")
                elif primary_name not in self.repos:
                    print(f"Warning: No primary found for {repo_name}")

           # if len(base_name) > 36:
            #    base_name = base_name[:-(len(base_name) - 36)]

        print(f"Created {len(pairs)} repository pairs")
        return pairs

    def create_milvus_instance(self, pair_name):
        """! Creates a new Milvus instance for a repository pair.
        @param the name of a repo pair as a string.
        @return A MilvusClient object."""
        db_path = f"./{pair_name}.db"
        return MilvusClient(uri=db_path)

    def setup_collections_for_pair(self, milvus_client, pair_name, primary_repo, fork_repo):
        """!
        Sets up 6 collections for a repository pair (2 repos × 3 models).
        @param milvus_client A MilvusClient object.
        @param pair_name The name of a repo pair as a string.
        @param primary_repo The name of the primary repository as a string.
        @param fork_repo The name of the fork repository as a string.
        @return The set of collection names"""
        collections = {}

        for i, model_name in enumerate(self.models, 1):
            ## Collections for primary repository
            primary_collection = f"primary_M{i}"
            collections[primary_collection] = (primary_repo, model_name)

            ## Collections for fork repository
            fork_collection = f"fork_M{i}"
            collections[fork_collection] = (fork_repo, model_name)

        print(f"Setting up {len(collections)} collections for pair {pair_name}...")

        for collection_name, (repo_name, model_name) in collections.items():
            ## Drops existing collection if present
            if milvus_client.has_collection(collection_name):
                milvus_client.drop_collection(collection_name)
                print(f"Dropped existing collection: {collection_name}")

            ## Gets model dimension
            dimension = self.model_manager.get_dimension(model_name)

            ## Creates new collection
            milvus_client.create_collection(
                collection_name=collection_name,
                dimension=dimension,
                metric_type="COSINE",
                consistency_level="Strong",
            )
            print(f"Created collection {collection_name} with dimension {dimension}")

        return collections

    def extract_code_files(self, dir_path):
        """! Extracts code files for embedding and preservation of plain text as metadata.
        @param dir_path A directory path as a string
        @return A list of all files with extensions defined in self.code_extensions"""
        dir_path = Path(dir_path)
        code_files = []

        for file_path in dir_path.rglob('*'):
            if file_path.is_file() and file_path.suffix.lower() in self.code_extensions:
                try:
                    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                        content = f.read().strip()

                    if content:  ## Skips empty files
                        relative_path = str(file_path.relative_to(dir_path))
                        file_stats = file_path.stat()

                        code_files.append({
                            'relative_path': relative_path,
                            'filename': file_path.name,
                            'content': content,
                            'size': file_stats.st_size,
                            'extension': file_path.suffix.lower()
                        })

                except Exception as e:
                    print(f"Error reading {file_path}: {e}")
                    continue

        print(f"Found {len(code_files)} code files in {dir_path}")
        return code_files

    def process_repository(self, repo_path, collection_name, model_name, milvus_client):
        """!
        Embeds a repository with chunk-aware storage and complete metadata preservation.
        @param repo_path A directory path as a string.
        @param collection_name A Milvus database collection name as a string.
        @param model_name An embedding model's name as a string
        @param milvus_client A milvus_client instance's name as a string.
        """
        print(f"Processing repository {repo_path} with model {model_name} -> {collection_name}")

        ## Extracts code files
        code_files = self.extract_code_files(repo_path)
        if not code_files:
            print(f"No code files found in {repo_path}")
            return

        ## Prepares texts for embedding
        texts = [file_data['content'] for file_data in code_files]

        ## Generates embeddings with chunking
        print(f"Generating embeddings for {len(texts)} files...")
        result = self.model_manager.embed_texts(texts, model_name)

        if result is None or result[0] is None:
            print(f"Failed to generate embeddings for {collection_name}")
            return

        embeddings, processed_chunks = result

        ## Maps chunks back to original files
        data_to_insert = []
        chunk_idx = 0

        for file_data in code_files:
            file_chunks = self.model_manager.chunk_text(file_data['content'])

            for chunk_num, chunk_content in enumerate(file_chunks):
                if chunk_idx < len(embeddings):
                    data_to_insert.append({
                        "id": chunk_idx,
                        "vector": embeddings[chunk_idx].tolist(),
                        "file_path": file_data['relative_path'],
                        "file_name": file_data['filename'],
                        "file_extension": file_data['extension'],
                        "file_size": file_data['size'],
                        "chunk_index": chunk_num,
                        "total_chunks": len(file_chunks),
                        "content": chunk_content,
                        "is_complete_file": len(file_chunks) == 1
                    })
                    chunk_idx += 1

        ## Inserts data into Milvus in small batches for stability
        batch_size = 50
        for i in range(0, len(data_to_insert), batch_size):
            batch = data_to_insert[i:i + batch_size]
            try:
                milvus_client.insert(collection_name=collection_name, data=batch)
                print(f"Inserted batch {i//batch_size + 1}/{(len(data_to_insert)-1)//batch_size + 1}")
            except Exception as e:
                print(f"Error inserting batch: {e}")
                continue

        print(f"Successfully processed {len(code_files)} files into {len(data_to_insert)} chunks for {collection_name}")

def clone_repositories():
    """! Clones repositories and handles errors, if present."""
    print("Setting up repositories...")

    ## Creates data directory
    os.makedirs("./data", exist_ok=True)

    import csv
    data_file = "../01_dataset/repositories.csv"

    with open(data_file, 'r') as data:
        reader = csv.DictReader(data)
        for row in reader:
            result = {}
            result[row['Title']] = row['URL']
            repos.update(result)

    for repo_name, repo_url in repos.items():
        repo_path = f"./repo_store/{repo_name}"

        ## Removes existing directory, if present
        if os.path.exists(repo_path):
            shutil.rmtree(repo_path)
            print(f"Removed existing {repo_name} directory")

        ## Clones repository
        print(f"Cloning {repo_name} repository...")
        try:
            Repo.clone_from(repo_url, repo_path)
            print(f"Successfully cloned {repo_name}")
        except Exception as e:
            print(f"Error cloning {repo_name}: {e}")
            raise

def main():
    """
    Main execution.
    """
    model_manager = None

    try:
        ## Initializes components
        print("Initializing embedding system...")
        model_manager = EmbeddingModelManager()

        ## Clones repositories
        clone_repositories()

        embedder = RepositoryEmbedder(model_manager)

        ## Groups repositories into pairs
        repo_pairs = embedder.group_repositories_into_pairs()

        if not repo_pairs:
            print("No repository pairs found!")
            return

        ## Processes each repository pair with its own Milvus instance
        for pair_name, primary_repo, fork_repo in repo_pairs:
            print(f"\n{'='*80}")
            print(f"Processing repository pair: {pair_name}")
            print(f"Primary: {primary_repo}, Fork: {fork_repo}")
            print(f"{'='*80}")

            milvus_client = embedder.create_milvus_instance(pair_name)

            try:
                ## Sets up collections for this pair
                collections = embedder.setup_collections_for_pair(
                    milvus_client, pair_name, primary_repo, fork_repo
                )

                ## Processes all collections for this pair
                for collection_name, (repo_name, model_name) in collections.items():
                    print(f"\n{'-'*60}")
                    print(f"Processing {collection_name}: {repo_name} + {model_name}")
                    print(f"{'-'*60}")

                    repo_path = f"./repo_store/{repo_name}"

                    try:
                        embedder.process_repository(repo_path, collection_name, model_name, milvus_client)
                    except Exception as e:
                        print(f"Error processing {collection_name}: {e}")
                        continue

                    ## Cleans up between models
                    model_manager.aggressive_cleanup()
                    time.sleep(2)

                print(f"✅ Completed pair {pair_name} - Database: {pair_name}.db")

            except Exception as e:
                print(f"Error processing pair {pair_name}: {e}")
                continue

            finally:
                ## Closes Milvus client for this pair
                if 'milvus_client' in locals():
                    del milvus_client

                ## Performs additional cleanup between pairs
                gc.collect()
                time.sleep(3)

        print(f"\n🎉 All embedding operations completed!")
        print(f"Created {len(repo_pairs)} separate database files")

    except Exception as e:
        print(f"Error during execution: {e}")
        import traceback
        traceback.print_exc()

    finally:
        ## Performs final cleanup
        if model_manager:
            model_manager.cleanup()
        shutil.rmtree("./repo_store")
        print("Script completed.")

if __name__ == "__main__":
    main()

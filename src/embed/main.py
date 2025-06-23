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

# Huggingface authentication
login(token=os.getenv("HF_TOKEN"))

class EmbeddingModelManager:
    """
    Enhanced embedding model manager with aggressive memory management
    and proper error handling for P100 GPU constraints.
    """
    
    def __init__(self):
        # Model configurations with corrected dimensions and trust settings
        self.model_configs = {
            "jinaai/jina-embeddings-v2-base-code": {
                "dimension": 768, 
                "id": "jina",
                "trust_remote_code": False,
                "max_seq_length": 512  # Reduced for memory efficiency
            },
            "nomic-ai/CodeRankEmbed": {
                "dimension": 256, 
                "id": "sfr2br",
                "trust_remote_code": True,  # Required for this model
                "max_seq_length": 256      # Heavily reduced due to 2B parameters
            }, 
            "codesage/codesage-large-v2": {
                "dimension": 1024, 
                "id": "codesage",
                "trust_remote_code": True,
                "max_seq_length": 512
            }
        }
        
        # Fixed: Initialize all required attributes
        self.current_model = None
        self.current_model_name = None
        self.device = "cuda" if torch.cuda.is_available() else "cpu"
        
        # P100-specific optimizations
        if torch.cuda.is_available():
            torch.cuda.set_per_process_memory_fraction(0.85)  # Reserve 15% for system
            os.environ['PYTORCH_CUDA_ALLOC_CONF'] = 'expandable_segments:True'
        
        print(f"Using device: {self.device}")
        if self.device == "cuda":
            print(f"GPU Memory: {torch.cuda.get_device_properties(0).total_memory / 1e9:.1f} GB")
        
    def aggressive_cleanup(self):
        """Perform aggressive memory cleanup between model loads."""
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
        """
        Load model with enhanced memory management and error handling.
        """
        if self.current_model_name == model_name and self.current_model is not None:
            return self.current_model
            
        # Aggressive cleanup before loading new model
        self.aggressive_cleanup()
        
        print(f"Loading model: {model_name}")
        config = self.model_configs[model_name]
        
        try:
            # Load with specific configurations for each model
            model_kwargs = {
                'device': self.device,
                'trust_remote_code': config['trust_remote_code']
            }
            
            # Special handling for problematic models
            if "SFR-Embedding" in model_name:
                # This model requires trust_remote_code and careful memory handling
                model_kwargs['model_kwargs'] = {'torch_dtype': torch.float16}
            
            model = SentenceTransformer(model_name, **model_kwargs)
            
            # Set maximum sequence length to prevent memory overflow
            if hasattr(model, 'max_seq_length'):
                model.max_seq_length = config['max_seq_length']
            
            # Test with minimal sample to verify dimensions
            test_embedding = model.encode(["test"], show_progress_bar=False)
            actual_dim = len(test_embedding[0])
            
            # Update dimension in config
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
        """
        Chunk long text files to prevent memory overflow while preserving content.
        Uses overlapping chunks to maintain context.
        """
        if len(text) <= max_length:
            return [text]
        
        chunks = []
        overlap = 50  # 50 character overlap to maintain context
        
        for i in range(0, len(text), max_length - overlap):
            chunk = text[i:i + max_length]
            if chunk.strip():  # Only add non-empty chunks
                chunks.append(chunk)
        
        return chunks
    
    def embed_texts(self, texts, model_name, batch_size=8):
        """
        Generate embeddings with aggressive memory management and chunking.
        Reduced batch size for P100 compatibility.
        """
        model = self.load_model(model_name)
        if model is None:
            return None
            
        try:
            all_embeddings = []
            processed_texts = []
            
            # Process and chunk texts first
            for text in texts:
                chunks = self.chunk_text(text)
                processed_texts.extend(chunks)
            
            print(f"Processing {len(processed_texts)} text chunks (from {len(texts)} original files)")
            
            # Process in very small batches for P100
            for i in range(0, len(processed_texts), batch_size):
                batch = processed_texts[i:i + batch_size]
                
                try:
                    batch_embeddings = model.encode(
                        batch, 
                        convert_to_numpy=True,
                        show_progress_bar=False,
                        batch_size=min(4, len(batch))  # Even smaller internal batches
                    )
                    all_embeddings.extend(batch_embeddings)
                    
                    # Memory cleanup between batches
                    if i % (batch_size * 4) == 0:
                        gc.collect()
                        if torch.cuda.is_available():
                            torch.cuda.empty_cache()
                    
                    if i % (batch_size * 2) == 0:
                        print(f"Processed {i + len(batch)}/{len(processed_texts)} chunks")
                        
                except Exception as e:
                    print(f"Error in batch {i}: {e}")
                    # Skip this batch but continue processing
                    continue
                
            return all_embeddings, processed_texts
            
        except Exception as e:
            print(f"Error generating embeddings: {e}")
            return None, None
    
    def get_dimension(self, model_name):
        """Get the embedding dimension for a specific model."""
        return self.model_configs.get(model_name, {}).get("dimension", 768)
    
    def cleanup(self):
        """Clean up loaded models and free GPU memory."""
        self.aggressive_cleanup()
        print("Model cleanup completed.")

class RepositoryEmbedder:
    """
    Enhanced repository processor with chunk-aware storage and metadata preservation.
    """
    
    def __init__(self, model_manager, milvus_client):
        self.model_manager = model_manager
        self.milvus_client = milvus_client

        # Expanded code file extensions
        self.code_extensions = {
            '.py', '.js', '.java', '.cpp', '.c', '.h', '.cs', '.php', 
            '.rb', '.go', '.rs', '.swift', '.kt', '.ts', '.jsx', '.tsx', 
            '.md', '.txt', '.csv', '.json', '.xml', '.yml', '.yaml',
            '.sql', '.sh', '.bat', '.html', '.css', '.scss', '.less'
        }
        
        # Collection mappings


        self.collection_mapping = {}
        for i in len(repos):
            for key in repos.keys():
                self.collection_mapping.update([i, (key, repos.get(key))])
       # self.collection_mapping = {
       #     "A": ("java-microservice_primary", "jinaai/jina-embeddings-v2-base-code"),
       #     "B": ("java-microservice_primary", "nomic-ai/CodeRankEmbed"),
       #     "C": ("java-microservice_primary", "codesage/codesage-large-v2"),
       #     "D": ("java-microservice_fork", "jinaai/jina-embeddings-v2-base-code"),
       #     "E": ("java-microservice_fork", "nomic-ai/CodeRankEmbed"),
       #     "F": ("java-microservice_fork", "codesage/codesage-large-v2"),
       #     "G": ("MBSB_primary", "jinaai/jina-embeddings-v2-base-code"),
       #     "H": ("MBSB_primary", "nomic-ai/CodeRankEmbed"),
       #     "I": ("MBSB_primary", "codesage/codesage-large-v2"),
       #     "J": ("MBSB_fork", "jinaai/jina-embeddings-v2-base-code"),
       #     "K": ("MBSB_fork", "nomic-ai/CodeRankEmbed"),
       #     "L": ("MBSB_fork", "codesage/codesage-large-v2"),
       #     "M": ("blog-primary", "jinaai/jina-embeddings-v2-base-code"),
       #     "N": ("blog-primary", "nomic-ai/CodeRankEmbed"),
       #     "O": ("blog-primary", "codesage/codesage-large-v2"),
       #     "P": ("blog-fork", "jinaai/jina-embeddings-v2-base-code"),
       #     "Q": ("blog-fork", "nomic-ai/CodeRankEmbed"),
       #     "R": ("blog-fork", "codesage/codesage-large-v2")
       # }
    
    def setup_collections(self):
        """Setup Milvus collections with enhanced schema for chunk metadata."""
        print("Setting up Milvus collections...")
        
        for collection_name, (repo_type, model_name) in self.collection_mapping.items():
            # Drop existing collection
            if self.milvus_client.has_collection(collection_name):
                self.milvus_client.drop_collection(collection_name)
                print(f"Dropped existing collection: {collection_name}")
            
            # Get model dimension
            dimension = self.model_manager.get_dimension(model_name)
            
            # Create new collection with enhanced schema
            self.milvus_client.create_collection(
                collection_name=collection_name,
                dimension=dimension,
                metric_type="COSINE",
                consistency_level="Strong",
            )
            print(f"Created collection {collection_name} with dimension {dimension}")
    
    def extract_code_files(self, dir_path):
        """Extract code files with enhanced metadata preservation."""
        dir_path = Path(dir_path)
        code_files = []
        
        for file_path in dir_path.rglob('*'):
            if file_path.is_file() and file_path.suffix.lower() in self.code_extensions:
                try:
                    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                        content = f.read().strip()
                    
                    if content:  # Skip empty files
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
    
    def process_repository(self, repo_path, collection_name, model_name):
        """
        Process repository with chunk-aware storage and complete metadata preservation.
        """
        print(f"Processing repository {repo_path} with model {model_name} -> {collection_name}")
        
        # Extract code files
        code_files = self.extract_code_files(repo_path)
        if not code_files:
            print(f"No code files found in {repo_path}")
            return
        
        # Prepare texts for embedding
        texts = [file_data['content'] for file_data in code_files]
        
        # Generate embeddings with chunking
        print(f"Generating embeddings for {len(texts)} files...")
        result = self.model_manager.embed_texts(texts, model_name)
        
        if result is None or result[0] is None:
            print(f"Failed to generate embeddings for {collection_name}")
            return
            
        embeddings, processed_chunks = result
        
        # Map chunks back to original files
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
        
        # Insert into Milvus in small batches
        batch_size = 50  # Smaller batches for stability
        for i in range(0, len(data_to_insert), batch_size):
            batch = data_to_insert[i:i + batch_size]
            try:
                self.milvus_client.insert(collection_name=collection_name, data=batch)
                print(f"Inserted batch {i//batch_size + 1}/{(len(data_to_insert)-1)//batch_size + 1}")
            except Exception as e:
                print(f"Error inserting batch: {e}")
                continue
        
        print(f"Successfully processed {len(code_files)} files into {len(data_to_insert)} chunks for {collection_name}")

def clone_repositories():
    """Clone repositories with error handling."""
    print("Setting up repositories...")
    
    # Create data directory
    os.makedirs("./data", exist_ok=True)

    import csv
    pri_file = "./embed/data/primary-dataset.csv"
    frk_file = "./embed/data/fork-dataset.csv"

    repos = {}
    with open(pri_file, 'r') as data:
        for line in csv.DictReader(["Title", "URL"], data.read()):
            repos.update([line.split(":")])

    with open(frk_file, 'r') as data:
        for line in csv.DictReader(["Title", "URL"], data.read()):
            repos.update([line.split(":")])

   # repos = {
   #     "java-microservice_primary": "https://github.com/apssouza22/java-microservice",
   #     "java-microservice_fork": "https://github.com/M3SOulu/EMSE2025SAR-java-microservice",
   #     "MBSB_primary": "https://github.com/anilallewar/microservices-basics-spring-boot",
   #     "MBSB_fork": "https://github.com/M3SOulu/EMSE2025SAR-microservices-basics-spring-boot",
   #     "blog-primary": "https://github.com/callistaenterprise/blog-microservices",
   #     "blog-fork": "https://github.com/M3SOulu/EMSE2025SAR-blog-microservices"
   # }
    
    for repo_name, repo_url in repos.items():
        repo_path = f"./data/{repo_name}"
        
        # Remove existing directory
        if os.path.exists(repo_path):
            shutil.rmtree(repo_path)
            print(f"Removed existing {repo_name} directory")
        
        # Clone repository
        print(f"Cloning {repo_name} repository...")
        try:
            Repo.clone_from(repo_url, repo_path)
            print(f"Successfully cloned {repo_name}")
        except Exception as e:
            print(f"Error cloning {repo_name}: {e}")
            raise

    self.repos = repos

def main():
    """
    Main execution with enhanced error handling and memory management.
    """
    model_manager = None
    
    try:
        # Initialize components
        print("Initializing embedding system...")
        model_manager = EmbeddingModelManager()
        milvus_client = MilvusClient(uri="./embed/data/embeddings.db")

        # Clone repositories
        clone_repositories()

        embedder = RepositoryEmbedder(model_manager, milvus_client)

        # Setup Milvus collections
        embedder.setup_collections()
        

        # Process all repository-model combinations
        print("Starting embedding process...")
        
        for collection_name, (repo_type, model_name) in embedder.collection_mapping.items():
            print(f"\n{'='*60}")
            print(f"Processing {collection_name}: {repo_type} + {model_name}")
            print(f"{'='*60}")
            
            repo_path = f"./data/{repo_type}"
            
            try:
                embedder.process_repository(repo_path, collection_name, model_name)
            except Exception as e:
                print(f"Error processing {collection_name}: {e}")
                # Continue with next collection
                continue
            
            # Aggressive cleanup between models
            model_manager.aggressive_cleanup()
            time.sleep(3)  # Longer pause between models
        
        print("\nAll embedding operations completed!")
        
    except Exception as e:
        print(f"Error during execution: {e}")
        import traceback
        traceback.print_exc()
        
    finally:
        # Cleanup
        if model_manager:
            model_manager.cleanup()
        shutil.rmtree("./data")
        print("Script completed.")

if __name__ == "__main__":
    main()

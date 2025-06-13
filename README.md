# Code Cloning Analysis

## To-do:

### Embedding generation
- Determine suitable model for slot B, integrate into embedding script, and test with the database checker.
- Automate pipeline, if possible within reasonable time
- Test pipeline against a single microservices repository and fork
- Scale system to batch-process multiple repositories and forks to a single database file

### RAG analysis
- Setup an analysis script in LM studio with three LLMs and a milvus vector database file (we may need to run this through the LM studio service running in a kaggle notebook? or on the csc computer)
- The vllm library should be used to ensure compatability with the csc computer.
- Test queries against a smaller database file for ease of initial prompt engineering
- Determine optimal format and required fields for LLM structured output (with eventual data visualization in mind)
- When ready, integrate analysis into the embedding and database check pipeline

### CSC Mahti
- When ready, present prototype system and schedule larger batch runs through csc.

### Visualization
- Design simple visualization UI to receive and display LLM structured output as it is received or after run.

### Paper
- Begin analysis after enough good data is collected.

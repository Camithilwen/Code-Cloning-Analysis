# Code Cloning Analysis

## To-do:

### Embedding generation
- ~Set up embedding script to process a primary and fork repository into vector space with complete metadata~
- ~Scale script to embed data with multiple code embedding models~
- ~Create script to dynamically check generated databases for completeness and data integrity~
- ~Determine suitable model for slot B, integrate into embedding script, and test with the database checker.~
- ~Automate pipeline, if possible within reasonable time~
- ~Test pipeline against multiple microservices repository and fork~
- ~Scale system to batch-process multiple repositories and forks to a single database file~
- Refactor to ingest dataset of github links (primary / fork) and upload one database artifact per primary/fork pair. **In progress**

### RAG analysis
- ~Setup an analysis script with three LLMs and a milvus vector database file~
- ~Test queries against a smaller database file for ease of initial prompt engineering~
- ~Determine optimal format and required fields for LLM structured output (with eventual data visualization in mind)~
- ~Test RAG on more than one collection and visualize results~
- ~Do complete testing of RAG on all collections, placing results in CSV file~
- ~Create script to output best Type similarity based on average of all LLM outputs & output graph showing all LLMs’ outputs~
- When ready, integrate analysis into the embedding and database check pipeline

### CSC Mahti
- When ready, present prototype system and schedule larger batch runs through csc.

### Visualization
- Design simple visualization UI to receive and display LLM structured output as it is received or after run.

### Paper
- Begin analysis after enough good data is collected.

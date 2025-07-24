#!/bin/bash
#SBATCH --account=project_2014646
#SBATCH --partition=gpusmall
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=10
#SBATCH --mem=130G
#SBATCH --time=1-12:00:00
#SBATCH --gres=gpu:a100:2

OLLAMA_SCRATCH=/scratch/project_2014646/shreya/ollama
export OLLAMA_MODELS=${OLLAMA_SCRATCH}/models

export PATH=/projappl/project_2014646/shreya/bin:$PATH

# Load required modules
module load python-data/3.10

# Set up virtual environment
rm -rf venv
python -m venv venv
source venv/bin/activate
pip install --upgrade pip
pip install ollama pydantic pandas requests pymilvus numpy
python -c "import pymilvus"

# Start Ollama in background
echo "Starting Ollama server..."
mkdir -p ${OLLAMA_SCRATCH}/logs
ollama serve > ${OLLAMA_SCRATCH}/logs/${SLURM_JOB_ID}.log 2>&1 &
OLLAMA_PID=$!
sleep 10  # Wait for server initialization

# Pull model (if not cached)
ollama pull devstral:24b
ollama list
# ollama run deepseek-r1:32b "Why is the sky blue?"
# Run the Python script
echo "Getting repository resutls..."
python complete_repo_results1112.py

# Cleanup
kill $OLLAMA_PID
echo "Job completed. Results saved to output directory."

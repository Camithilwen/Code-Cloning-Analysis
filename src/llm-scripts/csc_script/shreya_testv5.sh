#!/bin/bash
#SBATCH --account=project_2014646
#SBATCH --partition=gpumedium
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=10
#SBATCH --mem=130G
#SBATCH --time=1-01:00:00
#SBATCH --gres=gpu:a100:4

OLLAMA_SCRATCH=/scratch/project_2014646/shreya/ollama
export OLLAMA_MODELS=${OLLAMA_SCRATCH}/models

export PATH=/projappl/project_2014646/shreya/bin:$PATH

# Load required modules
module load python-data/3.10

# Set up virtual environment
if [ ! -d "venv" ]; then
    python -m venv venv
    source venv/bin/activate
    pip install --upgrade pip
    pip install ollama pydantic pandas scikit-learn requests
else
    source venv/bin/activate
fi

# Start Ollama in background
echo "Starting Ollama server..."
mkdir -p ${OLLAMA_SCRATCH}/logs
ollama serve > ${OLLAMA_SCRATCH}/logs/${SLURM_JOB_ID}.log 2>&1 &
OLLAMA_PID=$!
sleep 10  # Wait for server initialization

# Pull model (if not cached)
ollama pull starcoder2:15b
ollama list
# ollama run deepseek-r1:32b "Why is the sky blue?"
# Run the Python script
echo "Starting similarity analysis..."
python working_script5.py

# Cleanup
kill $OLLAMA_PID
echo "Job completed. Results saved to output directory."
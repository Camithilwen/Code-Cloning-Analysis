#!/bin/bash
#SBATCH --account=project_2014646
#SBATCH --partition=gpusmall
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=10
#SBATCH --mem=130G
#SBATCH --time=1-01:00:00
#SBATCH --gres=gpu:a100:2

module load pytorch/2.5
modul load cuda/12.1

export PIP_DEFAULT_TIMEOUT=300
pip install --user --default-timeout=300 --trusted-host pypi.org --trusted-host files.pythonhosted.org future
pip install --user --default-timeout=300 --trusted-host pypi.org --trusted-host files.pythonhosted.org vllm

export VLLM_LOGGING_LEVEL=DEBUG
export HF_HOME=/scratch/project_2014646/shreya/hf-cache

VLLM_LOG=/scratch/project_2014646/shreya/vllm-logs/${SLURM_JOB_ID}.log
SCRIPT_LOG=/scratch/project_2014646/shreya/vllm-logs/SCRIPT_${SLURM_JOB_ID}.log
mkdir -p $(dirname $VLLM_LOG)
mkdir -p $(dirname $SCRIPT_LOG)

# Load and run the model:
vllm serve "microsoft/phi-4"

# Call the server using curl:
curl -X POST "http://localhost:8000/v1/chat/completions" \
	-H "Content-Type: application/json" \
	--data '{
		"model": "microsoft/phi-4",
		"messages": [
			{
				"role": "user",
				"content": "What is the capital of France?"
			}
		]
	}'

python vllm_5.py > $SCRIPT_LOG 2>&1

echo "Job completed successfully"
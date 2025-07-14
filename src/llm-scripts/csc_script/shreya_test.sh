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
export HF_KEY=""
export HF_HOME=/users/muhammab/project_2014646/shreya/hf-cache

VLLM_LOG=/scratch/project_2014646/shreya/vllm-logs/${SLURM_JOB_ID}.log
SCRIPT_LOG=/scratch/project_2014646/shreya/vllm-logs/SCRIPT_${SLURM_JOB_ID}.log
mkdir -p $(dirname $VLLM_LOG)
mkdir -p $(dirname $SCRIPT_LOG)

MODEL="meta-llama/Llama-3.1-8B-Instruct"

python -m vllm.entrypoints.openai.api_server \
    --device=auto \
    --model=$MODEL \
    --served-model-name=$MODEL \
    --tensor-parallel-size=2 \
    --max-model-len=32768 \
    --gpu-memory-utilization=0.98 \
    --enforce-eager > $VLLM_LOG 2>&1 &

VLLM_PID=$!
trap "kill $VLLM_PID" EXIT
echo "Starting vLLM process $VLLM_PID - logs at $VLLM_LOG"

# Wait for vLLM server to become ready (up to 10 minutes)
timeout=600
interval=10
elapsed=0
while ! curl -s localhost:8000/v1/models | grep -q '"id":'; do
    if ! ps -p $VLLM_PID > /dev/null; then
        echo "vLLM server crashed. Check logs: $VLLM_LOG"
        exit 1
    fi
    sleep $interval
    elapsed=$((elapsed + interval))
    if [ $elapsed -ge $timeout ]; then
        echo "Timeout waiting for vLLM server to start."
        exit 1
    fi
done

echo "vLLM server is ready. Running script..."
python working_script.py > $SCRIPT_LOG 2>&1

echo "Job completed successfully"
#!/bin/bash
#SBATCH --account=project_xxxxxxx
#SBATCH --partition=gpusmall
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=10
#SBATCH --mem=130G
#SBATCH --time=1-01:00:00
#SBATCH --gres=gres/gpu:a100:2


module load pytorch/2.5

# Where to store the huge models
# For example Deepseek-R1-Distill-Llama-70B requires 132GB
export HF_HOME=/scratch/project_2014097/rouyu/hf-cache

# Where to store the vLLM server log
VLLM_LOG=/scratch/project_2014097/ruoyu/vllm-logs/${SLURM_JOB_ID}.log
mkdir -p $(dirname $VLLM_LOG)

#Script Logs
SCRIPT_LOG=/scratch/project_2014097/ruoyu/vllm-logs/SCRIPT_${SLURM_JOB_ID}.log
mkdir -p $(dirname $SCRIPT_LOG)

MODEL="AIDC-AI/Marco-o1"

python -m vllm.entrypoints.openai.api_server \
       --model=$MODEL \
       --served-model-name=$MODEL \
       --tensor-parallel-size 2 \
       --max-model-len 32768 \
       --gpu_memory_utilization 0.98 \
       --enforce-eager > $VLLM_LOG &



VLLM_PID=$!

echo "Starting vLLM process $VLLM_PID - logs go to $VLLM_LOG"

# Wait until vLLM is running properly
sleep 20

while ! curl -s localhost:8000/v1/models | grep -q '"id":'
do
    # catch if vllm has crashed
    if [ -z "$(ps --pid $VLLM_PID --no-headers)" ]; then
        exit
    fi
    sleep 10
done

curl localhost:8000/v1/completions -H "Content-Type: application/json" \
     -d "{\"prompt\": \"What would be like a hello world for LLMs?\", \"temperature\": 0, \"max_tokens\": 100, \"model\": \"$MODEL\"}" | json_pp


curl localhost:8000/v1/models | json_pp

python classify_marco.py > $SCRIPT_LOG
SCRIPT_PID=$!

echo "Starting Ruoyu Script  $SCRIPT_PID - logs go to $SCRIPT_LOG"
# To stop job after we have run what we want kill it
#kill $VLLM_PID
wait

# ... if we want to leave it running instead, don't kill but wait
# wait
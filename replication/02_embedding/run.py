import os
import subprocess
import sys

# Set environment variable for HuggingFace API key
os.environ['HF_TOKEN'] = 'AAAAAAAAA'

# Install UV
subprocess.run('curl -LsSf https://astral.sh/uv/install.sh | sh', shell=True, check=True)

# Add UV to path
uv_path = os.path.expanduser('~/.cargo/bin')
os.environ['PATH'] = f"{uv_path}:{os.environ['PATH']}"

# Create .env file
with open('.env', 'w') as f:
    f.write(f"HF_TOKEN={os.environ.get('HF_TOKEN', '')}\n")

# Run main script
subprocess.run(['uv', 'run', '--env-file', '.env', './main.py'], check=True)


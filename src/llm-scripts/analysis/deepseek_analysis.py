'''Awaiting approval for LLAMA usage'''

from vllm import LLM, SamplingParams
import sqlite3
from huggingface_hub import login
from transformers import pipeline

con = sqlite3.connect("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/dev/data/embeddings.db")
con.text_factory = lambda b: b.decode(errors = 'ignore') # and here

cur = con.cursor()

res = cur.execute("SELECT id, data FROM PriA")
code_contents = res.fetchall()
with open("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/analysis/code_snips_two.txt", 'w') as f:
    print(f"Snippet 1: {code_contents[0]}\n AND Snippet 2: {code_contents[1]}", file=f)

pipe = pipeline("text-generation", model="deepseek-ai/DeepSeek-V3", trust_remote_code=True)

messages = [
    {"role": "user", "content": f"How similar are these two code snippets {code_contents[0]} and {code_contents[1]}?"}
]
pipe(messages)



# prompts = [
#     f"How similar are these two code snippets {code_contents[0]} and {code_contents[1]}?",
# ]
# sampling_params = SamplingParams(temperature=0.8, top_p=0.95)

# llm = LLM(model="meta-llama/Llama-3.1-8B-Instruct")

# outputs = llm.generate(prompts, sampling_params)

# for output in outputs:
#     prompt = output.prompt
#     generated_text = output.outputs[0].text
#     print(f"Prompt: {prompt!r}, Generated text: {generated_text!r}")

con.close()
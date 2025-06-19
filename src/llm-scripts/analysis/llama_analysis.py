'''Awaiting approval for LLAMA usage'''

from vllm import LLM, SamplingParams
import sqlite3
from huggingface_hub import login
import transformers
import torch

con = sqlite3.connect("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/dev/data/embeddings.db")
con.text_factory = lambda b: b.decode(errors = 'ignore') # and here

cur = con.cursor()

res = cur.execute("SELECT id, data FROM PriA")
code_contents = res.fetchall()

model_id = "meta-llama/Meta-Llama-3.1-8B-Instruct"

pipeline = transformers.pipeline(
    "text-generation",
    model=model_id,
    model_kwargs={"torch_dtype": torch.bfloat16},
    device_map="auto",
)
messages = [
    {"role": "user", "content": f"How similar are these two code snippets {code_contents[0]} and {code_contents[1]}?"}
]
# messages = [
#     {"role": "system", "content": "You are a pirate chatbot who always responds in pirate speak!"},
#     {"role": "user", "content": "Who are you?"},
# ]

outputs = pipeline(
    messages,
    max_new_tokens=256,
)
print(outputs[0]["generated_text"][-1])



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
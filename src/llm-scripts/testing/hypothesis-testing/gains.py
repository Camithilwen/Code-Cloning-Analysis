# The magic happens here
import matplotlib.pyplot as plt
import scikitplot as skplt
import pandas as pd

model="llama"

df_l = pd.read_csv("data/RAG_vs_CodeNet_binary_results_llama_iteration_1.csv")
df_d = pd.read_csv("data/RAG_vs_CodeNet_binary_complete_results_devstral_iteration_0.csv")
df_c = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_mistral_codestral22b_iteration_0.csv")

fig, axes = plt.subplots(1, 3, figsize=(18, 6))

skplt.metrics.plot_confusion_matrix(df_l['GroundTruthSimilar'], df_l['PredictedSimilar'], ax=axes[0])
axes[0].set_title("Llama3-8B")

skplt.metrics.plot_confusion_matrix(df_d['GroundTruthSimilar'], df_d['PredictedSimilar'], ax=axes[1])
axes[1].set_title("Devstral-24B")

skplt.metrics.plot_confusion_matrix(df_c['GroundTruthSimilar'], df_c['PredictedSimilar'], ax=axes[2])
axes[2].set_title("Codestral-22B")

plt.tight_layout()
plt.savefig("all_models_confusion_mtx.svg")
plt.show()

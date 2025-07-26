# The magic happens here
import matplotlib.pyplot as plt
import scikitplot as skplt
import pandas as pd

df_l = pd.read_csv("data/RAG_vs_CodeNet_binary_results_llama_iteration_0.csv")
df_d = pd.read_csv("data/RAG_vs_CodeNet_binary_complete_results_devstral_iteration_0.csv")
df_c = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_mistral_codestral22b_iteration_1.csv")

figure, axis = plt.subplots(1, 3)

lplt = skplt.metrics.plot_confusion_matrix(df_l['GroundTruthSimilar'], df_l['PredictedSimilar'])
axis[0,1].plot(lplt)
# axis[0, 1].plot(X, Y1)
# axis[0, 2].plot(X, Y1)

# plt.plot()
plt.savefig("llama_confusion_mtx.svg")
# use wilcoxon signed rank test instead of mcnemar since we can't assume normality

# https://dl.acm.org/doi/pdf/10.1145/3661167.3661199

import pandas as pd
from statsmodels.stats.contingency_tables import mcnemar
from scipy.stats import wilcoxon

csvs = [
    "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_devstral_final2.csv",
    "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_ds8b_final2.csv",
    "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_ds32b_final2.csv",
    "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_mistral_41.csv",
    "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_scoder_41.csv"
]

names = ["devstral:24b", "deepseek-r1:8b", "deepseek-r1:32b", "mistralai/codestral-22b-v0.1", "starcoder2-15b-instruct-v0.1"]
i = 0
for csv in csvs:
    df = pd.read_csv(csv)
    df_control = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/naive-comparison/NAIVE_vs_CodeNet_binary_results_all.csv")
    
    # print(f"{csv.split('/')[-1]}")
    print(names[i])
    
    
    # summarize the finding
    print('statistic=%.3f, p-value=%.30f' % (result.statistic, result.pvalue))
    # interpret the p-value
    alpha = 0.00005 # bonferroni correction
    if result.pvalue > alpha:
        print('Same proportions of errors (fail to reject H0)')
    else:
        print('Different proportions of errors (reject H0)')
    
    print("\n\n")
    i+=1
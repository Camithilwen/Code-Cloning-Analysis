# use wilcoxon signed rank test instead of mcnemar since we can't assume normality

# https://dl.acm.org/doi/pdf/10.1145/3661167.3661199

import pandas as pd
from scipy.stats import wilcoxon
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score

csvs = [
    "data/deepseek_iters.csv",
    "data/devstral_iters.csv"
]

# for pri in csvs[0]:
#     for sec in csvs[1]:
pri = csvs[0]
sec = csvs[1]
df_pri = pd.read_csv(pri)
df_sec = pd.read_csv(sec)

acc_pri = df_pri['Accuracy']
acc_sec = df_sec['Accuracy']

# print(f"{csv.split('/')[-1]}")
print(f"{pri.split("_")[0]} v. {sec.split("_")[0]}")

result = wilcoxon(acc_pri, acc_sec)

# summarize the finding
print('statistic=%.3f, p-value=%.30f' % (result.statistic, result.pvalue))
# interpret the p-value
alpha = 0.1 # bonferroni correction
if result.pvalue > alpha:
    print('Same proportions of errors (fail to reject H0)')
else:
    print('Different proportions of errors (reject H0)')

print("\n\n")
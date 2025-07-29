# use wilcoxon signed rank test instead of mcnemar since we can't assume normality

# https://dl.acm.org/doi/pdf/10.1145/3661167.3661199

import pandas as pd
from scipy.stats import wilcoxon
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score

jina_accs = [0.54, 0.54, 0.54, 0.54, 0.54, 0.54]

devstral_accs = [0.63, 0.63, 0.62
                 , 0.64, 0.62, 0.64]
llama_accs = [0.53, 0.54, 0.54
              , 0.53, 0.50, 0.51]
codestral_accs = [0.71, 0.72, 0.68, 0.68, 0.68, 0.68]

metrics = {"devstral": devstral_accs, "llama": llama_accs, "codestral": codestral_accs,
           "jina": jina_accs}


# prompt1_accs = [0.50, 0.50, 0.50, 0.50, 0.50, 0.50]

# prompt2_accs = [0.50, 0.50, 0.50, 0.50, 0.50, 0.50]

# prompt3_accs = [0.50, 0.50, 0.50, 0.50, 0.50, 0.50]

# prompt4_accs = [0.53, 0.54, 0.54
#               , 0.53, 0.53, 0.54]

# metrics = {"p1": prompt1_accs, "p2": prompt2_accs, "p3": prompt3_accs,
#            "p4": prompt4_accs}

matches = []

for acc_pri_k in metrics:
        for acc_sec_k in metrics:
            if acc_sec_k == acc_pri_k:
                 continue
            if f'{acc_sec_k}{acc_pri_k}' in matches:
                 continue
            matches.append(f'{acc_pri_k}{acc_sec_k}')

            acc_pri = metrics[acc_pri_k]
            acc_sec = metrics[acc_sec_k]

            print(acc_pri_k, acc_sec_k)

            result = wilcoxon(acc_pri, acc_sec)

            # summarize the finding
            print('statistic=%.3f, p-value=%.30f' % (result.statistic, result.pvalue))
            # interpret the p-value
            alpha = 0.05
            if result.pvalue > alpha:
                print('Same proportions of errors (fail to reject H0)')
            else:
                print('Different proportions of errors (reject H0)')

            print("\n\n")

            # 0.05 for models
            # 0.1 for prompting
# /// script
# dependencies = [
#   "pandas",
#   "scipy",
# ]
# ///

import pandas as pd
from scipy.stats import wilcoxon

## @var models
#  @brief Whether or not you're looking at models' results or not
models = True

if models:
    ## @brief Here, put in the accuracy or whichever metric you want into the lists
    jina_accs = [0.54, 0.54, 0.54, 0.54, 0.54, 0.54]

    devstral_accs = [0.63, 0.63, 0.62
                     , 0.64, 0.62, 0.64]
    llama_accs = [0.53, 0.54
                  , 0.53, 0.50, 0.51, 0.52]
    codestral_accs = [0.66, 0.69
                      , 0.67, 0.66, 0.65, 0.64]

    metrics = {"devstral": devstral_accs, "llama": llama_accs, "codestral": codestral_accs,
               "jina": jina_accs}

else:
    prompt1_accs = [0.50, 0.50, 0.50, 0.50, 0.50, 0.50]

    prompt2_accs = [0.50, 0.50, 0.50, 0.50, 0.50, 0.50]

    prompt3_accs = [0.50, 0.50, 0.50, 0.50, 0.50, 0.50]

    prompt4_accs = [0.53, 0.54
                , 0.53, 0.50, 0.51, 0.52]

    metrics = {"p1": prompt1_accs, "p2": prompt2_accs, "p3": prompt3_accs,
            "p4": prompt4_accs}

matches = []

for acc_pri_k in metrics:
        for acc_sec_k in metrics:
            if acc_sec_k == acc_pri_k:
                 continue
            if (acc_sec_k, acc_pri_k) in metrics:
                 continue
            matches.append((acc_pri_k, acc_sec_k))

            acc_pri = metrics[acc_pri_k]
            acc_sec = metrics[acc_sec_k]

            print(acc_pri_k, acc_sec_k)

            result = wilcoxon(acc_pri, acc_sec)

            ## @brief summarize the finding
            print('statistic=%.3f, p-value=%.30f' % (result.statistic, result.pvalue))
            ## @brief interpret the p-value
            ## @var alpha
            #  @brief Modify this to whatever your alpha value is
            alpha = 0.1
            if models:
                 alpha=0.05
            if result.pvalue > alpha:
                print('Same proportions of errors (fail to reject H0)')
            else:
                print('Different proportions of errors (reject H0)')

            print("\n\n")
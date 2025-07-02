# mcnemar test on mistral and devstral

import pandas as pd
from statsmodels.stats.contingency_tables import mcnemar

csvs = [
    "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_devstral_final2.csv",
    "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_ds8b_final2.csv",
    "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_ds32b_final2.csv",
    "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_mistral_41.csv",
    "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_scoder_41.csv"
]

for csv in csvs:
    df = pd.read_csv(csv)
    df_control = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/naive-comparison/NAIVE_vs_CodeNet_binary_results_all.csv")

    # a: 1298 cases where both correctly predicted the class.
    a = len(df.loc[
        (
            (
                df['GroundTruthSimilar'] == df['PredictedSimilar']
                )
        ) &
        (
            (
                df_control['GroundTruthSimilar'] == df_control['PredictedSimilar']
                )
        )
    ])

    # print(a)

    # b: 12 cases where Model A was correct, but Model B was incorrect.
    b = len(df.loc[
        (
            (
                df['GroundTruthSimilar'] == df['PredictedSimilar']
                )
        ) &
        (
            (
                df_control['GroundTruthSimilar'] != df_control['PredictedSimilar']
                ) 
        )
    ])

    # print(b)

    # c: 20 cases where Model B was correct, but Model A was incorrect.
    c = len(df.loc[
        (
            (
                df['GroundTruthSimilar'] != df['PredictedSimilar']
                )
        ) &
        (
            (
                df_control['GroundTruthSimilar'] == df_control['PredictedSimilar']
                ) 
        )
    ])

    # print(c)

    # d: 25 cases where both were incorrect.
    d = len(df.loc[
        (
            (
                df['GroundTruthSimilar'] != df['PredictedSimilar']
                )
        ) &
        (
            (
                df_control['GroundTruthSimilar'] != df_control['PredictedSimilar']
                )
        )
    ])

    # print(d)

    table = [[a, b], 
             [c, d]]
    
    print(f"{csv.split('/')[-1]}")

    print(table)
    
    # calculate mcnemar test
    result = mcnemar(table, exact=True)
    # summarize the finding
    print('statistic=%.3f, p-value=%.10f' % (result.statistic, result.pvalue))
    # interpret the p-value
    alpha = 0.00005 # bonferroni correction
    if result.pvalue > alpha:
        print('Same proportions of errors (fail to reject H0)')
    else:
        print('Different proportions of errors (reject H0)')
    
    print("\n\n")
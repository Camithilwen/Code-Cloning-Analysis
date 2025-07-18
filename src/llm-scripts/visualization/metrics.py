from sklearn.metrics import classification_report, precision_recall_fscore_support
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, mean_squared_error
import pandas as pd

BASE_DIR = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/visualization/data"

FILENAMES = [
    "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/DATA1K/RAG_vs_CodeNet_binary_results_starcoder_41.csv"
    #'RAG_vs_CodeNet_binary_results_mean_devstral_iter2_mistral_41_1k.csv'
    # 'sofar.csv'
    # '/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/naive-comparison/NAIVE_vs_CodeNet_binary_results_all.csv'
    # 'NAIVE_vs_CodeNet_binary_results_all.csv'
    # 'RAG_vs_CodeNet_binary_results_all_ds.csv',
    # 'RAG_vs_CodeNet_binary_results_all_scoder.csv',
    # 'RAG_vs_CodeNet_binary_results_mistral1.csv',
    # 'RAG_vs_CodeNet_binary_results_scoder1.csv',
    # 'RAG_vs_CodeNet_binary_results_scoder2.csv',
    # 'RAG_vs_CodeNet_binary_results_scoder11.csv',
    # 'RAG_vs_CodeNet_binary_results_scoder13.csv',
    # 'RAG_vs_CodeNet_binary_results_scoder14_all.csv',
    # 'RAG_vs_CodeNet_binary_results_mistral14_all.csv',
    # 'RAG_vs_CodeNet_binary_results_scoder15.csv',
    # 'RAG_vs_CodeNet_binary_results_scoder21.csv'
    # '/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/visualization/sofar.csv'
]

for fname in FILENAMES:
    if '/' in fname:
        df = pd.read_csv(fname)
    else:
        df = pd.read_csv(f"{BASE_DIR}/{fname}")

    # report = classification_report(df.loc[df['PredictedType']=="Type-4", 'GroundTruthSimilar'], df.loc[df['PredictedType']=="Type-4", 'PredictedSimilar'])
    with open(f'prevscoderrs.txt', 'w') as f:
        # acc0 = accuracy_score(df.loc[(df['GroundTruthSimilar']==0), 'GroundTruthSimilar'], df.loc[(df['GroundTruthSimilar']==0), 'PredictedSimilar'])
        # acc1 = accuracy_score(df.loc[(df['GroundTruthSimilar']==1) & (df['PredictedType']=="Type-4"), 'GroundTruthSimilar'], df.loc[(df['GroundTruthSimilar']==1) & (df['PredictedType']=="Type-4"), 'PredictedSimilar'])
        # print(f"Accuracy0: {acc0:.2f}, Accuracy1: {acc1:.2f}\n", file=f)
        # truths = df.loc[(df['PredictedType']=="Type-4"), 'GroundTruthSimilar']
        # preds = df.loc[(df['PredictedType']=="Type-4"), 'PredictedSimilar']
        # acc = accuracy_score(truths, preds)
        # prec = precision_score(truths, preds)
        # rec = recall_score(truths, preds)
        # f1 = f1_score(truths, preds)
        # print(f"Accuracy: {acc:.2f}, Precision: {prec:.2f}, Recall: {rec:.2f}, F1-Score: {f1:.2f}\n", file=f)
        # print(report, file=f)
        print('\n', file=f)
        acc = accuracy_score(df['GroundTruthSimilar'], df['PredictedSimilar'])
        prec = precision_score(df['GroundTruthSimilar'], df['PredictedSimilar'])
        rec = recall_score(df['GroundTruthSimilar'], df['PredictedSimilar'])
        f1 = f1_score(df['GroundTruthSimilar'], df['PredictedSimilar'])
        mse = mean_squared_error(df['GroundTruthSimilar'], df['PredictedSimilar'])
        print(f"Accuracy: {acc:.2f}, Precision: {prec:.2f}, Recall: {rec:.2f}, F1-Score: {f1:.2f}, MSE: {mse:.2f}\n", file=f)
        print(classification_report(df['GroundTruthSimilar'], df['PredictedSimilar']), file=f)
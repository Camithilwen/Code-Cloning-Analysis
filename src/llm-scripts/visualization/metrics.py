from sklearn.metrics import classification_report, precision_recall_fscore_support
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score
import pandas as pd

df = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_all_ds.csv")

report = classification_report(df['GroundTruthSimilar'], df['PredictedSimilar'])
with open('/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/metrics_ds638.txt', 'w') as f:
    acc0 = accuracy_score(df.loc[df['GroundTruthSimilar']==0, 'GroundTruthSimilar'], df.loc[df['GroundTruthSimilar']==0, 'PredictedSimilar'])
    acc1 = accuracy_score(df.loc[df['GroundTruthSimilar']==1, 'GroundTruthSimilar'], df.loc[df['GroundTruthSimilar']==1, 'PredictedSimilar'])
    print(f"Accuracy0: {acc0:.2f}, Accuracy1: {acc1:.2f}\n", file=f)
    
    acc = accuracy_score(df['GroundTruthSimilar'], df['PredictedSimilar'])
    prec = precision_score(df['GroundTruthSimilar'], df['PredictedSimilar'])
    rec = recall_score(df['GroundTruthSimilar'], df['PredictedSimilar'])
    f1 = f1_score(df['GroundTruthSimilar'], df['PredictedSimilar'])
    print(f"Accuracy: {acc:.2f}, Precision: {prec:.2f}, Recall: {rec:.2f}, F1-Score: {f1:.2f}\n", file=f)
    print(report, file=f)
# /// script
# dependencies = [
#   "scikit-learn",
#   "pandas",
# ]
# ///

from sklearn.metrics import classification_report
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, mean_squared_error
import pandas as pd

## @var FILENAMES
#  @brief All files that you want to do metrics of, write them all here
FILENAMES = [
    "./RAG_vs_CodeNet_binary_results_mistral_codestral22b_iteration_1.csv"
]

for fname in FILENAMES:
    df = pd.read_csv(fname)
    
    with open(f'comp_mistral.txt', 'w') as f:
        print('\n', file=f)
        acc = accuracy_score(df['GroundTruthSimilar'], df['PredictedSimilar'])
        prec = precision_score(df['GroundTruthSimilar'], df['PredictedSimilar'])
        rec = recall_score(df['GroundTruthSimilar'], df['PredictedSimilar'])
        f1 = f1_score(df['GroundTruthSimilar'], df['PredictedSimilar'])
        mse = mean_squared_error(df['GroundTruthSimilar'], df['PredictedSimilar'])
        print(f"Accuracy: {acc:.2f}, Precision: {prec:.2f}, Recall: {rec:.2f}, F1-Score: {f1:.2f}, MSE: {mse:.2f}\n", file=f)
        print(classification_report(df['GroundTruthSimilar'], df['PredictedSimilar']), file=f)
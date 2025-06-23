from sklearn.metrics import classification_report, precision_recall_fscore_support
import pandas as pd

df = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/meanofthreess.csv")

report = classification_report(df['GroundTruthSimilar'], df['PredictedSimilar'])
with open('/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/metricsmot.txt', 'w') as f:
    print(report, file=f)
from sklearn.metrics import classification_report, precision_recall_fscore_support
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score
import pandas as pd

df = pd.read_csv("play_data/RAG_vs_CodeNet_binary_results_all_ds.csv")
ITER = 4.2
results = []
# -- stuff --

for min_threshold in [0.0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.9, 1.0]:
    # for min_threshold2 in [0.0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.9, 1.0]:
    preds_tp = []
    preds_v = []

    for idx, row in df.iterrows():
        results = {"Type-1": row["Type-1"], "Type-2": row["Type-2"], "Type-3": row["Type-3"], "Type-4": row["Type-4"]}
        ## -- THRESH METHOD --
        if results['Type-4'] > min_threshold:
            preds_tp.append('Type-4')
            preds_v.append(1)
        else:
            preds_tp.append("Non-clone")
            preds_v.append(0)
        ## -- METHOD ENDS --

    df[f'PredictedSim{ITER}'] = preds_v
    df[f'PredictedType{ITER}'] = preds_tp

    predtpcolname = f"PredictedType{ITER}"
    predsimcolname = f"PredictedSim{ITER}"


    # -- RESULTS --
    with open(f'ITER{ITER}/ITER{ITER}_THR{min_threshold}.txt', 'w') as f:
        try:
            acc0 = accuracy_score(df.loc[(df['GroundTruthSimilar']==0), 'GroundTruthSimilar'], df.loc[(df['GroundTruthSimilar']==0), predsimcolname])
            acc1 = accuracy_score(df.loc[(df['GroundTruthSimilar']==1) & (df[predtpcolname]=="Type-4"), 'GroundTruthSimilar'], df.loc[(df['GroundTruthSimilar']==1) & (df[predtpcolname]=="Type-4"), predsimcolname])
            print(f"Accuracy0: {acc0:.2f}, Accuracy1: {acc1:.2f}\n", file=f)
        except ValueError:
            pass
        
        try:
            report = classification_report(df.loc[df[predtpcolname]=="Type-4", 'GroundTruthSimilar'], df.loc[df[predtpcolname]=="Type-4", predsimcolname])
            truths = df.loc[(df[predtpcolname]=="Type-4"), 'GroundTruthSimilar']
            preds = df.loc[(df[predtpcolname]=="Type-4"), predsimcolname]
            acc = accuracy_score(truths, preds)
            prec = precision_score(truths, preds)
            rec = recall_score(truths, preds)
            f1 = f1_score(truths, preds)
            print(f"Accuracy: {acc:.2f}, Precision: {prec:.2f}, Recall: {rec:.2f}, F1-Score: {f1:.2f}\n", file=f)
            print(report, file=f)
        except ValueError:
            pass
        
        print('\n', file=f)
        acc = accuracy_score(df['GroundTruthSimilar'], df[predsimcolname])
        prec = precision_score(df['GroundTruthSimilar'], df[predsimcolname])
        rec = recall_score(df['GroundTruthSimilar'], df[predsimcolname])
        f1 = f1_score(df['GroundTruthSimilar'], df[predsimcolname])
        print(f"Accuracy: {acc:.2f}, Precision: {prec:.2f}, Recall: {rec:.2f}, F1-Score: {f1:.2f}\n", file=f)
        print(classification_report(df['GroundTruthSimilar'], df[predsimcolname]), file=f)
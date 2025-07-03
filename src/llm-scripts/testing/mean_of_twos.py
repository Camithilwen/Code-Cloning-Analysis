import pandas as pd
import statistics
import math

df = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_all.csv")

groundtruth = ['GroundTruthSimilar']
predsim = ['PredictedSimilar']

for index, row in df.iterrows():
    if index==0:
        continue
    if row['PairID'] == 1001:
        break
    mistral_sim_score = row['PredictedSimilar']
    scoder_sim_score = df.loc[(df['ModelName']=='mistralai/codestral-22b-v0.1') & (df['PairID'] == row['PairID'])].values[0][8]
    groundtruth.append(row['GroundTruthSimilar'])
    predsim.append(math.ceil(statistics.mean([mistral_sim_score, scoder_sim_score])))

df2 = pd.DataFrame(groundtruth, predsim)

df2.to_csv("RAG_vs_CodeNet_binary_results_mean_devstral_iter2_mistral_41_1k.csv")
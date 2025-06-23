import pandas as pd
import statistics
import math

df = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_all.csv")

groundtruth = []
predsim = []

MAX = 200

for index, row in df.iterrows():
    if row['PairID'] == 201:
        break
    mistral_sim_score = row['PredictedSimilar']
    ds_sim_score = df.loc[(df['ModelName']=='deepseek/deepseek-r1-0528-qwen3-8b') & (df['PairID'] == row['PairID'])].values[0][8]
    scoder_sim_score = df.loc[(df['ModelName']=='starcoder2-15b-instruct-v0.1') & (df['PairID'] == row['PairID'])].values[0][8]
    groundtruth.append(row['GroundTruthSimilar'])
    predsim.append(math.ceil(statistics.mean([mistral_sim_score, ds_sim_score, scoder_sim_score])))

df2 = pd.DataFrame(groundtruth, predsim)

df2.to_csv("meanofthreess.csv")
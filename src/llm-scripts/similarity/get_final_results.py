import pandas as pd
import statistics
import csv

DIR_NAME = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/similarity/rag-result-files"

df = pd.read_csv('/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/similarity/rag-result-files/RAG_all_colX.csv')

with open(f"{DIR_NAME}/RAG_all_results.csv", 'w') as file:
    writer = csv.writer(file)
    writer.writerow(['FileID', 'Type-X', 'Collection'])

for col in ['FrkA', 'FrkB', 'FrkC']:
    for fid in range(0, 8):
        rowM = df.loc[(df['Collection'] == col) & (df['FileID'] == fid) & (df['ModelName'] == "mistralai/codestral-22b-v0.1")].values
        rowD = df.loc[(df['Collection'] == col) & (df['FileID'] == fid) & (df['ModelName'] == "deepseek/deepseek-r1-0528-qwen3-8b")].values
        rowS = df.loc[(df['Collection'] == col) & (df['FileID'] == fid) & (df['ModelName'] == "starcoder2-15b-instruct-v0.1")].values

        t1_res = statistics.mean([rowM[0][1], rowD[0][1], rowS[0][1]])
        t2_res = statistics.mean([rowM[0][2], rowD[0][2], rowS[0][2]])
        t3_res = statistics.mean([rowM[0][3], rowD[0][3], rowS[0][3]])
        t4_res = statistics.mean([rowM[0][4], rowD[0][4], rowS[0][4]])

        averages = [t1_res, t2_res, t3_res, t4_res]
        max = averages[0]
        index = 0

        for i in range(1, len(averages)):
            if averages[i] > max:
                max = averages[i]
                index = i
        
        with open(f"{DIR_NAME}/RAG_all_results.csv", 'a') as file:
            writer = csv.writer(file)
            writer.writerow([fid, f'Type-{index+1}', col])
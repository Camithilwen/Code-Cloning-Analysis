import pandas as pd

df = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/full_pipeline/milvus_rag_results_12.csv")


# print(df.loc[[((df['Type-1']==-1) & 
#               (df['Type-2']==-1) &
#               (df['Type-3']==-1) &
#               (df['Type-4']==-1)) == True]])

print(len(df[(df['Type-1']==-1) & 
              (df['Type-2']==-1) &
              (df['Type-3']==-1) &
              (df['Type-4']==-1) &
              (df['TargetCollection']=="fork_M2")]))

print(len(df))

print(3673/9726)

print(1406/3673)

print(1066/3673)

print(1099/3673)
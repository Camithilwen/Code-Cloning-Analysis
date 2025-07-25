import pandas as pd

df_og = pd.read_csv('/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/full_pipeline/milvus_complete.csv')

df = df_og[(df_og['Type-1']!=-1) & 
              (df_og['Type-2']!=-1) &
              (df_og['Type-3']!=-1) &
              (df_og['Type-4']!=-1)
              ]

dbs = ['Blog.db', 'Micro-ewolff.db']

df_blog = df[(df['Database']=='Blog.db')]
print(len(df_og[(df_og['Database']=='Spring-movie.db') & (df_og['TargetCollection']=='fork_M1')]))

df_wolf = df[df['Database']=='Micro-ewolff.db']

df_smovie = df[df['Database']=='Spring-movie.db']

print('T1 T2 T3 T4')
print( 
    len(df_blog[(df_blog['PredictedType']=='Type-1') & (df_blog['TargetCollection']=='fork_M1')]), 
    len(df_blog[(df_blog['PredictedType']=='Type-2') & (df_blog['TargetCollection']=='fork_M1')]), 
    len(df_blog[(df_blog['PredictedType']=='Type-3') & (df_blog['TargetCollection']=='fork_M1')]), 
    len(df_blog[(df_blog['PredictedType']=='Type-4') & (df_blog['TargetCollection']=='fork_M1')]), 
      )

print( 
    len(df_blog[(df_blog['PredictedType']=='Type-1') & (df_blog['TargetCollection']=='fork_M2')]), 
    len(df_blog[(df_blog['PredictedType']=='Type-2') & (df_blog['TargetCollection']=='fork_M2')]), 
    len(df_blog[(df_blog['PredictedType']=='Type-3') & (df_blog['TargetCollection']=='fork_M2')]), 
    len(df_blog[(df_blog['PredictedType']=='Type-4') & (df_blog['TargetCollection']=='fork_M2')]), 
      )

print( 
    len(df_blog[(df_blog['PredictedType']=='Type-1') & (df_blog['TargetCollection']=='fork_M3')]), 
    len(df_blog[(df_blog['PredictedType']=='Type-2') & (df_blog['TargetCollection']=='fork_M3')]), 
    len(df_blog[(df_blog['PredictedType']=='Type-3') & (df_blog['TargetCollection']=='fork_M3')]), 
    len(df_blog[(df_blog['PredictedType']=='Type-4') & (df_blog['TargetCollection']=='fork_M3')]), 
      )

print('\n')

print( 
    len(df_wolf[(df_wolf['PredictedType']=='Type-1') & (df_wolf['TargetCollection']=='fork_M1')]), 
    len(df_wolf[(df_wolf['PredictedType']=='Type-2') & (df_wolf['TargetCollection']=='fork_M1')]), 
    len(df_wolf[(df_wolf['PredictedType']=='Type-3') & (df_wolf['TargetCollection']=='fork_M1')]), 
    len(df_wolf[(df_wolf['PredictedType']=='Type-4') & (df_wolf['TargetCollection']=='fork_M1')]), 
      )

print( 
    len(df_wolf[(df_wolf['PredictedType']=='Type-1') & (df_wolf['TargetCollection']=='fork_M2')]), 
    len(df_wolf[(df_wolf['PredictedType']=='Type-2') & (df_wolf['TargetCollection']=='fork_M2')]), 
    len(df_wolf[(df_wolf['PredictedType']=='Type-3') & (df_wolf['TargetCollection']=='fork_M2')]), 
    len(df_wolf[(df_wolf['PredictedType']=='Type-4') & (df_wolf['TargetCollection']=='fork_M2')]), 
      )

print( 
    len(df_wolf[(df_wolf['PredictedType']=='Type-1') & (df_wolf['TargetCollection']=='fork_M3')]), 
    len(df_wolf[(df_wolf['PredictedType']=='Type-2') & (df_wolf['TargetCollection']=='fork_M3')]), 
    len(df_wolf[(df_wolf['PredictedType']=='Type-3') & (df_wolf['TargetCollection']=='fork_M3')]), 
    len(df_wolf[(df_wolf['PredictedType']=='Type-4') & (df_wolf['TargetCollection']=='fork_M3')]), 
      )

print('\n')
print( 
    len(df_smovie[(df_smovie['PredictedType']=='Type-1') & (df_smovie['TargetCollection']=='fork_M1')]), 
    len(df_smovie[(df_smovie['PredictedType']=='Type-2') & (df_smovie['TargetCollection']=='fork_M1')]), 
    len(df_smovie[(df_smovie['PredictedType']=='Type-3') & (df_smovie['TargetCollection']=='fork_M1')]), 
    len(df_smovie[(df_smovie['PredictedType']=='Type-4') & (df_smovie['TargetCollection']=='fork_M1')]), 
      )

print( 
    len(df_smovie[(df_smovie['PredictedType']=='Type-1') & (df_smovie['TargetCollection']=='fork_M2')]), 
    len(df_smovie[(df_smovie['PredictedType']=='Type-2') & (df_smovie['TargetCollection']=='fork_M2')]), 
    len(df_smovie[(df_smovie['PredictedType']=='Type-3') & (df_smovie['TargetCollection']=='fork_M2')]), 
    len(df_smovie[(df_smovie['PredictedType']=='Type-4') & (df_smovie['TargetCollection']=='fork_M2')]), 
      )

print( 
    len(df_smovie[(df_smovie['PredictedType']=='Type-1') & (df_smovie['TargetCollection']=='fork_M3')]), 
    len(df_smovie[(df_smovie['PredictedType']=='Type-2') & (df_smovie['TargetCollection']=='fork_M3')]), 
    len(df_smovie[(df_smovie['PredictedType']=='Type-3') & (df_smovie['TargetCollection']=='fork_M3')]), 
    len(df_smovie[(df_smovie['PredictedType']=='Type-4') & (df_smovie['TargetCollection']=='fork_M3')]), 
      )
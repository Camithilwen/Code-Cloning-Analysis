import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# --- DISTRUBTION OF DB PLOT ---
df_og = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/full_pipeline/milvus_complete.csv")

df = df_og[(df_og['Type-1']!=-1) & 
              (df_og['Type-2']!=-1) &
              (df_og['Type-3']!=-1) &
              (df_og['Type-4']!=-1)
              ]

print(df)
# collection_counts = df.groupby(['TargetCollection', 'PredictedType']).size().reset_index(name='Count')
collection_counts = df.groupby(['Database', 'PredictedType']).size().reset_index(name='Count')

overall_counts = df['PredictedType'].value_counts().reset_index()
overall_counts.columns = ['PredictedType', 'Count']
# overall_counts['TargetCollection'] = 'Overall'
overall_counts['Database'] = 'Overall'

combined = pd.concat([collection_counts, overall_counts], ignore_index=True)

plt.figure(figsize=(10, 6))
# sns.barplot(data=combined, x='PredictedType', y='Count', hue='TargetCollection')
sns.barplot(data=combined, x='PredictedType', y='Count', hue='Database')

plt.title('Distribution of Types across Databases and Overall')
plt.xlabel('Type')
plt.ylabel('Count')
plt.legend(title='Collection')
plt.tight_layout()
plt.savefig("./distribution_db.svg")

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# --- DISTRUBTION OF COL PLOT ---
df_og = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/full_pipeline/milvus_complete.csv")

df = df_og[(df_og['Type-1']!=-1) & 
              (df_og['Type-2']!=-1) &
              (df_og['Type-3']!=-1) &
              (df_og['Type-4']!=-1)
              ]

print(df)
collection_counts = df.groupby(['TargetCollection', 'PredictedType']).size().reset_index(name='Count')
# collection_counts = df.groupby(['Database', 'PredictedType']).size().reset_index(name='Count')

overall_counts = df['PredictedType'].value_counts().reset_index()
overall_counts.columns = ['PredictedType', 'Count']
overall_counts['TargetCollection'] = 'Overall'
# overall_counts['Database'] = 'Overall'

combined = pd.concat([collection_counts, overall_counts], ignore_index=True)

plt.figure(figsize=(10, 6))
sns.barplot(data=combined, x='PredictedType', y='Count', hue='TargetCollection')
# sns.barplot(data=combined, x='PredictedType', y='Count', hue='Database')

plt.title('Distribution of Types across Collections and Overall')
plt.xlabel('Type')
plt.ylabel('Count')
plt.legend(title='Collection')
plt.tight_layout()
plt.savefig("./distribution_col.svg")


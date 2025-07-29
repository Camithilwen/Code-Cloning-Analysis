# /// script
# dependencies = [
#   "matplotlib",
#   "pandas",
#   "seaborn",
# ]
# ///

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# --- DISTRUBTION OF DB PLOT ---
## @var df_og
#  @brief This is the path to the database predictions CSV
df_og = pd.read_csv("./milvus_complete.csv")

## @var df
#  @brief Remove all instances of errored results due to embedding model errors
df = df_og[(df_og['Type-1']!=-1) & 
              (df_og['Type-2']!=-1) &
              (df_og['Type-3']!=-1) &
              (df_og['Type-4']!=-1)
              ]

collection_counts = df.groupby(['Database', 'PredictedType']).size().reset_index(name='Count')

overall_counts = df['PredictedType'].value_counts().reset_index()
overall_counts.columns = ['PredictedType', 'Count']
overall_counts['Database'] = 'Overall'

combined = pd.concat([collection_counts, overall_counts], ignore_index=True)

plt.figure(figsize=(10, 6))
sns.barplot(data=combined, x='PredictedType', y='Count', hue='Database')

plt.title('Distribution of Types across Databases and Overall')
plt.xlabel('Type')
plt.ylabel('Count')
plt.legend(title='Databases')
plt.tight_layout()
plt.savefig("./distribution_db.svg")

## --- DISTRIBUTION OF COLLECTIONS ---
## @brief Same but now with the collection type (embedding model) as our divisor
collection_counts = df.groupby(['TargetCollection', 'PredictedType']).size().reset_index(name='Count')

overall_counts = df['PredictedType'].value_counts().reset_index()
overall_counts.columns = ['PredictedType', 'Count']
overall_counts['TargetCollection'] = 'Overall'

combined = pd.concat([collection_counts, overall_counts], ignore_index=True)

plt.figure(figsize=(10, 6))
sns.barplot(data=combined, x='PredictedType', y='Count', hue='TargetCollection')

plt.title('Distribution of Types across Collections and Overall')
plt.xlabel('Type')
plt.ylabel('Count')
plt.legend(title='Collection')
plt.tight_layout()
plt.savefig("./distribution_col.svg")


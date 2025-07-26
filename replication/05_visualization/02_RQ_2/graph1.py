import pandas as pd
import matplotlib.pyplot as plt

# Load your data
df_og = pd.read_csv('/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/full_pipeline/milvus_complete.csv')
df = df_og[(df_og['Type-1']!=-1) & 
              (df_og['Type-2']!=-1) &
              (df_og['Type-3']!=-1) &
              (df_og['Type-4']!=-1)]
# Count occurrences of each predicted type
type_counts = df['PredictedType'].value_counts()

# Bar Plot
# plt.figure(figsize=(8, 5))
# type_counts.plot(kind='bar', color='skyblue', edgecolor='black')
# plt.title('Distribution of Predicted Types')
# plt.xlabel('Predicted Type')
# plt.ylabel('Count')
# plt.xticks(rotation=45)
# plt.tight_layout()
# plt.savefig("zero.png")

# type_means = df.groupby('PredictedType')[['Type-1', 'Type-2', 'Type-3', 'Type-4']].mean()

# type_means.plot(kind='bar', stacked=True, figsize=(10,6), colormap='tab20')
# plt.title('Average Type Probabilities by Predicted Type')
# plt.xlabel('Predicted Type')
# plt.ylabel('Mean Probability')
# plt.legend(title='Type')
# plt.tight_layout()
# plt.savefig("two.png")

import seaborn as sns

plt.figure(figsize=(6,5))
sns.heatmap(df[['Type-1', 'Type-2', 'Type-3', 'Type-4']].corr(), annot=True, cmap='coolwarm')
plt.title('Correlation Between Type Scores')
plt.tight_layout()
plt.savefig("four.svg")


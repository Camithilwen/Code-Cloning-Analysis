import pandas as pd
import matplotlib.pyplot as plt

# Load your data
df = pd.read_csv('/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/full_pipeline/milvus_rag_results.csv')

# Count occurrences of each predicted type
type_counts = df['PredictedType'].value_counts()

# Bar Plot
plt.figure(figsize=(8, 5))
type_counts.plot(kind='bar', color='skyblue', edgecolor='black')
plt.title('Distribution of Predicted Types')
plt.xlabel('Predicted Type')
plt.ylabel('Count')
plt.xticks(rotation=45)
plt.tight_layout()
plt.savefig("zero.png")

# Pie Chart
# plt.figure(figsize=(6, 6))
# type_counts.plot(kind='pie', autopct='%1.1f%%', startangle=90, colors=plt.cm.Paired.colors)
# plt.title('Predicted Type Distribution')
# plt.ylabel('')
# plt.tight_layout()
# plt.savefig("one.png")

type_means = df.groupby('PredictedType')[['Type-1', 'Type-2', 'Type-3', 'Type-4']].mean()

type_means.plot(kind='bar', stacked=True, figsize=(10,6), colormap='tab20')
plt.title('Average Type Probabilities by Predicted Type')
plt.xlabel('Predicted Type')
plt.ylabel('Mean Probability')
plt.legend(title='Type')
plt.tight_layout()
plt.savefig("two.png")

# plt.figure(figsize=(12, 8))
# for i, t in enumerate(['Type-1', 'Type-2', 'Type-3', 'Type-4']):
#     plt.subplot(2, 2, i+1)
#     df.boxplot(column=t, by='PredictedType')
#     plt.title(f'{t} Distribution by Predicted Type')
#     plt.suptitle('')
#     plt.xlabel('Predicted Type')
#     plt.ylabel('Score')
# plt.tight_layout()
# plt.savefig("three.png")

import seaborn as sns

plt.figure(figsize=(6,5))
sns.heatmap(df[['Type-1', 'Type-2', 'Type-3', 'Type-4']].corr(), annot=True, cmap='coolwarm')
plt.title('Correlation Between Type Scores')
plt.tight_layout()
plt.savefig("four.png")


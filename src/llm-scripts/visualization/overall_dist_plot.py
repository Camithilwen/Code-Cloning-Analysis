import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# --- DISTRUBTION OF TYPES PLOT ---
df = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/visualization/data/RAG_all_results.csv")

collection_counts = df.groupby(['Collection', 'Type-X']).size().reset_index(name='Count')

overall_counts = df['Type-X'].value_counts().reset_index()
overall_counts.columns = ['Type-X', 'Count']
overall_counts['Collection'] = 'Overall'

combined = pd.concat([collection_counts, overall_counts], ignore_index=True)

plt.figure(figsize=(10, 6))
sns.barplot(data=combined, x='Type-X', y='Count', hue='Collection')

plt.title('Distribution of Types across Collections and Overall')
plt.xlabel('Type')
plt.ylabel('Count')
plt.legend(title='Collection')
plt.tight_layout()
plt.savefig("./distribution.png")

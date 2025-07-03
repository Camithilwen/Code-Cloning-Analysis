import pandas as pd
import matplotlib.pyplot as plt

# Load your data
df = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/RAG_vs_CodeNet_binary_results_scoder_41.csv")
# df = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/visualization/sofar.csv")

# Group by GroundTruthSimilar (0: non-similar, 1: similar)
categories = [0, 1]
counts = []
accuracies = []

for cat in categories:
    group = df[df['GroundTruthSimilar'] == cat]
    counts.append(len(group))
    if len(group) > 0:
        accuracy = (group['PredictedSimilar'] == group['GroundTruthSimilar']).mean()
    else:
        accuracy = 0
    accuracies.append(accuracy)

# Plotting
fig, ax1 = plt.subplots()

# Bar plot for counts
bars = ax1.bar(['Non-similar', 'Similar'], counts, color='lightpink', label='Count')
ax1.set_ylabel('Number of Samples', color='lightpink')
ax1.set_xlabel('Ground Truth Similarity')
ax1.tick_params(axis='y', labelcolor='lightpink')

# Line plot for accuracy
ax2 = ax1.twinx()
ax2.plot(['Non-similar', 'Similar'], accuracies, color='mediumpurple', marker='o', label='Accuracy')
ax2.set_ylabel('Accuracy', color='mediumpurple')
ax2.tick_params(axis='y', labelcolor='mediumpurple')
ax2.set_ylim(0, 1)

# Titles and legends
plt.title('Number of Samples and Accuracy by CodeNet: StarCoder')
fig.tight_layout()
plt.savefig("starcoder_final.png")


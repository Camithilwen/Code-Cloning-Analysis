import os
import re
import numpy as np

labels = [
    "Accuracy", "Precision", "Recall", "F1-Score", "MSE",  # First line
    "Class 0 Precision", "Class 0 Recall", "Class 0 F1-Score",
    "Class 1 Precision", "Class 1 Recall", "Class 1 F1-Score",
    "Macro Avg Precision", "Macro Avg Recall", "Macro Avg F1-Score",
    "Weighted Avg Precision", "Weighted Avg Recall", "Weighted Avg F1-Score"
]

def extract_metrics_from_file(filepath):
    with open(filepath, 'r') as f:
        text = f.read()

    first_line_match = re.search(
        r'Accuracy:\s*([\d.]+),\s*Precision:\s*([\d.]+),\s*Recall:\s*([\d.]+),\s*F1-Score:\s*([\d.]+),\s*MSE:\s*([\d.]+)',
        text
    )
    line_metrics = list(map(float, first_line_match.groups())) if first_line_match else []

    table_pattern = re.findall(
        r'^\s*\d?\s*\d?\s*([\d.]+)\s+([\d.]+)\s+([\d.]+)\s+\d+',
        text,
        re.MULTILINE
    )
    table_metrics = [float(val) for group in table_pattern for val in group]

    return line_metrics + table_metrics

def compute_average_metrics(folder_path):
    all_metrics = []

    for filename in os.listdir(folder_path):
        if filename.endswith(".txt"):
            filepath = os.path.join(folder_path, filename)
            metrics = extract_metrics_from_file(filepath)
            if metrics:
                all_metrics.append(metrics)

    if not all_metrics:
        print("No metrics found.")
        return

    max_len = max(len(m) for m in all_metrics)
    all_metrics = [m + [np.nan] * (max_len - len(m)) for m in all_metrics]

    averages = np.nanmean(np.array(all_metrics), axis=0)

    print("Average Metrics:\n")
    for label, value in zip(labels, averages):
        print(f"{label}: {value:.4f}")

# ---------- MAIN ----------
folder_path = '/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/hypothesis-testing/llama_results'
compute_average_metrics(folder_path)

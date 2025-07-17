import os
import re
import math
import glob

def extract_second_metrics_from_file(file_path):
    with open(file_path, 'r') as f:
        content = f.read()

        # Match all "Accuracy: ..., Precision: ..., Recall: ..., F1-Score: ..." lines
        matches = re.findall(
            r'Accuracy\s*:\s*([0-9.]+|nan)\s*,\s*'
            r'Precision\s*:\s*([0-9.]+|nan)\s*,\s*'
            r'Recall\s*:\s*([0-9.]+|nan)\s*,\s*'
            r'F1-Score\s*:\s*([0-9.]+|nan)',
            content, re.IGNORECASE
        )

        # Only use the second match if it exists
        if len(matches) >= 2:
            accuracy, precision, recall, f1 = matches[1]
            return {
                'file': file_path,
                'accuracy': float(accuracy) if accuracy != 'nan' else float('nan'),
                'precision': float(precision) if precision != 'nan' else float('nan'),
                'recall': float(recall) if recall != 'nan' else float('nan'),
                'f1_score': float(f1) if f1 != 'nan' else float('nan')
            }
        else:
            return None  # Skip files without 2 blocks

def find_best_file_by_metric(directory, metric='f1_score'):
    all_metrics = []

    for file_path in glob.glob(os.path.join(directory, '*.txt')):
        metrics = extract_second_metrics_from_file(file_path)
        if metrics and not math.isnan(metrics[metric]):
            all_metrics.append(metrics)

    if not all_metrics:
        return None

    best = max(all_metrics, key=lambda x: x[metric])
    return best

# Example usage
if __name__ == "__main__":
    directory_path = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/best_threshold/ITER4.2"
    best_result = find_best_file_by_metric(directory_path, metric='accuracy')  # or 'accuracy'

    if best_result:
        print(f"Best file (based on second metric block): {best_result['file']}")
        print(f"Accuracy: {best_result['accuracy']:.2f}, Precision: {best_result['precision']:.2f}, Recall: {best_result['recall']:.2f}, F1-Score: {best_result['f1_score']:.2f}")
    else:
        print("No valid results found with two metric blocks.")

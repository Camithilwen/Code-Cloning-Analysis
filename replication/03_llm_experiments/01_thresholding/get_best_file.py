# /// script
# ///

import os
import re
import math
import glob

# /**
#  * @brief Extracts the second occurrence of evaluation metrics from a file.
#  * 
#  * This function searches for lines in the format:
#  * "Accuracy: ..., Precision: ..., Recall: ..., F1-Score: ..."
#  * and extracts the second such occurrence (if it exists) from the file.
#  *
#  * @param file_path The path to the text file to parse.
#  * @return A dictionary containing the second block of metrics with keys:
#  *         'file', 'accuracy', 'precision', 'recall', 'f1_score', or
#  *         None if the second block is not found.
#  */
def extract_second_metrics_from_file(file_path):
    with open(file_path, 'r') as f:
        content = f.read()

        # Match all metric blocks
        matches = re.findall(
            r'Accuracy\s*:\s*([0-9.]+|nan)\s*,\s*'
            r'Precision\s*:\s*([0-9.]+|nan)\s*,\s*'
            r'Recall\s*:\s*([0-9.]+|nan)\s*,\s*'
            r'F1-Score\s*:\s*([0-9.]+|nan)',
            content, re.IGNORECASE
        )

        # Return the second set of metrics if available
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
            return None  # Not enough metric blocks found

# /**
#  * @brief Finds the file with the best metric value in a directory.
#  * 
#  * Iterates over all .txt files in the specified directory and uses
#  * the second block of metrics for comparison.
#  *
#  * @param directory The directory containing the result files.
#  * @param metric The metric to optimize ('accuracy', 'precision', 'recall', or 'f1_score').
#  * @return A dictionary with the file path and best metric values, or None if no valid files found.
#  */
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

# /// Example usage
if __name__ == "__main__":
    directory_path = "/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/testing/best_threshold/ITER4.2"
    best_result = find_best_file_by_metric(directory_path, metric='accuracy')  # Change metric as needed

    if best_result:
        print(f"Best file (based on second metric block): {best_result['file']}")
        print(f"Accuracy: {best_result['accuracy']:.2f}, Precision: {best_result['precision']:.2f}, Recall: {best_result['recall']:.2f}, F1-Score: {best_result['f1_score']:.2f}")
    else:
        print("No valid results found with two metric blocks.")
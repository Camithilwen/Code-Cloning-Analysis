import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import matplotlib.patches as mpatches

df = pd.read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/visualization/data/RAG_all_colX.csv")

# --- SINGLE FILE PLOT ---
def get_fid_plot(fid, frk):
    cats = np.array(['Type-1', 'Type-2', 'Type-3', 'Type-4'])

    mistral_rw = df.loc[(df['FileID'] == fid) & (df['ModelName'] == "mistralai/codestral-22b-v0.1") & (df['Collection'] == frk)]
    print(np.array(mistral_rw.values))
    mistral = np.array([mistral_rw.values[0][1], 
            mistral_rw.values[0][2], 
            mistral_rw.values[0][3], 
            mistral_rw.values[0][4]])
    print(mistral)

    ds_row = df.loc[(df['FileID'] == fid) & (df['ModelName'] == "deepseek/deepseek-r1-0528-qwen3-8b") & (df['Collection'] == frk)]

    deepseek = np.array([ds_row.values[0][1], 
            ds_row.values[0][2], 
            ds_row.values[0][3], 
            ds_row.values[0][4]])
    print(deepseek)

    scoder_row = df.loc[(df['FileID'] == fid) & (df['ModelName'] == "starcoder2-15b-instruct-v0.1") & (df['Collection'] == frk)]
    starcoder = np.array([scoder_row.values[0][1], 
            scoder_row.values[0][2], 
            scoder_row.values[0][3], 
            scoder_row.values[0][4]])
    print(starcoder)

    w = 0.25 
    x = np.arange(len(cats))

    min_height = 0
    mistral_plot = np.where(mistral < 0, min_height, mistral)
    starcoder_plot = np.where(starcoder < 0, min_height, starcoder)
    deepseek_plot = np.where(deepseek < 0, min_height, deepseek)

    fig, ax = plt.subplots()

    ax.bar(x - w, mistral_plot, width=w, label='Mistral')
    ax.bar(x, starcoder_plot, width=w, label='Starcoder')
    ax.bar(x + w, deepseek_plot, width=w, label='Deepseek')

    ax.set_xticks(x)
    ax.set_xticklabels(cats)
    ax.set_ylabel('Type Relevance')
    ax.set_title(f"Type Distribution for File Number {fid}")
    ax.legend()

    plt.savefig(f"types_for_fid_{fid}_{frk}.png")

if __name__ == '__main__':
    fids = [0, 1, 2, 3, 4, 5, 6, 7]
    for i in ['FrkA', 'FrkB', 'FrkC']:
        for fid in fids:
                get_fid_plot(fid, i)
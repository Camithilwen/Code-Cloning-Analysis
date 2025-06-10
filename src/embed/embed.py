# ---
# jupyter:
#   jupytext:
#     formats: ipynb,py:percent
#     text_representation:
#       extension: .py
#       format_name: percent
#       format_version: '1.3'
#       jupytext_version: 1.17.1
#   kernelspec:
#     display_name: Python 3
#     name: python3
# ---

# %% colab={"base_uri": "https://localhost:8080/", "height": 1000} id="CU0kDis-Rs3I" outputId="85b52138-ee07-46b0-9d79-7316193e3d30"
#System installs
# !curl -LsSf https://astral.sh/uv/install.sh | sh


# %% colab={"base_uri": "https://localhost:8080/"} id="bM0PSGoFanJQ" outputId="aac9ccaf-41ac-4b1c-c473-c4ed012e23e3"
# !export HF_TOKEN=''
# !huggingface-cli login

# %% id="6z2q8uP7RuyA"
# uv run main.py
#
# %%
# !rm -rf ./repo

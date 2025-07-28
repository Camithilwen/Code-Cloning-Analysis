#!/bin/bash

BASE_DIR="/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/csc_script/repo-scripts/again"
TO_DIR="/projappl/project_2014646/shreya"

scp -r -O $BASE_DIR/complete_repo_results_apollo.py muhammab@mahti.csc.fi:$TO_DIR
scp -r -O $BASE_DIR/complete_repo_results_Jaeger.py muhammab@mahti.csc.fi:$TO_DIR
scp -r -O $BASE_DIR/complete_repo_results_piggymetrics.py muhammab@mahti.csc.fi:$TO_DIR
scp -r -O $BASE_DIR/complete_repo_results_robotshop.py muhammab@mahti.csc.fi:$TO_DIR
scp -r -O $BASE_DIR/apollo.sh muhammab@mahti.csc.fi:$TO_DIR
scp -r -O $BASE_DIR/jaeger.sh muhammab@mahti.csc.fi:$TO_DIR
scp -r -O $BASE_DIR/piggymetrics.sh muhammab@mahti.csc.fi:$TO_DIR
scp -r -O $BASE_DIR/robotshop.sh muhammab@mahti.csc.fi:$TO_DIR
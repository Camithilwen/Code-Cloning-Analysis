# Load the necessary libraries
install.packages('readr')
library(readr)

# Load the dataset from the CSV file
dataset_og <- read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/full_pipeline/milvus_rag_results_12.csv")

# Display the first few rows of the dataset
head(dataset_og)

dataset<-dataset_og[dataset_og$"Type-1"!=-1,]

# Display the column names
colnames(dataset)

# Install and load the package
install.packages('dplyr')

library(dplyr)

# Select the columns of interest
selected_data <- dataset %>% select("PredictedType", "Database")

# Create a contingency table for Highest educational level and Anemia level
contingency_table <- table(selected_data$"PredictedType", selected_data$"Database")

# View the contingency table
print(contingency_table)

# Perform chi-square test
chi_square_test <- chisq.test(contingency_table)

# View the results
print(chi_square_test)

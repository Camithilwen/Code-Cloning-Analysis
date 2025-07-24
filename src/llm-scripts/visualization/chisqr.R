# Load the necessary libraries
install.packages('readr')
install.packages('dplyr')
install.packages("pheatmap")

library(readr)
library(dplyr)
library(pheatmap)

# Load the dataset from the CSV file
dataset_og <- read_csv("/Users/shreyanakum/Documents/NSF@Oulu/Code-Cloning-Analysis/src/llm-scripts/full_pipeline/milvus_complete.csv")

# Display the first few rows of the dataset
head(dataset_og)

dataset<-dataset_og[dataset_og$"Type-1"!=-1,]

# Display the column names
colnames(dataset)

# Install and load the package

# Select the columns of interest
selected_data <- dataset %>% select("PredictedType")

# Create a contingency table
contingency_table <- table(selected_data$"PredictedType")

# View the contingency table
print(contingency_table)

# Perform chi-square test
chi_square_test <- chisq.test(contingency_table)

# View the results
print(chi_square_test)

# Observed counts
observed_counts <- chi_square_test$observed

print(observed_counts)

# Expected counts
expected_counts <- chi_square_test$expected
print(round(expected_counts, 2))

# Pearson residuals
pearson_residuals <- chi_square_test$residuals
print(round(pearson_residuals, 2))



# p value is less than alpha = 2.2e-16, which means that our results are statistically
# significant.
# the results are statistically significant and deviate from the uniform 
# expected counts.
# based on the pearson residuals, we can see that Type-1 is has a large positive residual,
# which means that it is significantly higher than the expected Type-1 count.
# Type-2 and Type-4 have large negative residuals, meaning that they are significanlty
# lower than the respective expected counts.
# Type-3 is a small positive residual, at 6.27, which means that Type-3
# clones are slightly higher than the expectected count of Type-3.

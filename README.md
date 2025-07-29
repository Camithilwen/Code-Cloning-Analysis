# Microservice-Specific Code Cloning Analysis

## Shreya Nakum, Jamie Kemman

This repository is the culmination of research conducted during the 2025 IRES NSF REU program organized through the University of Arizona and sponsored by the University of Oulu, Finland.

## Abstract
Code reuse is a widespread efficiency practice in software development, especially in the emerging realm of microservice development. Microservices are small-scale, single-task or single-service software components which are coupled to other microservices to form robust large software systems via common communication protocols. There is a proliferation of microservice projects available with open source licenses through Github. This allows developers to quickly copy and adapt existing architecture to any given use case, but it also results in a proliferation of reused code in various states of change from the original source. Use of cloned code, though efficient, can carry intensive maintenance costs if changes are required across the entire population of a given clone. Identifying the presence and distribution of code clones within a software project is therefore of interest to developers, but manual identification of cloned code segments is tedious and time-consuming as code clones may exist as any of several subtypes. Furthermore, existing analysis tools are often limited in scope and available only for select programming languages. In response to the need for rapid and multilingual analysis for the full spectrum of code clone types, large language models (LLMs) emerge as a prime contender. In order to evaluate the potential of LLMs for this purpose, we compiled a dataset of 26 open source microservice repositories and 26 forks in various states of change and compared the performance of one general purpose and two code-specific LLMs. We found that the sampled LLMs performed close to the overall accuracy of human evaluators in identifying overall distribution of clones on a subset of the data, albeit with false negative results. We also found LLMs to be perform well at differentiating between clone subtypes when compared to an approach using non-generative machine learning techniques.

## Doxygen Documentation


## References
We used matplotlib, scikit learn, pandas, ollama, lmstudio, scikit-plot, R studio, IBM CodeNet, Pymilvus, pytorch, hugging face, GitPython, and transformers.

(J. D. Hunter, "Matplotlib: A 2D Graphics Environment", Computing in Science & Engineering, vol. 9, no. 3, pp. 90-95, 2007)[https://ieeexplore.ieee.org/document/4160265].

(Scikit-learn: Machine Learning in Python)[https://jmlr.csail.mit.edu/papers/v12/pedregosa11a.html], Pedregosa et al., JMLR 12, pp. 2825-2830, 2011.

(Data structures for statistical computing in python)[https://pub.curvenote.com/01908378-3686-7168-a380-d82bbf21c799/public/mckinney-57fc0d4e8a08cd7f26a4b8bf468a71f4.pdf], McKinney, Proceedings of the 9th Python in Science Conference, Volume 445, 2010.

R Core Team (2021). R: A language and environment for statistical computing. R Foundation for Statistical Computing, Vienna, Austria. URL https://www.R-project.org/.


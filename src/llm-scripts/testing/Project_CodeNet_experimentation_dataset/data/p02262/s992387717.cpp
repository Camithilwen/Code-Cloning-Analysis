#include <iostream>
#include <cstdlib>

const int MAX_SIZE = 1000000;
const int MAX_M = 100 + 1;

void insertionSort(int A[], int n, int g, int &count) {
  for (int i = g; i < n; i++) {
     int v = A[i];

     int j = i -g;
    
     while ((j >= 0) && (A[j] > v)) {
       A[j + g] = A[j];
       j -= g;
       count = count + 1;
     }

     A[j + g] = v;
  }
}

int main() {
  int n = 0;

  std::cin >> n;

  int A[MAX_SIZE] = {0};

  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  int m = 0;
  int G[MAX_M] = {0};

  G[0] = 1;
  m++;

  while (G[m] < n) {
    int g = 3 * G[m - 1] + 1;

    if (g >= n) {
      break;
    } else {
      G[m] = g;
    }

    m++;
  }

  std::cout << m << std::endl;
    
  int count = 0;

  for (int i = m - 1; i >= 0; i--) {
    std::cout << G[i];

    if (i > 0) {
      std::cout << " ";
    } else {
      std::cout << std::endl;
    }    
    
    insertionSort(A, n, G[i], count);
  }
  
  std::cout << count << std::endl;
  
  for (int i = 0; i < n; i++) {
    std::cout << A[i] << std::endl;
  }
  
  return 0;
}
#include <iostream>
#include <vector>

void printArray(std::vector<int> a) {
  int n = (int)a.size();
  for (int i = 0; i < n; i++) {
    std::cout << a[i] <<std::endl; 
  }
}

int insertionSort(std::vector<int> &a, int g) {
  int cnt = 0, n = (int)a.size();
  for (int i = g; i < n; i++) {
    int v = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > v) {
      a[j + g] = a[j];
      j = j - g;
      cnt++;
    }
    a[j + g] = v;
  }
  return cnt;
}

int shellSort(std::vector<int> &a) {
  std::vector<int> g;
  for (int i = 1; i <= (int)a.size(); i = i * 3 + 1) {
    g.push_back(i);
  }
  int m = (int)g.size();
  std::cout << m << std::endl;

  int cnt = 0;
  for (int i = m - 1; i >= 0; i--) {
    cnt += insertionSort(a, g[i]);

    std::cout << g[i];
    if (i > 0)
      std::cout << " ";
    else
      std::cout << std::endl;
  }

  return cnt;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::cout << shellSort(a) << std::endl;
  printArray(a);
}


#include <bits/stdc++.h>

int main() {

  int v[128];
  int n;

  std::cin >> n;
  for(int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }

  for(int i = n-1; i > 0; --i) {
    std::cout << v[i] << " ";
  }
  std::cout << v[0] << std::endl;
  
  
  return 0;
}
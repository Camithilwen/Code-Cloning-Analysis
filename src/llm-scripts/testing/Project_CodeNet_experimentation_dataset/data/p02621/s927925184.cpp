#include <iostream>

int main() {
  int a; std::cin >> a;
  int sum = a;
  sum += a*a + a*a*a;
  std::cout << sum << std::endl;
  
  return 0;
} 
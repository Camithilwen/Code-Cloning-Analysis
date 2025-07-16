#include <iostream>

int main()
{
  int a, b, c;
  std::cin >> a >> b >> c;
  if (a==b) {
    if (a!=c) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
  }
  else {
    if (a==c || b==c) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
  }
  return 0;
}
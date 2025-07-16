#include <iostream>
#include <string>

int main()
{
  int K;
  std::string S;
  std::cin >> K;
  std::cin >> S;
  if (S.length() <= K) std::cout << S << std::endl;
  else std::cout << S.substr(0, K) << "..." << std::endl;
  return 0;
}

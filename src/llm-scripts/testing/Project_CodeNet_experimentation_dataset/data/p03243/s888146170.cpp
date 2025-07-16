#include <iostream>

int main() {
  int N;
  std::cin >> N;

  int abc_in;
  if (N % 111 == 0)
    abc_in = N;
  else
    abc_in = ((N / 111) + 1) * 111;

  std::cout << abc_in << std::endl;
  return 0;
}

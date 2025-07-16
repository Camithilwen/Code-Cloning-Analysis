#include <iostream>

int main(int argc, char const* argv[])
{
  int i, n, a, b, a_score, b_score;

  while (true) {
    a_score = 0;
    b_score = 0;

    std::cin >> n;
    if (n == 0) { break; }

    for (i = 0; i < n; i++) {
      std::cin >> a;
      std::cin >> b;

      if (a > b) {
        a_score += (a + b);
      } else if (b > a) {
        b_score += (a + b);
      } else {
        a_score += a;
        b_score += b;
      }
    }
    std::cout << a_score << " " << b_score << std::endl;
  }

  return 0;
}
#include <iostream>
#include <string>

typedef long long ll;

std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
ll N;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin >> N;
  std::string ans = "";
  while (N) {
    N--;
    ans = alphabet[N % 26] + ans;
    N /= 26;
  }

  std::cout << ans << "\n";

  return 0;
}

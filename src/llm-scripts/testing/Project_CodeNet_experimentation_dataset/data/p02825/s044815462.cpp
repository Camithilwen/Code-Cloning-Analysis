// Written by newbiechd
#include <cstring>
#include <iostream>
#include <string>

const int maxN = 13;
int n;

const std::string ans[][7] = {
  {
    "aabc",
    "ddbc",
    "efgg",
    "efhh"
  },
  {
    "aabbd",
    "ccf.d",
    "eefgg",
    "..hij",
    "..hij"
  },
  {
    "aabbcc",
    "ddeeff",
    "ghi...",
    "ghi...",
    "...jkl",
    "...jkl"
  },
  {
    "aabbcc.",
    "ddee..h",
    "ffgg..h",
    "....ijk",
    "....ijk",
    "....lmn",
    "....lmn"
  }
};

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  
  if (n < 3) {
    printf("-1\n");
    return 0;
  }
  if (n == 3) {
    std::cout << "aa.\n..a\n..a\n";
    return 0;
  }

  int k = (n & 3) + 4;
  for (int i = 0; i < n - k; ++i) {
    std::string str(n, '.');
    str.replace(i / 4 * 4, 4, ans[0][i % 4]);
    std::cout << str << '\n';
  }
  for (int i = n - k; i < n; ++i) {
    std::string str(n, '.');
    str.replace(n - k, k, ans[k - 4][i + k - n]);
    std::cout << str << '\n';
  }
  return 0;
}

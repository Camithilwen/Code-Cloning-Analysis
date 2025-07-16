#include <bits/stdc++.h>

int solve() {
  int N, M; std::cin >> N >> M;
  std::vector<int> s(M);
  std::vector<int> c(M);
  for (int i = 0; i < M; ++i) std::cin >> s[i] >> c[i];

  /* 全探索 */
  for (int n = 0; n < std::pow(10,N); ++n) {
    int digit = 1;      // 0は1桁
    std::vector<int> each_num(1, n%10); // 一の位
    int x = n/10;

    while (x) {
      digit++;
      each_num.push_back(x%10);
      x /= 10;
    }

    if (digit != N) continue; // 桁数の条件を満たさない

    std::reverse(each_num.begin(), each_num.end());

    bool ok = true; // 条件を満たす整数が存在するかどうか
    
    for (int i = 0; i < M; ++i)
      if (each_num[s[i]-1] != c[i]) ok = false; // 一つでも条件を満たさないものがあれば

    if (ok) return n; // 桁数とそれぞれの桁の数字が条件を満たす
  }
  
  return -1;
  
}

int main() {
  std::cout << solve() << std::endl;

  return 0;
}

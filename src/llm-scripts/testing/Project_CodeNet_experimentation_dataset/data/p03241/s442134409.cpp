/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, M;
  cin >> N >> M;
  for (int64_t g = M / N; g >= 1; --g) {
    if (M % g == 0 && M / g >= N) {
      cout << g << endl;
      return 0;
    }
  }
  cout << 1 << endl;
  return 0;
}

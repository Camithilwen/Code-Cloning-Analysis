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
  int64_t result = 1;
  for (int64_t d = 1; d * d <= M; ++d) {
    if (M % d == 0 && M / d >= N) {
      result = max(result, d);
    }
    if (M % d == 0 && d >= N) {
      result = max(result, M / d);
    }
  }
  cout << result << endl;
  return 0;
}

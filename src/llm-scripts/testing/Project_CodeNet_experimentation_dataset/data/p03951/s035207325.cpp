/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  string s, t;
  cin >> N >> s >> t;
  int64_t overwrap = 0;
  for (int64_t ov = 1; ov <= N; ++ov) {
    if (s.substr(N - ov, ov) == t.substr(0, ov)) {
      overwrap = ov;
    }
  }
  // const int64_t L = static_cast<int64_t>(T.length());
  cout << (N * 2 - overwrap) << endl;
  return 0;
}

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

  int64_t K, T;
  cin >> K >> T;
  vector<int64_t> A(T);
  for (int64_t i = 0; i < T; ++i) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  cout << max(A[0] - (K - A[0] + 1), 0L) << endl;

  return 0;
}

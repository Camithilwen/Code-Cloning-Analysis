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

  int64_t N;
  cin >> N;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<int64_t> A(N + 1, 0);
  for (int64_t i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  vector<int64_t> result;
  vector<int64_t> B(N + 1, 0);
  for (int64_t i = N; i >= 1; --i) {
    int64_t temp = 0;
    for (int64_t j = 2 * i; j <= N; j += i) {
      temp += B[j];
      temp %= 2;
    }
    if (temp != A[i]) {
      B[i] = 1;
      result.emplace_back(i);
    }
  }
  cout << result.size() << endl;
  for (int64_t i = 0; i < static_cast<int64_t>(result.size()); ++i) {
    if (i != 0) {
      cout << " " << endl;
    }
    cout << result[i];
  }
  cout << endl;
  return 0;
}

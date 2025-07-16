#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                           \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
  cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string N;
  cin >> N;
  int n = N.length();
  long long dp[n + 1][2];
  dp[n][0] = 0;
  dp[n][1] = 0;
  for (int i = n - 1; i >= 0; i--) {
    dp[i][0] = INT_MAX;
    dp[i][1] = INT_MAX;
    int dig = N[i] - '0';
    for (int j = 0; j < 10 - dig; j++) {
      dp[i][0] = min(dp[i][0], dp[i + 1][0] + j + j + dig);
    }
    for (int j = 0; j + 1 < 10 - dig; j++) {
      dp[i][0] = min(dp[i][0], dp[i + 1][1] + j + j + dig + 1);
    }
    for (int j = 10 - dig; j < 10; j++) {
      dp[i][1] = min(dp[i][1], dp[i + 1][0] + j + (j + dig) % 10);
    }
    if (i < n - 1)
      for (int j = 9 - dig; j < 10; j++) {
        dp[i][1] = min(dp[i][1], dp[i + 1][1] + j + (j + dig + 1) % 10);
      }
  }
  long long ans = min(dp[0][0], dp[0][1] + 1);
  cout << ans << endl;
  return 0;
}

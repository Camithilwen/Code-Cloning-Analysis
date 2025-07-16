#include <bits/stdc++.h>
using namespace std;

string s, rs;
int n, k;
vector<vector<vector<int>>> dp;

int solve();

int main() {
  cin >> s >> k;
  n = s.size();
  rs = s;
  reverse(rs.begin(), rs.end());
  cout << solve() << endl;
  return 0;
}

int solve() {
  int res = 0;
  dp.assign(n + 1, vector(n + 1, vector<int>(k + 1, 0)));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int l = 0; l <= k; ++l) {
        dp[i + 1][j + 1][l] = max(dp[i + 1][j][l], dp[i][j + 1][l]);
        if (s[i] == rs[j])
          dp[i + 1][j + 1][l] = max(dp[i + 1][j + 1][l], dp[i][j][l] + 1);
        else if (l != 0)
          dp[i + 1][j + 1][l] = max(dp[i + 1][j + 1][l], dp[i][j][l - 1] + 1);
        else
          dp[i + 1][j + 1][l] = max(dp[i + 1][j + 1][l], dp[i][j][l]);
      }
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      for (int l = 1; l <= k; ++l)
        dp[i][j][l] = max(dp[i][j][l], dp[i][j][l - 1]);
  for (int i = 0; i <= n; ++i) {
    // even
    res = max(res, dp[i][n - i][k] * 2);
    // odd
    if (i > 0) res = max(res, dp[i - 1][n - i][k] * 2 + 1);
  }
  return res;
}
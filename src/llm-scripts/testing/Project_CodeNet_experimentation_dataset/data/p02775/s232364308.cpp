#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

// i桁目まで見て j枚多く払う時(0 or 1)
ll dp[1000100][2];

int main() {
  string s;
  cin >> s;

  s = '0' + s;
  int n = (int)s.size();
  memset(dp, 0, sizeof(dp));
  dp[0][1] = 1;

  for (int i = 1; i < n; i++) {
    int current = s[i] - '0';
    dp[i][0] = min(dp[i - 1][0] + current, dp[i - 1][1] + (10 - current));
    dp[i][1] = min(dp[i - 1][0] + current + 1, dp[i - 1][1] + (9 - current));
  }
  cout << dp[n - 1][0] << '\n';
}
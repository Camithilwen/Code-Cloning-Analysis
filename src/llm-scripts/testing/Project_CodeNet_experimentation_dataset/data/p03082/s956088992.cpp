#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const int N = 205, X = 1e5+10;

int n, x;
int s[N];
int dp[2][X]; // dp[i][j] = # of ways to end with j, last mod i

void add(int& a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  sort(s, s + n, greater<int>());
  dp[0][x] = 1;
  for (int i = 0; i < n; i++) {
    memset(dp[1], 0, sizeof dp[1]);
    // take self
    for (int j = 0; j <= x; j++) {
      add(dp[1][j%s[i]], dp[0][j]);
    }
    // don't take self
    for (int j = 0; j <= x; j++) {
      add(dp[1][j], (ll) dp[0][j] * (n - i - 1) % MOD);
    }
    swap(dp[0], dp[1]);
  }
  int ans = 0;
  for (int i = 0; i < s[n-1]; i++) {
    add(ans, (ll) i * dp[0][i] % MOD);
  }
  cout << ans << nl;
  return 0;
}

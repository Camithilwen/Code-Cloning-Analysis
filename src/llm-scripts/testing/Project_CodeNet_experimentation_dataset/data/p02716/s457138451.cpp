#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n;
  cin >> n;
  vl a(n);
  rep(i, n) cin >> a[i];
  ll m = n % 2 + 1;
  ll dp[n + 1][m + 1][2] = {};
  rep(i, n + 1) rep(j, m + 1) rep(k, 2) dp[i][j][k] = -1e18;
  dp[0][0][0] = 0;
  rep(i, n) rep(j, m + 1) rep(k, 2) {
    if(k == 1)
      dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][k]);
    else {
      if(j != 0 || i != n - 1)
        dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][k] + a[i]);
      if(j < m) dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][k]);
    }
  }
  ll ans = -1e18;
  rep(j, m + 1) rep(k, 2) ans = max(ans, dp[n][j][k]);
  cout << ans << endl;
}
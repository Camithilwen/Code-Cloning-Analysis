#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x) for (auto&& v : (x))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))

ll dp[3010][3010];
pair<ll, ll> a[3010];
int main() {
  ll n, t;
  cin >> n >> t;
  rep(i, n) cin >> a[i].first >> a[i].second;
  sort(a, a + n);
  rep(i, n) {
    rep(j, t) {
      updatemax(dp[i + 1][j], dp[i][j]);
      updatemax(dp[i + 1][min(j + a[i].first, t)], dp[i][j] + a[i].second);
    }
    updatemax(dp[i + 1][t], dp[i][t]);
  }
  cout << dp[n][t] << endl;
}

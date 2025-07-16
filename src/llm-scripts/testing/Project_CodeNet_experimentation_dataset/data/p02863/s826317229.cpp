#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, t;
  cin >> n >> t;
  vector<P> v(n);
  rep(i, 0, n) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());

  vector<vector<int>> dp(n + 1, vector<int>(3001, 0));
  int ans = 0;
  rep(i, 0, n) {
    rep(j, 0, t) {
      chmax(dp[i + 1][j], dp[i][j]);
      if (j + v[i].first < t)
        chmax(dp[i + 1][j + v[i].first], dp[i][j] + v[i].second);
    }
    int now = dp[i][t - 1] + v[i].second;
    chmax(ans, now);
  }

  cout << ans << endl;
}

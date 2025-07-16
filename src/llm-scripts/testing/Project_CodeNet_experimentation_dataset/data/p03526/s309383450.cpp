#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int nax = 5010;
const ll INF = 1e18L;
ll dp[nax][nax];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  for (int i = 0; i < nax; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;

  int n;
  cin >> n;
  vector<pair<int, int>> q(n);
  for (int i = 0; i < n; ++i) {
    cin >> q[i].first >> q[i].second;
    q[i].first += q[i].second;
  }
  sort(q.begin(), q.end());
  for (int i = 0; i < n; ++i) {
    q[i].first -= q[i].second;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (dp[i][j] == INF) continue;
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      if (dp[i][j] <= q[i].first) {
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + q[i].second);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (dp[n][i] != INF) {
      ans = i;
    }
  }
  cout << ans << '\n';
}
#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  int N;
  cin >> N;

  const int64_t INF = 1'000'000'000L * 200'000 + 1;
  vector<vector<int64_t>> dp(N + 2, vector<int64_t>(3, -INF));
  dp[0][0] = 0;
  rep(i, N) {
    int a;
    cin >> a;
    irep(j, 2) {
      dp[i + 2][j] = dp[i][j] + a;
      rep(k, j) {
        if (i - (j - k) >= 0) {
          dp[i + 2][j] = max(dp[i + 2][j], dp[i - (j - k)][k] + a);
        }
      }
      dp[i + 2][j] = max(dp[i + 2][j], -INF);
    }
  }

  /*rep(i, N + 2) {
    rep(j, 3) { cerr << " " << dp[i][j]; }
    cerr << "\n";
  }*/

  if (N % 2 == 0) {
    cout << max(dp[N + 1][1], dp[N][0]) << endl;
  } else {
    cout << max(dp[N + 1][2], max(dp[N][1], dp[N - 1][0])) << endl;
  }
  return 0;
}
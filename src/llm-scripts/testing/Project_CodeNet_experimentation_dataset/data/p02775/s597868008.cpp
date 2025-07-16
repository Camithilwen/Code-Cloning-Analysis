#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

void solve();

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

int dp[10000000+1][2];

void solve() {
  string S; cin >> S;

  reverse(S.begin(), S.end());

  dp[0][0] = S[0] - '0';
  dp[0][1] = 10 - (S[0] - '0');

  for (int i = 1; i < S.size(); i++) {
    int s = S[i] - '0';
    if (0 < s && s < 9) {
      dp[i][0] = min(dp[i-1][0] + s, dp[i-1][1] + s + 1);
      dp[i][1] = min(dp[i-1][0] + (10 - s), dp[i-1][1] + (10 - (s + 1)));
    } else if (s == 0) {
      dp[i][0] = min(dp[i-1][0], dp[i-1][1] + 1);
      dp[i][1] = dp[i-1][1] + 9;
    } else if (s == 9) {
      dp[i][0] = dp[i-1][0] + 9;
      dp[i][1] = min(dp[i-1][0] + 1, dp[i-1][1]);
    }
  }

  cout << min(dp[S.size()-1][0], dp[S.size()-1][1]+1) << endl;
}
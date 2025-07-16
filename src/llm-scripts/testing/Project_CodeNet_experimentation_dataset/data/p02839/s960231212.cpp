#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int mod = 1e9+7;

int dp[88][88][14000];

int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));
  rep(i,h) rep(j,w) cin >> a[i][j];
  rep(i,h) rep(j,w) cin >> b[i][j];

  dp[0][0][7000 + (a[0][0] - b[0][0])] = 1; 
  dp[0][0][7000 + (b[0][0] - a[0][0])] = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      for (int k = 200; k <= 13000; k++) {
        if (i > 0) {
          dp[i][j][k + (a[i][j] - b[i][j])] |= dp[i - 1][j][k];
          dp[i][j][k + (b[i][j] - a[i][j])] |= dp[i - 1][j][k];
        }
        if (j > 0) {
          dp[i][j][k + (a[i][j] - b[i][j])] |= dp[i][j - 1][k]; 
          dp[i][j][k + (b[i][j] - a[i][j])] |= dp[i][j - 1][k];
        }
      }
    }
  }

  int res = 2e9;
  for (int k = 0; k < 14000; k++) {
    if (!dp[h - 1][w - 1][k]) continue;
    res = min(res, abs(7000 - k));
  }
  cout << res << endl;
  return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;cin >> n >> m;
  vector<int> a(m);
  rep(i,m) cin >> a[i];
  vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
  sort(a.begin(), a.end());
  vector<int> b = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  dp[0][0] = 0;
  rep1(i,m) {
    rep(j,n+1) {
      if(j - b[a[i-1]] >= 0) {
	if(dp[i][j - b[a[i-1]]] != -1) {
	  dp[i][j] = max(dp[i][j - b[a[i-1]]] + 1, dp[i-1][j]);
	}
	else dp[i][j] = dp[i-1][j];
      }
      else dp[i][j] = dp[i-1][j];
    }
  }

  // rep(i,m+1) {
  //   rep(j,n+1) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  int x = m, y = n;
  while(y > 0 ) {
    if(y - b[a[x-1]] >= 0) {
      if( dp[x][y] - 1 == dp[x][y - b[a[x-1]]] ) {
	cout << a[x-1];
	y -= b[a[x-1]];
      }
      else x--;
    }
    else x--;
  }
  cout << "\n";
  return 0;
}

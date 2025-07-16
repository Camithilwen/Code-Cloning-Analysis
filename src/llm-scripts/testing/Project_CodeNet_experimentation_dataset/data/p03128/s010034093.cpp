#include <bits/stdc++.h>
using namespace std;

const int match[10] = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
const int INF = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  int a[m];
  for ( int i = 0; i < m; i++ ) { cin >> a[i]; }
  sort(a, a+m, greater<int>());


  int dp[n+1];
  dp[0] = 0;
  for ( int i = 1; i <= n; i++ ) {
    dp[i] = -INF;
    for ( int j = 0; j < m; j++ ) {
      if ( i-match[a[j]] < 0 ) { continue; }
      if ( dp[i-match[a[j]]] < 0 ) { continue; }
      dp[i] = max(dp[i-match[a[j]]]+1, dp[i]);
    }
  }

  while ( n > 0 ) {
    for ( int i = 0; i < m; i++ ) {
      if ( n-match[a[i]] < 0 ) { continue; }
      if ( dp[n-match[a[i]]] == dp[n]-1 ) {
        cout << a[i];
        n -= match[a[i]];
        break;
      }
    }
  }
  cout << endl;
  return 0;
}

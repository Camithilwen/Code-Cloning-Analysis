#include <bits/stdc++.h>
using namespace std;

#define name ""
#define ini freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
#define foe(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define long long long 
#define db double 
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1e9+7;
const int MOD = 1e9+7;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

const int N = 1e6+2;
string s;
int n, dp[N][2], ssum[N];

int main()
{
  fastio;
  cin >> s; reverse(all(s)); 
  int n = s.size(); s = '#' + s;
  for (int i = n; i > 0; i--) ssum[i] = ssum[i + 1] + (9 - (s[i] - '0'));
  dp[0][0] = dp[0][1] = 0;
  int mn = ssum[1];
  for (int i = 1; i <= n; i++){
    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + (s[i] - '0');
    dp[i][1] = mn - ssum[i + 1] + 2;
    mn = min(mn, dp[i][0] + ssum[i + 1]);
    mn = min(mn, dp[i][1] + ssum[i + 1]);
  }
  cout << min(dp[n][0], dp[n][1]); 
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int toInt(char c) {
  return c-'0';
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s; cin >> s;
  reverse(all(s));
  int n = s.size();
  vector<vector<ll>> dp(n+1, vector<ll>(2, longinf));
  dp[0][0] = 0;
  rep(i, n) {
    if(toInt(s[i]) == 9) {
      dp[i+1][0] = min({dp[i][0]+toInt(s[i])});
      dp[i+1][1] = min({dp[i][0]+10-toInt(s[i]), dp[i][1]+10-(toInt(s[i])+1), dp[i][1]+1});
    } else {
      dp[i+1][0] = min({dp[i][0]+toInt(s[i]), dp[i][1]+toInt(s[i])+1});
      dp[i+1][1] = min({dp[i][0]+10-toInt(s[i]), dp[i][1]+10-(toInt(s[i])+1)});
    }
  }
  cout << min(dp[n][0], dp[n][1]+1) << "\n";
  return 0;
}

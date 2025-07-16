#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  vector<vector<vector<ll>>>
    dp(N+1, vector<vector<ll>>(2, vector<ll>(3, -longinf))); // index, select(1) or not(0), not select count
  dp[0][0][0] = 0;
  rep(i, N) {
    rep(k, 3) { // select
      dp[i+1][1][k] = max(dp[i][0][k]+A[i], dp[i+1][1][k]);
    }
    if(i) { // not select
      rep(k, 3) { // selected previous index
        dp[i+1][0][k] = max(dp[i][1][k], dp[i+1][0][k]);
      }
      rep(k, 2) { // not selected previous index
        dp[i+1][0][k+1] = max(dp[i][0][k], dp[i+1][0][k+1]);
      }
    } else {
      dp[i+1][0][1] = 0;
    }
  }

  ll ans = -longinf;
  if(N%2) ans = max(dp[N][1][2], dp[N][0][1]);
  else ans = max(dp[N][1][1], dp[N][0][0]);
  cout << ans << endl;
  return 0;
}

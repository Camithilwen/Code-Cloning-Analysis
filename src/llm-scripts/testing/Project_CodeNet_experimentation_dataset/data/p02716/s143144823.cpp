#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = int_fast64_t;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  int n; cin>>n;
  const ll INF = 1e18;
  vector<ll> A(n);
  rep(i,n) cin>>A[i];
  vector<vll> dp(n+1, vll(5, -INF));
  dp[0][0] = 0;
  int k = n%2+1;
  rep(i,n) repc(j,k) {
    chmax(dp[i+1][j+1], dp[i][j]);
    if((i+j)%2==0) chmax(dp[i+1][j], dp[i][j] + A[i]);
    else chmax(dp[i+1][j], dp[i][j]);
  }
  cout << dp[n][k] << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}
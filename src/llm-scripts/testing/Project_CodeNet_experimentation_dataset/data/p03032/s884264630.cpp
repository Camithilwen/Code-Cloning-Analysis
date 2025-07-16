// 2020-07-15 23:13:36
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
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

vector<int> vs;
int dp[55][55][105];
int rec(int l, int r, int k) {
  if(dp[l][r][k] >= 0) return dp[l][r][k];
  chmax(dp[l][r][k], 0);
  if(l == r) return dp[l][r][k];
  if(k >= 1) {
    chmax(dp[l][r][k], rec(l+1, r, k-1) + vs[l]);
    chmax(dp[l][r][k], rec(l, r-1, k-1) + vs[r-1]);
  }
  if(k >= 2) {
    chmax(dp[l][r][k], rec(l+1, r, k-2));
    chmax(dp[l][r][k], rec(l, r-1, k-2));
  }
  return dp[l][r][k];
}
void answer() {
  int n, k;
  cin >> n >> k;
  vs.resize(n);
  rep(i, n) cin >> vs[i];
  repc(i, n) repc(j, n) repc(ki, k) dp[i][j][ki] = -1;
  cout << rec(0, n, k) << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}
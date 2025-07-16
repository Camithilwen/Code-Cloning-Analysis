// 2020-07-04 23:45:06
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

int dp[105][55][55], v[55];
int rec(int k, int l, int r) {
  if(dp[k][l][r] >= 0) return dp[k][l][r];
  chmax(dp[k][l][r], 0);
  if(k == 0) return dp[k][l][r];
  if(l == r) return dp[k][l][r];
  chmax(dp[k][l][r], rec(k-1, l+1, r) + v[l]);
  chmax(dp[k][l][r], rec(k-1, l, r-1) + v[r-1]);
  if(k >= 2) {
    if(v[l] < 0) chmax(dp[k][l][r], rec(k-2, l+1, r));
    if(v[r-1] < 0) chmax(dp[k][l][r], rec(k-2, l, r-1));
  }
  return dp[k][l][r];
}
void answer() {
  int n, k;
  cin >> n >> k;
  repc(ki, k) repc(li, n) repc(ri, n) dp[ki][li][ri] = -1;
  rep(i, n) cin >> v[i];
  cout << max(0, rec(k, 0, n)) << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}
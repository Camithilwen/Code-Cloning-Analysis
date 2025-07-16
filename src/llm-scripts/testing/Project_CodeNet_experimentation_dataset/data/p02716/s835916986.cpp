// 2020-07-18 10:56:41
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

const ll INF = 1e18;
void answer() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  int k = n%2+1;
  vector<ll> dp(k+1, -INF);
  dp[0] = 0;
  rep(i, n) {
    vector<ll> p(k+1, -INF);
    swap(p, dp);
    repc(j, k) {
      if(j<k) chmax(dp[j+1], p[j]);
      if((i+j)%2) {
        chmax(dp[j], p[j]);
      } else {
        chmax(dp[j], p[j] + a[i]);
      }
    }
  }
  cout << dp[k] << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}

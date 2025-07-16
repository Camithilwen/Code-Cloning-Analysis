#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) \
  for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) \
  for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
#define ALL(v) v.begin(), v.end()
//#define endl "\n"
#define ciosup \
  cin.tie(0);  \
  ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e15 + 7LL;
constexpr ll MOD = 1e9 + 7LL;
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (int i = 0; i < v.size(); ++i) {
    is >> v[i];
  }
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < v.size() - 1; ++i) {
    os << v[i] << " ";
  }
  if (v.size() > 0) {
    os << v[v.size() - 1] << endl;
  }
  return os;
}

int main() {
  int n,t;
  cin >> n >> t;
  vint a(n), b(n);
  REP(i, n) { cin >> a[i] >> b[i]; }
  vector<vll> dp(n + 1, vll(6000 + 1, 0)), dp2(n + 1, vll(6000 + 1, 0));
  //REP(i, n + 1) { REP(j,6000) {dp[i][j] = 0;} }
  REP(i,n){
    REP(j,6000){
      if (dp[i][j] != -1) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        if (j + a[i]<= 6000) dp[i + 1][j + a[i]] = max(dp[i + 1][j + a[i]], dp[i][j] + b[i]);
      }
      if (j > 0) dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - 1]);
    }
  }
  //REP(i, n + 1) { dp2[i][0] = 0; }
  IREP(i, n) {
    REP(j, 6000) {
      if (dp2[i][j] != -1) {
        dp2[i][j] = max(dp2[i][j], dp2[i + 1][j]);
        if (j + a[i] <= 6000)
          dp2[i][j + a[i]] = max(dp2[i][j + a[i]], dp2[i + 1][j] + b[i]);
      }
      if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
    }
  }
  ll ans = 0;
  REP(i,n){
    REP(j, t) { ans = max(ans, b[i] + dp[i][j] + dp2[i+1][t - 1 - j]); }
  }
  cout << ans << endl;
}
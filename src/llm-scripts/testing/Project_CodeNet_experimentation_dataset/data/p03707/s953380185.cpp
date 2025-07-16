#pragma region template
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vld = vector<ld>;
using vvld = vector<vld>;
using vvvld = vector<vvld>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template <typename T>
using pqrev = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, n) for (ll i = 0, i##_end = (n); i < i##_end; i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for (ll i = (a), i##_end = (b); i < i##_end; i++)
#define reprb(i, a, b) for (ll i = (b)-1, i##_end = (a); i >= i##_end; i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
//*
constexpr ll MOD = 1e9 + 7;
/*/
constexpr ll MOD = 998244353;
//*/
constexpr ll INF = 1e+18;
constexpr ld EPS = 1e-12L;
constexpr ld PI = 3.14159265358979323846L;
constexpr ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
constexpr ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
template <typename S, typename T>
constexpr bool chmax(S &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename S, typename T>
constexpr bool chmin(S &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif
template <typename T>
bool print_(const T &a) {
  cout << a;
  return true;
}
template <typename T>
bool print_(const vector<T> &vec) {
  for (auto &a : vec) {
    cout << a;
    if (&a != &vec.back()) {
      cout << " ";
    }
  }
  return false;
}
template <typename T>
bool print_(const vector<vector<T>> &vv) {
  for (auto &v : vv) {
    for (auto &a : v) {
      cout << a;
      if (&a != &v.back()) {
        cout << " ";
      }
    }
    if (&v != &vv.back()) {
      cout << "\n";
    }
  }
  return false;
}
void print() { cout << "\n"; }
template <typename Head, typename... Tail>
void print(Head &&head, Tail &&... tail) {
  bool f = print_(head);
  if (sizeof...(tail) != 0) {
    cout << (f ? " " : "\n");
  }
  print(forward<Tail>(tail)...);
}
#pragma endregion



int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m, q;
  cin >> n >> m >> q;
  vs s(n);
  rep(i, n){
    cin >> s[i];
  }
  vvi v(n+1, vi(m+1, 0));
  vvi ev(n, vi(m+1, 0));
  vvi eh(n+1, vi(m, 0));
  rep(i, n)rep(j, m){
    v[i+1][j+1] = s[i][j]-'0';
  }
  rep(i, n+1)rep(j, m){
    v[i][j+1] += v[i][j];
  }
  rep(i, n)rep(j, m+1){
    v[i+1][j] += v[i][j];
  }
  rep(i, n-1)rep(j, m){
    ev[i+1][j+1] = (s[i][j] == '1' && s[i+1][j] == '1');
  }
  rep(i, n)rep(j, m){
    ev[i][j+1] += ev[i][j];
  }
  rep(i, n-1)rep(j, m+1){
    ev[i+1][j] += ev[i][j];
  }
  rep(i, n)rep(j, m-1){
    eh[i+1][j+1] = (s[i][j] == '1' && s[i][j+1] == '1');
  }
  rep(i, n+1)rep(j, m-1){
    eh[i][j+1] += eh[i][j];
  }
  rep(i, n)rep(j, m){
    eh[i+1][j] += eh[i][j];
  }
  while(q--){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = v[c][d]-v[a-1][d]-v[c][b-1]+v[a-1][b-1];
    ans -= ev[c-1][d]-ev[a-1][d]-ev[c-1][b-1]+ev[a-1][b-1];
    ans -= eh[c][d-1]-eh[a-1][d-1]-eh[c][b-1]+eh[a-1][b-1];
    print(ans);
  }
}

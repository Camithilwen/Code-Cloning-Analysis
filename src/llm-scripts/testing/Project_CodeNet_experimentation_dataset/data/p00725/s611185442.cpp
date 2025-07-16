// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979;
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
bool odd(const int &n) { return n & 1; }
bool even(const int &n) { return ~n & 1; }
template<typename T = int> T in() { T x; cin >> x; return x; }
template<typename T = int> T in(T &&x) { T z(forward<T>(x)); cin >> z; return z; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &x : v) is >> x; return is; }
template<typename A, typename B> istream &operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second; }
template<typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v) { int n = v.size(); rep(i, n) os << v[i] << (i == n - 1 ? "" : "\n"); return os; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { int n = v.size(); rep(i, n) os << v[i] << (i == n - 1 ? "" : " "); return os; }
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << p.first << ' ' << p.second; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
// clang-format on

int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};

main {
  while (true) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    auto a = vectors(h, w, 0LL);
    cin >> a;
    int si, sj;
    rep(i, h) rep(j, w) if (a[i][j] == 2) si = i, sj = j;
    function<int(int, int, int)> dfs = [&](int i, int j, int c) {
      if (c == 10) return INF;
      int mini = INF;
      rep(k, 4) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || nj < 0 || ni >= h || nj >= w || a[ni][nj] == 1) continue;
        while (0 <= ni && ni < h && 0 <= nj && nj < w) {
          if (a[ni][nj] == 3) {
            cmin(mini, c + 1);
            break;
          }
          if (a[ni][nj] == 1) {
            a[ni][nj] = 0;
            cmin(mini, dfs(ni - di[k], nj - dj[k], c + 1));
            a[ni][nj] = 1;
            break;
          }
          ni += di[k], nj += dj[k];
        }
      }
      return mini;
    };
    int ans = dfs(si, sj, 0);
    cout << (ans == INF ? -1 : ans) << endl;
  }
}


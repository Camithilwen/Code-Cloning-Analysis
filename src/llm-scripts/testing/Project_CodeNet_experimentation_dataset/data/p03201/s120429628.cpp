#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define all(a) (a).begin(), (a).end()
#define bit32(x) (1 << (x))
#define bit64(x) (1ll << (x))
#define sz(v) ((int) v.size())
using namespace std;
using i64 = long long;
using f80 = long double;
using vi32 = vector<int>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> void chmax(T &x, T y) { x = max(x, y); }
template <typename T> void chmin(T &x, T y) { x = min(x, y); }
template <typename T> T power(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
template <typename T, typename U> vector<U> make_vector(T&& n, U&& val) { return vector<U>(forward<T>(n), forward<U>(val)); }
template <typename T, typename... Args> decltype(auto) make_vector(T&& n, Args&&... args) { return vector<decltype(make_vector(forward<Args>(args)...))>(forward<T>(n), make_vector(forward<Args>(args)...)); }
const int INF = 1001001001;
const i64 LINF = 1001001001001001001ll;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
#endif

void solve() {
  int n;
  cin >> n;
  vi32 a(n);
  cin >> a;
  sort(a.rbegin(), a.rend());
  map<int, int> cnt;
  rep(i, n) cnt[a[i]]++;
  int ans = 0;
  rep(i, n) {
    if (cnt[a[i]] == 0) continue;
    cnt[a[i]]--;
    int m = 1;
    while (a[i] >= m) m <<= 1;
    int b = m - a[i];
    if (cnt[b] == 0) continue;
    cnt[b]--;
    ans += 1;
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(16);
  cerr << fixed << setprecision(16);
  solve();
  return 0;
}
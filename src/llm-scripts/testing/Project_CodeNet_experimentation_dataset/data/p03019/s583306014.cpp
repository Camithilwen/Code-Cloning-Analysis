#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define each(x, y) for (auto &x : y)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ll << (b))
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define rsort(v) sort(all(v)); reverse(all(v))

using namespace std;

using i32 = int;
using i64 = long long;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

inline void yes() { cout << "Yes" << '\n'; exit(0); }
inline void no() { cout << "No" << '\n'; exit(0); }
inline i64 gcd(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); if (a % b == 0) return b; return gcd(b, a % b); }
inline i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }
template<typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template<typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template<typename T> inline void amax(T &x, T y) { if (x < y) x = y; }
template<typename T> inline void amin(T &x, T y) { if (x > y) x = y; }
template<typename T> inline T power(T x, i64 n) { T r = 1; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }

void solve() {
  int N, X; cin >> N >> X;
  vi64 S(N);
  vector<tuple<i64, i64, i64>> t;
  i64 M = 0;
  i64 D = 0;
  i64 ok = 0, ng = -1;
  rep(i, N) {
    i64 b, l, u; cin >> b >> l >> u;
    t.push_back(make_tuple(b, l, u));
    S[i] = b * l + (X - b) * u;
    M += S[i];
    ok += b;
    D += -l * b;
  }
  vi32 ord(N);
  iota(all(ord), 0);
  sort(all(ord), [&](int i, int j) {
    return S[i] > S[j];
  });
  vi64 sums(N + 1);
  rep(i, N) sums[i + 1] = sums[i] + S[ord[i]]; 
  while (ok - ng > 1) {
    i64 k = (ok + ng) / 2;
    i64 ma = -1e18;
    i64 p = k / X, q = k - p * X;
    rep(i, N) {
      i64 MM;
      if (p > i) MM = sums[p + 1] - S[ord[i]];
      else MM = sums[p];
      i64 b, l, u;
      tie(b, l, u) = t[ord[i]];
      i64 T;
      if (q <= b) T = q * l;
      else T = b * l + (q - b) * u;
      amax(ma, MM + T);
    }
    if (ma + D >= 0) ok = k;
    else ng = k;
  }
  cout << ok << '\n';
}

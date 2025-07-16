#include <bits/stdc++.h>
#define BIT(n) (1LL << (n))
#define BITF(n, i) (((n) >> i) & 1)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPB(i, n) for (int i = 0; i < BIT(n); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORA(i, n) for (auto &&i : n)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define DEBUG(x) cerr << #x << ": " << x << "\n"
#define DEBUG2(x, y) cerr << #x << ": " << x << " " << #y << ": " << y << "\n"
#define DEBUG3(x, y, z) cerr << #x << ": " << x << " " << #y << ": " << y << " " << #z << ": " << z << "\n"
#define PRINTALL(V)    \
  for (auto v : (V)) { \
    cerr << v << " ";  \
  }                    \
  cerr << "\n";
#define ALL(v) v.begin(), v.end()
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define epb emplace_back
#define int long long
#define pint pair<int, int>
#define ld long double
using namespace std;
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> using vec = std::vector<T>;
template <class T> void print(const T &x) { cout << x << "\n"; }
template <class T> void print2(const T &x, const T &y) { cout << x << " " << y << "\n"; }
template <class T> void print3(const T &x, const T &y, const T &z) { cout << x << " " << y << " " << z << "\n"; }
const int MOD = 998244353, INF = 1061109567, INF2 = INF * INF;
const double EPS = 1e-10, PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int binpow(int a, int b, int mo) {
  int ans = 1;
  do {
    if (b & 1) ans = 1ll * ans * a % mo;
    a = 1ll * a * a % mo;
  } while (b >>= 1);
  return ans;
}
const int FACTSIZE = 100100;
int fact[FACTSIZE];
int revfact[FACTSIZE];

int ncr(int n, int r) {
  if (n < r) return 0;
  if (n < 0 || r < 0) return 0;
  int rs = fact[n] * revfact[r];
  if (rs >= MOD) rs %= MOD;
  rs *= revfact[n - r];
  if (rs >= MOD) rs %= MOD;
  return rs;
}
void init() {
  fact[0] = 1, revfact[0] = 1;
  for (int i = 1; i < FACTSIZE; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
    revfact[i] = binpow(fact[i], MOD - 2, MOD);
  }
}
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  init();
  int K, N;
  cin >> K >> N;
  vec<int> res(2 * K - 1, -1);
  FORS(i, 2, K + 1) {
    int ans = 0;
    if (i % 2 == 1) {
      int even = (i - 1) / 2;
      FORS(j, 0, even) {
        int val = N - j * 2;
        int tmp = ncr(even, j) * ncr(val + (K - 1), val);
        ans += j % 2 == 0 ? tmp : -tmp;
        ans %= MOD;
      }
      // DEBUG2(i, ans);
    } else {
      int even = i / 2 - 1;
      FORS(j, 0, even) {
        int val = N - 1 - j * 2;
        // DEBUG2(val, K - 2);
        int tmp = ncr(even, j) * ncr(val + (K - 2), val);
        ans += j % 2 == 0 ? tmp : -tmp;
        ans %= MOD;
      }
      FORS(j, 0, even) {
        int val = N - j * 2;
        int tmp = ncr(even, j) * ncr(val + (K - 2), val);
        ans += j % 2 == 0 ? tmp : -tmp;
        ans %= MOD;
      }
      //      int even = i / 2;
    }
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    res[i - 2] = ans;
    res[(2 * K - 2) - (i - 2)] = ans;
  }
  REP(i, 2 * K - 1) print(res[i]);
}
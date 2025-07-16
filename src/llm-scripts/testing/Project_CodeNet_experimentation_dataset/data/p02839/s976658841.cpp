#define MOD_TYPE 1

#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;
/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
*/
using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

constexpr ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
constexpr int INF = (int)1e9;
constexpr ll LINF = (ll)4e18;
constexpr ld PI = acos(-1.0);
constexpr ld EPS = 1e-11;
constexpr int Dx[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
constexpr int Dy[] = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";

inline void init_main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);
}
template <typename T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
inline ll CEIL(ll a, ll b)
{
  return (a + b - 1) / b;
}
#pragma endregion

int main()
{
  init_main();

  int h, w;
  cin >> h >> w;
  int a[80][80], b[80][80];
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(i, h) rep(j, w) cin >> b[i][j];

  bool dp[80][80][160 * 81] = {};
  const int add = 80 * 80;
  dp[0][0][a[0][0] - b[0][0] + add] = true;
  dp[0][0][b[0][0] - a[0][0] + add] = true;
  rep(i, h) rep(j, w)
  {
    rep(k, 160 * 80)
    {
      if (!dp[i][j][k])
        continue;
      if (i + 1 != h)
      {
        int kk = k + a[i + 1][j] - b[i + 1][j];
        if (0 <= kk && kk < 160 * 80)
          dp[i + 1][j][kk] = true;
        kk = k + b[i + 1][j] - a[i + 1][j];
        if (0 <= kk && kk < 160 * 80)
          dp[i + 1][j][kk] = true;
      }
      if (j + 1 != w)
      {
        int kk = k + a[i][j + 1] - b[i][j + 1];
        if (0 <= kk && kk < 160 * 80)
          dp[i][j + 1][kk] = true;
        kk = k + b[i][j + 1] - a[i][j + 1];
        if (0 <= kk && kk < 160 * 80)
          dp[i][j + 1][kk] = true;
      }
    }
  }

  int Min = INF;
  rep(k, 160 * 80)
  {
    if (!dp[h - 1][w - 1][k])
      continue;
    int val = abs(k - add);
    chmin(Min, val);
  }
  cout << Min << endl;
  return 0;
}

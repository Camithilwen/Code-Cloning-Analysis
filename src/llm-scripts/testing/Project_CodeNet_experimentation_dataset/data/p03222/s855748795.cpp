#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()
#define sortAl(v) sort(all(v))
#define sortAlr(v)          \
  sort(v.begin(), v.end()); \
  reverse(v.begin(), v.end())

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T &a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T &a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
#define INF LLONG_MAX

ll bridge_dp[9][2] = {};

void create_bridge_dp() {
  bridge_dp[0][0] = 1;
  bridge_dp[1][0] = 1;
  for (int i = 2; i <= 8; i++) {
    // 横線を引かない
    bridge_dp[i][0] = bridge_dp[i - 1][0] + bridge_dp[i - 1][1];
    // 横線を引けるのは左に横線がない場合
    bridge_dp[i][1] = bridge_dp[i - 1][0];
  }
}

ll way_bridge(ll n) {
  if (n <= 0) {
    return 1;
  }
  return bridge_dp[n][0] + bridge_dp[n][1];
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll h, w, k;
  cin >> h >> w >> k;

  create_bridge_dp();

  vvll dp(h + 1, vll(w + 2));
  dp[0][1] = 1;

  rep(y, h) {
    REP(x, w + 1) {
      dp[y + 1][x] = dp[y][x] * way_bridge(x - 1) * way_bridge(w - x);
      dp[y + 1][x] += dp[y][x - 1] * way_bridge(x - 2) * way_bridge(w - x);
      dp[y + 1][x] += dp[y][x + 1] * way_bridge(x - 1) * way_bridge(w - x - 1);
      dp[y + 1][x] %= mod;
    }
  }

  cout << dp[h][k] << endl;

  return 0;
}

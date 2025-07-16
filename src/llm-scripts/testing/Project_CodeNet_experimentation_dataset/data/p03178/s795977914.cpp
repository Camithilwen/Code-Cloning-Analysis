#include <bits/stdc++.h>

#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x
#define dump_1(x1) cerr << #x1 << ": " << x1 << endl
#define dump_2(x1, x2) \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << endl
#define dump_3(x1, x2, x3)                                                \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
       << x3 << endl
#define dump_4(x1, x2, x3, x4)                                            \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
       << x3 << ", " #x4 << ": " << x4 << endl
#define dump_5(x1, x2, x3, x4, x5)                                        \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
       << x3 << ", " #x4 << ": " << x4 << ", " #x5 << ": " << x5 << endl
#define dump(...) \
  CHOOSE((__VA_ARGS__, dump_5, dump_4, dump_3, dump_2, dump_1, ~))(__VA_ARGS__)
#define check(s) cerr << s << endl

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

using namespace std;

using ll = long long;

const long long MOD = 1000000007;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

const ll LINF = 2e18;
const int INF = 1e9;

void solve(std::string K, ll D) {
  ll N = K.size();
  vector<vector<vector<ll>>> dp(N + 1,
                                vector<vector<ll>>(2, vector<ll>(D + 1)));
  dp[0][0][0] = 1;
  FOR(i, 0, N) {
    ll k = K.at(i) - '0';
    FOR(j, 0, D) {
      FOR(dig, 0, 10) { (dp[i + 1][1][(j + dig) % D] += dp[i][1][j]) %= MOD; }
      FOR(dig, 0, k) { (dp[i + 1][1][(j + dig) % D] += dp[i][0][j]) %= MOD; }
      (dp[i + 1][0][(j + k) % D] += dp[i][0][j]) %= MOD;
    }
  }
  ll ans = (dp[N][0][0] + dp[N][1][0] - 1 + MOD) % MOD;
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  std::string K;
  std::cin >> K;
  ll D;
  cin >> D;
  solve(K, D);
  return 0;
}

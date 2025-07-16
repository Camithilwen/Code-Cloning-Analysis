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

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

const ll LINF = 2e18;
const int INF = 1e9;

ll N;
std::vector<ll> a;
vector<vector<vector<double>>> dp;

double f(ll c1, ll c2, ll c3) {
  if (dp[c1][c2][c3] != -1.0) return dp[c1][c2][c3];

  if (c1 == 0 && c2 == 0 && c3 == 0) return 0.0;

  double ret = 0.0;
  if (c1 > 0) ret += f(c1 - 1, c2, c3) * c1;
  if (c2 > 0) ret += f(c1 + 1, c2 - 1, c3) * c2;
  if (c3 > 0) ret += f(c1, c2 + 1, c3 - 1) * c3;
  ret += N;
  ret *= 1.0 / (c1 + c2 + c3);
  return dp[c1][c2][c3] = ret;
}

void solve() {
  dp.resize(310, vector<vector<double>>(310, vector<double>(310, -1.0)));

  ll c1 = 0, c2 = 0, c3 = 0;
  rep(i, N) {
    if (a.at(i) == 1) c1++;
    if (a.at(i) == 2) c2++;
    if (a.at(i) == 3) c3++;
  }
  cout << f(c1, c2, c3) << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  scanf("%lld", &N);
  a.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }
  solve();
  return 0;
}

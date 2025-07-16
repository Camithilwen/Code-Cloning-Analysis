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

using namespace std;

using ll = long long;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

const ll LINF = 2e18;
const int INF = 1e8;

int g(vector<pair<int, int>> a) {
  sort(all(a));
  int res = INF;
  int py = -INF * 2;
  for (int i = 1; i < sz(a); i++) {
    if (a.at(i - 1).second == 0 && a.at(i).second != 0) {
      res = min(res, a.at(i).first - a.at(i - 1).first);
    }
  }
  return res;
}

int f(map<int, vector<pair<int, int>>>& mp) {
  int res = INF;
  for (auto p : mp) {
    res = min(res, g(p.second));
  }
  return res;
}

void solve(ll N, std::vector<ll> X, std::vector<ll> Y, std::vector<char> U) {
  vector<ll> dir(N);  // URDL = 0123

  rep(i, N) {
    if (U.at(i) == 'U') dir.at(i) = 0;
    if (U.at(i) == 'R') dir.at(i) = 1;
    if (U.at(i) == 'D') dir.at(i) = 2;
    if (U.at(i) == 'L') dir.at(i) = 3;
  }

  int ans = INF;

  rep(ri, 4) {
    {  // UD
      map<int, vector<pair<int, int>>> mp;
      rep(i, N) {
        if (dir.at(i) != 0 && dir.at(i) != 2) continue;
        mp[X.at(i)].emplace_back(Y.at(i), dir.at(i));
      }
      ans = min(ans, f(mp) * 5);
    }
    {  // UR
      map<int, vector<pair<int, int>>> mp;
      rep(i, N) {
        if (dir.at(i) != 0 && dir.at(i) != 1) continue;
        mp[X.at(i) + Y.at(i)].emplace_back(Y.at(i), dir.at(i));
      }
      ans = min(ans, f(mp) * 10);
    }
    // rotate
    rep(i, N) {
      int px = X.at(i), py = Y.at(i);
      // 反時計に90度回転
      X.at(i) = py;
      Y.at(i) = -px;
      dir.at(i) = (dir.at(i) + 1) % 4;
    }
  }

  if (ans != INF) {
    cout << ans << endl;
  } else {
    cout << "SAFE" << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  ll N;
  cin >> N;
  std::vector<ll> X(N);
  std::vector<ll> Y(N);
  std::vector<char> U(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i);
    cin >> Y.at(i);
    cin >> U.at(i);
  }
  solve(N, std::move(X), std::move(Y), std::move(U));
  return 0;
}

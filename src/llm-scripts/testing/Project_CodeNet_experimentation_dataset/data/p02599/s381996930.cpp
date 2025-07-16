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

// Binary Indexed Tree (Fenwick Tree)
// https://youtu.be/lyHk98daDJo?t=7960
template <typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n = 0) : n(n), d(n + 1) {}
  void add(int i, T x = 1) {
    for (i++; i <= n; i += i & -i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i & -i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) { return sum(r - 1) - sum(l - 1); }
};

void solve(ll N, ll Q, std::vector<ll> c, std::vector<ll> l,
           std::vector<ll> r) {
  vector<int> pi(N + 1, -1);
  vector<vector<int>> ps(N);
  rep(i, N) {
    int l = pi.at(c.at(i));
    if (l != -1) ps.at(l).push_back(i);
    pi.at(c.at(i)) = i;
  }

  vector<vector<pair<int, int>>> qs(N);
  rep(i, Q) { qs.at(l.at(i)).emplace_back(r.at(i), i); }

  BIT<int> d(N);
  vector<int> ans(Q);

  for (int x = N - 1; x >= 0; --x) {
    for (int y : ps.at(x)) d.add(y, 1);
    for (auto query : qs.at(x)) {
      int r = query.first, i = query.second;
      ans.at(i) = (r - x + 1) - d.sum(r);
    }
  }

  rep(i, Q) { cout << ans.at(i) << endl; }

  return;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  ll N;
  scanf("%lld", &N);
  ll Q;
  scanf("%lld", &Q);
  std::vector<ll> c(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &c[i]);
  }
  std::vector<ll> l(Q);
  std::vector<ll> r(Q);
  for (int i = 0; i < Q; i++) {
    scanf("%lld", &l[i]);
    scanf("%lld", &r[i]);
    l[i]--;  // 0-indexed
    r[i]--;  // 0-indexed
  }
  solve(N, Q, std::move(c), std::move(l), std::move(r));
  return 0;
}

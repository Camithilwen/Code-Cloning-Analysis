#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 1000000000;
const long long int llINF = 1000000000000000000;

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

#define REP(i, n) for (ll i = 0; i < (n); i++)
#define RREP(i, n) for (ll i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define AUTO(i, m) for (auto &i : m)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end())
#define MIN(vec) *std::min_element(vec.begin(), vec.end())
#define ARGMAX(vec)                                                            \
  std::distance(vec.begin(), std::max_element(vec.begin(), vec.end()))
#define ARGMIN(vec)                                                            \
  std::distance(vec.begin(), std::min_element(vec.begin(), vec.end()))
#define REV(T) greater<T>()
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define VVL(a, b, c) vector<vector<ll>>(a, vector<ll>(b, c))
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))
#define SP(a) setprecision(a)
#define SQRT(a) sqrt((long double)(a))
#define DPOW(a, b) pow((long double)(a), (long double)(b))

ll POW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = POW(n, m / 2);
    return (tmp * tmp);
  } else {
    return (n * POW(n, m - 1));
  }
}

struct UnionFind {
  vector<ll> data;

  UnionFind(ll sz) { data.assign(sz, -1); }

  bool unite(ll x, ll y) {
    x = root(x), y = root(y);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  ll root(ll k) {
    if (data[k] < 0)
      return (k);
    return (data[k] = root(data[k]));
  }

  ll size(ll k) { return (-data[root(k)]); }

  ll same(ll a, ll b) { return root(a) == root(b); }
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct PO {
  ll ar;
  ll br;
  ll i;
};
bool pocomp(const PO &a, const PO &b) {
  if (a.ar == b.ar)
    return a.br < b.br;
  return a.ar < b.ar;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, K, L;
  cin >> N >> K >> L;
  auto uf1 = UnionFind(N);
  auto uf2 = UnionFind(N);
  vector<PO> P(N);
  REP(i, K) {
    ll p, q;
    cin >> p >> q;
    uf1.unite(p - 1, q - 1);
  }

  REP(i, L) {
    ll r, s;
    cin >> r >> s;
    uf2.unite(r - 1, s - 1);
  }

  REP(i, N) { P[i] = {uf1.root(i), uf2.root(i), i}; }
  sort(ALL(P), pocomp);
  vl ans(N);
  for (ll i = 0; i < N; i++) {
    ll j = i;
    while (j + 1 < N && P[j].ar == P[j + 1].ar && P[j].br == P[j + 1].br) {
      j++;
    }
    for (ll k = i; k <= j; k++) {
      ans[P[k].i] = j - i + 1;
    }
    i = j;
  }

  REP(i, N) { cout << ans[i] << " " << endl; }

  return 0;
}

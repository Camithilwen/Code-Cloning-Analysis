#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define pb push_back
#define COUT(x) cout << (x) << "\n"
#define COUTF(x) cout << setprecision(15) << (x) << "\n"
#define ENDL cout << "\n"
#define DF(x) x.erase(x.begin())
#define ALL(x) x.begin(), x.end()
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort(x.rbegin(), x.rend())
#define REVERSE(x) reverse(ALL(x))
#define MAX(x) *max_element(ALL(x))
#define MAXI(x) max_element(ALL(x)) - x.begin()
#define SUM(x) accumulate(ALL(x), 0ll)
#define COUNT(x, y) count(ALL(x), y);
#define ANS cout << ans << "\n"
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define Yes cout << "Yes\n";
#define No cout << "No\n";
#define YN YES else NO
#define yn Yes else No
#define init() \
  cin.tie(0);  \
  ios::sync_with_stdio(false)
#define LINE cerr << "[debug] line: " << __LINE__ << "\n";
#define debug(x) cerr << "[debug] " << #x << ": " << x << "\n";
#define debugV(v)                       \
  cerr << "[debugV] " << #v << ":";     \
  rep(z, v.size()) cerr << " " << v[z]; \
  cerr << "\n";
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using mll = map<ll, ll>;
using qll = queue<ll>;
using P = pair<ll, ll>;
using vp = vector<P>;
using vs = vector<string>;

template <typename T>
inline istream& operator>>(istream& i, vector<T>& v) {
  rep(j, v.size()) i >> v[j];
  return i;
}

template <typename T1, typename T2>
inline istream& operator>>(istream& i, pair<T1, T2>& v) {
  return i >> v.first >> v.second;
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ld PI = 3.141592653589793238462643383279;
ll get_digit(ll x) {
  return to_string(x).size();
}

ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

void rec(ll v, const vvll& G, vector<bool>& seen, vll& order) {
  seen[v] = true;
  for (auto next : G[v]) {
    if (seen[next]) continue;
    rec(next, G, seen, order);
  }
  order.push_back(v);
}

signed main() {
  init();
  ll N, M;
  cin >> N >> M;

  vvll G(N);
  vvll G2(N);
  rep(i, N + M - 1) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].pb(b);
    G2[b].pb(a);
  }

  vector<bool> seen(N, 0);
  vll order;
  rep(i, N) {
    if (seen[i]) continue;
    rec(i, G, seen, order);
  }
  REVERSE(order);

  vll order2(N);
  rep(i, N) order2[order[i]] = i;

  rep(i, N) {
    ll max_index = -1;
    ll ma = -1;
    for (auto gg : G2[i])
      if (ma < order2[gg]) {
        max_index = gg;
        ma = order2[gg];
      }

    COUT(max_index + 1);
  }

  return 0;
}
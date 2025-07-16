#include <bits/stdc++.h>
using namespace std;

// boost
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;
using vld = vector<ld>;
using vvld = vector<vld>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T& a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T& a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
// #define mod (998244353ll)

const long long INF = 1LL << 60;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n, q;
  string s;
  cin >> n >> s >> q;
  vll vq(q);
  rep(i, q) cin >> vq[i];

  vi d, m, c;
  d.reserve(1e6 + 10);
  m.reserve(1e6 + 10);
  c.reserve(1e6 + 10);

  rep(i, n) {
    if (s[i] == 'D')
      d.push_back(i);
    else if (s[i] == 'M')
      m.push_back(i);
    else if (s[i] == 'C')
      c.push_back(i);
  }

  vll nc(n + 2);

  rep(i, n) {
    if (s[i] == 'C')
      nc[i]++;
  }

  REP(i, n) {
    nc[i] += nc[i - 1];
  }

  for (const auto k : vq) {
    ll ans = 0;

    vll imos(n + 2);
    vll dc(n + 2);

    rep(i, n) {
      if (s[i] == 'D') {
        dc[i] = nc[min(i + k - 1, n - 1)] - nc[i];
        imos[i]++;
        if (i + k < n) {
          imos[i + k]--;
        }
      }
    }

    REP(i, n) {
      imos[i] += imos[i - 1];
    }

    REP(i, n) {
      dc[i] += dc[i - 1];
      if (s[i] == 'C') {
        dc[i] -= imos[i];
      } else if (s[i] == 'M') {
        ans += dc[i];
      }
    }

    cout << ans << endl;
  }

  return 0;
}

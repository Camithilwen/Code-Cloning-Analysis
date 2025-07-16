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

  ll n;
  cin >> n;

  multiset<ll> a;
  rep(i, n) {
    ll tmp;
    cin >> tmp;
    a.insert(tmp);
  }

  ll ans = 0;

  while (a.size() >= 2) {
    ll mx = *a.rbegin();
    ll p2 = 2;
    while (p2 <= mx)
      p2 *= 2;
    if (p2 == mx - p2) {
      a.erase(a.lower_bound(mx));
      auto itr = a.lower_bound(mx);
      if (itr != a.end()) {
        a.erase(itr);
        ans++;
      }
    } else {
      a.erase(a.lower_bound(mx));
      auto itr = a.lower_bound(p2 - mx);
      if (*itr == p2 - mx) {
        ans++;
        a.erase(itr);
      }
    }
  }

  cout << ans << endl;

  return 0;
}

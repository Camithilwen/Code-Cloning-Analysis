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
  vll v(n);
  rep(i, n) {
    cin >> v[i];
  }

  map<ll, ll> odd, even;
  rep(i, n) {
    if (i % 2 == 0) {
      odd[v[i]]++;
    } else {
      even[v[i]]++;
    }
  }

  ll k = n / 2;
  ll ans = 0;

  priority_queue<P> oq, eq;

  for (auto it : odd) {
    oq.emplace(it.second, it.first);
  }
  oq.emplace(0, -1);

  for (auto it : even) {
    eq.emplace(it.second, it.first);
  }
  eq.emplace(0, -1);

  if (oq.top().second != eq.top().second) {
    ans = n - (oq.top().first + eq.top().first);
  } else {
    ll ot, et;
    ot = oq.top().first;
    et = eq.top().first;
    oq.pop();
    eq.pop();
    ans = n - (ot + eq.top().first);
    chmin(ans, n - (et + oq.top().first));
  }

  cout << ans << endl;

  return 0;
}

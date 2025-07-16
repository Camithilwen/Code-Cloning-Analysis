#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> PLL;
#define chmax(x, y) do { x = max(x, y); } while(0)
#define chmin(x, y) do { x = min(x, y); } while(0)
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
template<typename T>
using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;

ll N, Q;
string s;

signed main() {
  cin >> N >> s >> Q;
  while (Q--) {
    ll k;
    cin >> k;
    vector<ll> d(N, 0), m(N, 0), dm(N, 0);
    // d, m, dm の構築
    if (s[0] == 'D') d[0] = 1;
    if (s[0] == 'M') m[0] = 1;
    for (int i = 1; i < N; i++) {
      d[i] = d[i-1];
      m[i] = m[i-1];
      dm[i] = dm[i-1];
      if (s[i] == 'D') {
        d[i] += 1;
      }
      if (s[i] == 'M') {
        m[i] += 1;
        dm[i] += d[i-1];
      }
    }
    ll ans = 0;
    // 集計
    for (int i = 2; i < N; i++) {
      if (s[i] != 'C') continue;
      ans += dm[i-1];
      if (i - k >= 0) {
        ans -= dm[i-k];
        ans -= d[i-k] * (m[i-1] - m[i-k]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}

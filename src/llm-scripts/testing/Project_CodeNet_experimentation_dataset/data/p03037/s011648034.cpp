#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define double long double
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> l(m), r(m);
  rep(i, m) cin >> l[i] >> r[i];
  ll a = LLONG_MIN, b = LLONG_MAX;
  rep(i, m) updatemax(a, l[i]);
  rep(i, m) updatemin(b, r[i]);
  cout << max(0ll, b - a + 1) << endl;
}

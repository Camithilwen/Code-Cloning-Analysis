#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  ll n, x;
  cin >> n >> x;
  V<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] + a[i] <= x) continue;
    ll diff = a[i - 1] + a[i] - x;
    ll eat = min(a[i], diff);
    ans += eat;
    a[i] -= eat;
  }
  if (a[0] > x) ans += a[0] - x;
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep2(i, i0, n) for (int i = i0; i < n; ++i)

// x^y % m
ll mpow(ll x, ll y, ll m = 998244353) {
  ll ret = 1;
  while (y != 0) {
    if (y & 1) ret = (ret * x) % m;
    x = (x * x) % m;
    y = y >> 1;
  }
  return ret;
};

ll minv(ll a, ll m = 998244353) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

int main() {
  const ll MOD = 998244353;
  ll n, m, k;
  cin >> n >> m >> k;
  if (m == 1) {
    cout << ((k == n - 1) ? 1 : 0) << endl;
    return 0;
  }

  ll ans = 0;
  ll fi = (m * mpow(m - 1, n - 1)) % MOD;
  ans = (ans + fi) % MOD;
  rep2(i, 1, k + 1) {
    fi = (fi * (n - i)) % MOD;
    fi = (fi * minv(i)) % MOD;
    fi = (fi * minv(m - 1)) % MOD;
    ans = (ans + fi) % MOD;
  }

  cout << ans << endl;
  return 0;
}
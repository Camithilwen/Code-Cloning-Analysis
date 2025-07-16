#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int mod = 1e9 + 7;

ll pwr (ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

ll inv (ll a) {
  return pwr (a, mod - 2);
}

ll nCr (ll n, ll r) {
  ll ans = 1;
  for (int i = 0; i < r; i++) ans = (ans * (n - i)) % mod;
  for (int i = 1; i <= r; i++) ans = (ans * inv (i)) % mod;

  return ans;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, m;
  ll k;
  cin >> n >> m >> k;

  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += (((ll)(m - i) * (m - i + 1)) / 2);
    ans %= mod;
  }
  ll a = (((ll)n * (n - 1)) + n) % mod;
  ans = (ans * a) % mod;
  ll tmp_ans = 0;
  for (int i = 1; i <= n; i++) {
    tmp_ans += (((ll)(n - i) * (n - i + 1)) / 2);
    tmp_ans %= mod;
  }
  ll b = (((ll)m * (m - 1)) + m) % mod;
  tmp_ans = (tmp_ans * b) % mod;

  ans = (ans + tmp_ans) % mod;

  ans = (ans * nCr ((ll)n * m - 2, k - 2)) % mod;

  cout << ans << '\n';
}

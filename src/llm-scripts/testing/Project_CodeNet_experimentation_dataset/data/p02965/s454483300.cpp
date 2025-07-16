#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

ll mod = 998244353;

const ll MAX = 3000000;
ll f[MAX], inv[MAX], finv[MAX];

void init() {
	inv[1] = 1;
	for (int i = 2; i < MAX; i++)
		inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
  f[0] = f[1] = finv[0] = finv[1] = 1;
  for (int i = 2; i < MAX; i++)
    f[i] = (f[i - 1] * i) % mod, finv[i] = (finv[i - 1] * inv[i]) % mod;
}

ll binom(ll n, ll k) {
  return (((f[n] * finv[n - k]) % mod) * finv[k]) % mod;
}

int n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> m;
  init();
  ll res = 0;
  for (int i = 0; i <= n && i <= m; i++) {
    if ((3 * m - i) % 2 == 0) {
      res = (res + binom(n, i) * binom((3 * m - i) / 2 + n - 1, n - 1)) % mod;
    }
  }
  for (int i = 2 * m + 1; i <= 3 * m; i++) {
    res = (res - (n * binom(3 * m - i + n - 2, n - 2)) % mod + mod) % mod;
  }
  cout << res << "\n";
}

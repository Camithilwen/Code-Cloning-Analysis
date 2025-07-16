#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
const int mod = 998244353;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

vl fac(3e6, 1);
vl invfac(fac.size(), 1);

ll bin(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fac[n] * invfac[k] % mod * invfac[n - k] % mod;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int i = 2; i < (int)fac.size(); ++i) {
    fac[i] = fac[i - 1] * i % mod;
    invfac[i] = mpow(fac[i], mod - 2);
  }
  int n, m;
  cin >> n >> m;
  ll res = 0;
  for (int k = m % 2; k <= m; k += 2) {
    int a = (m - k) / 2;
    res = (res + (bin(n - 1 + m + a, n - 1) - (n - k) * bin(n - 1 + a - 1, n - 1) - k * bin(n - 1 + a, n - 1)) % mod * bin(n, k)) % mod;
  }
  cout << (res % mod + mod) % mod << endl;
  return 0;
}

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 998244353

// x^n
ll mod_pow(ll x, ll n) {
  if (n == 0) return 1;
  ll res = mod_pow(x * x % MOD, n / 2);
  if (n & 1) res = res * x % MOD;
  return res;
}

// x^{-1}
ll mod_inv(ll x) { return mod_pow(x, MOD - 2); }

vector<ll> fact;
vector<ll> fact_inv;

void init_fact(int n) {
  fact.resize(n + 1);
  fact_inv.resize(n + 1);
  fact[0] = fact_inv[0] = 1;
  for (int i = 0; i < n; ++i) {
    fact[i + 1] = fact[i] * (i + 1) % MOD;
    fact_inv[i + 1] = fact_inv[i] * mod_inv(i + 1) % MOD;
  }
}

ll nCr(ll n, ll r) {
  if (n < r || n < 0 || r < 0) return 0;
  return fact[n] * fact_inv[r] % MOD * fact_inv[n - r] % MOD;
}

ll nPr(ll n, ll r) { return nCr(n, r) * fact[r] % MOD; }

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  init_fact(n);
  ll ans = 0;
  for (int i = 0; i <= k; ++i) {
    ll res = nCr(n - 1, n - 1 - i);
    res = (res * m) % MOD;
    res = (res * mod_pow(m - 1, n - 1 - i)) % MOD;
    ans = (ans + res) % MOD;
  }
  cout << ans << endl;
  return 0;
}
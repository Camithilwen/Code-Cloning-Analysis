#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 510000;

// https://drken1215.hatenablog.com/entry/2018/06/08/210000
ll fac[MAX], finv[MAX], inv[MAX];
void combinationInit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

ll combination(ll n, ll k) {
  if (n < k) {
    return 0;
  } else if (n < 0 || k < 0) {
    return 0;
  }
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

vector<pair<ll, ll>> primeFactorize(ll n) {
  vector<pair<ll, ll>> r;
  for (int i = 2; i * i <= n; i++) {
    if (n % i != 0) {
      continue;
    }
    int ex = 0;
    while (n % i == 0) {
      ex++;
      n /= i;
    }
    r.push_back({i, ex});
  }
  if (n > 1) {
    r.push_back({n, 1});
  }
  return r;
}

int main() {
  ll n, m;
  cin >> n >> m;
  auto res = primeFactorize(m);
  ll v = 1;
  combinationInit();
  for (ll i = 0; i < res.size(); i++) {
    v *= combination(res[i].second + n - 1, n - 1);
    v %= MOD;
  }

  cout << v << endl;
}

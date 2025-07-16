#include <bits/stdc++.h>
using namespace std;

const int N = 3000000;
const int MOD = 998244353;

int fact[N];
int ifact[N];

int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return 1LL * fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}

int M(int n, int k) {
  return C(n + k - 1, k - 1);
}

int n, m;

int main() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = 1LL * fact[i-1] * i % MOD;
  ifact[N-1] = 347057526;
  for (int i = N-2; i >= 0; --i) ifact[i] = 1LL * ifact[i+1] * (i+1) % MOD;
  
  scanf("%d %d", &n, &m);
  
  long long ans = 0;
  for (int odd = 0; odd <= m; ++odd) {
    if (m*3 - odd & 1) continue;
    
    int nn = m*3 - odd >> 1;
    
    long long res1 = 1LL * M(nn, n) - 1LL * M(nn - m, n) * n % MOD;
    long long res2 = 1LL * M(nn - m, n - 1) * n % MOD;
    
    ans = ans + res1 * C(n, odd) % MOD + res2 * C(n-1, odd) % MOD;
  }
  
  ans %= MOD;
  if (ans < 0) ans += MOD;
  
  printf("%lld\n", ans);
  return 0;
}

#include <stdio.h>

typedef long long var;

const int N = 210005;
const int MOD = 1e9 + 7;

int h, w, a, b;
var inv[N + 1], fac[N + 1], invfac[N + 1];

var f(int n, int m);
var c(int n, int m);

int main() {
  inv[0] = fac[0] = invfac[0] = inv[1] = 1;
  for (int i = 2; i <= N; ++i)
    inv[i] = ((MOD - MOD / i) * inv[MOD % i]) % MOD;
  for (int i = 1; i <= N; ++i) {
    fac[i] = (fac[i - 1] * i) % MOD;
    invfac[i] = (invfac[i - 1] * inv[i]) % MOD;
  }
  scanf("%d%d%d%d", &h, &w, &a, &b);
  var res = f(h, w);
  for (int i = 1; i <= a; ++i)
    (res -= (f(h - i + 1, b) * f(i, w - b)) % MOD) %= MOD;
  printf("%lld\n", (res + MOD) % MOD);
  return 0;
}

var f(int n, int m) { 
  return c((n - 1) + (m - 1), m - 1);
}

var c(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return (((fac[n] * invfac[m]) % MOD) * invfac[n - m]) % MOD;
}

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200010;
const int MOD = 1000000007;
typedef long long Int;

Int fac[MAX_N + 1];
Int inv[MAX_N + 1], ifac[MAX_N + 1];

Int comb(int n, int r)
{
  if (n < 0 || r < 0) return 0;
  if (n < r) return 0;
  Int ret = 1;
  ret = (ret * fac[n]) % MOD;
  ret = (ret * ifac[r]) % MOD;
  ret = (ret * ifac[n - r]) % MOD;
  return ret;
}

int main()
{
  int n, m, k;
  
  inv[1] = 1;
  fac[0] = ifac[0] = 1;
  fac[1] = ifac[1] = 1;
  for (int i = 2; i <= MAX_N - 1; i++) {
    fac[i] = (fac[i - 1] * i) % MOD;
    inv[i] = (inv[MOD % i] * (MOD - MOD / i)) % MOD;
    ifac[i] = ifac[i - 1] * inv[i] % MOD;
  }
  
  scanf("%d %d %d", &n, &m, &k);
  
  Int ans = 0;
  
  for (int i = 1; i <= m - 1; i++) {
    Int coef = (Int)n * n * (m - i) * i % MOD;
    ans = (ans + comb(n * m - 2, k - 2) * coef) % MOD;
  }
  
  for (int i = 1; i <= n - 1; i++) {
    Int coef = (Int)m * m * (n - i) * i % MOD;
    ans = (ans + comb(n * m - 2, k - 2) * coef) % MOD;
  }
  
  printf("%lld\n", ans);
  
  return 0;
}

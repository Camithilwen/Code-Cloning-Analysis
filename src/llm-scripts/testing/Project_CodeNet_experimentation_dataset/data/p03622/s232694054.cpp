#include <cstdio>
#include <cstring>
#include <algorithm>
const int MOD = 998244353;
const int MAXN = 5e5 + 10;

int n, m;
namespace {
  inline int add(int x) { return x >= MOD ? x - MOD : x; }
  inline int sub(int x) { return x < 0 ? x + MOD : x; }
  inline int mul(int x, int y) { return 1ll * x * y % MOD; }
  inline int pwr(int x, int y) {
    int ans = 1;
    for (; y; y >>= 1, x = mul(x, x)) {
      if (y & 1) ans = mul(ans, x);
    }
    return ans;
  }
}
int fact[MAXN << 1], invf[MAXN << 1];
int choose(int x, int y) {
  return x < y ? 0 : mul(fact[x], mul(invf[y], invf[x - y]));
}
int main() {
  scanf("%d%d", &n, &m);
  fact[0] = 1, invf[0] = 1;
  if (n < m) std::swap(n, m);
  for (int i = 1; i <= 2 * n; i++) {
    fact[i] = mul(fact[i - 1], i);
    invf[i] = pwr(fact[i], MOD - 2);
  }

  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = add(ans + mul(choose(2 * i - 1, i), choose(n + m - 2 * i, n - i)));
  }
  printf("%d\n", add(n + mul(ans, pwr(choose(n + m, n), MOD - 2))));
}

#include <stdio.h>
#define mod 1000000007
typedef long long ll;

ll mul(ll a, ll b) {
  return (a * b) % mod;
}

ll rev(ll a) {
  ll ans = 1, b = mod - 2;
  while(b) {
    if(b & 1) ans = mul(ans, a);
    a = mul(a, a), b >>= 1;
  }
  return ans;
}

ll sum(ll a) {
  return a * (a + 1) / 2;
}

int main(void) {
  ll i, j, n, m, k, ans = 0, c, now;
  scanf("%lld%lld%lld", &n, &m, &k);
  ll fact[n * m + 1];
  fact[0] = 1;
  for(i = 1; i <= n * m; ++i) fact[i] = mul(fact[i - 1], i);
  c = mul(fact[n * m - 2], mul(rev(fact[k - 2]), rev(fact[n * m - k])));
  for(i = 0; i < n; ++i) for(j = 0; j < m; ++j) {
    now = m * sum(i) + n * sum(j);
    now += sum(n - 1 - i) * m + sum(m - 1 - j) * n;
    now %= mod;
    now = mul(now, c);
    ans += now;
    ans %= mod;
  }
  ans = mul(ans, rev(2));
  printf("%lld", ans);
  return 0;
}
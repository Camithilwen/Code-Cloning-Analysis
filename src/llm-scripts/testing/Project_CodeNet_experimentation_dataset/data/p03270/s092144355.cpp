#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

i64 MOD = 998244353;

long long inv_mod(long long a, long long m = MOD) {
  long long b, x, u, q, abs_m, tmp;

  abs_m = (m < 0) ? -m : m;
  b = m;
  x = 1;
  u = 0;
  while (b > 0) {
    q = a / b;
    tmp = u;
    u = x - q * u;
    x = tmp;
    tmp = b;
    b = a - q * b;
    a = tmp;
  }

  return (x < 0) ? abs_m + x : x;
}


i64 fact[101010];
i64 inv[101010];

void init() {
  fact[0] = 1;
  for(int i = 1;i < 101010;i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  inv[101010 - 1] =  inv_mod(fact[101010 - 1]) % MOD;
  for(int i = 101010 - 1;i >= 1;i--) {
    inv[i - 1] = inv[i] * i % MOD;
  }
}

i64 comp(i64 n, i64 k) {
  if(n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
  init();
  i64 K, N;
  cin >> K >> N;

  for(int i = 2; i <= 2 * K;i++) {
    i64 p = i;
    if(i > K + 1) p = (K + 1) * 2 - p;
    p /= 2;

    i64 ans = 0;

    for(int j = 0;j <= p;j++) {
      auto res = comp(p, j) * comp(K + N - 2 * j - 1, N - 2 * j) % MOD;
      if(j & 1) ans = (ans - res % MOD + MOD) % MOD;
      else ans = (ans + res) % MOD;
    }
    cout << ans << endl;
  }
}

// https://atcoder.jp/contests/abc127/tasks/abc127_e

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

//------------------------------------------------------------------------------
ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

ll mod_inverse(ll x, ll mod) {
  return mod_pow(x, mod - 2, mod);
}

ll mod_comb(ll n, ll k, ll mod) {
  if (n < 0 || k < 0 || n < k) return 0;
  ll a = 1, b = 1;
  while(k > 0) {
    a = a * n-- % mod;
    b = b * k-- % mod;
  }
  return a * mod_inverse(b, mod) % mod;
}

//------------------------------------------------------------------------------
const int M_MAX = 2*1e5;
const int MOD = 1e9+7;

ll N, M, K;

void solve() {
  ll y = 1;
  y = y * (N - 1) % MOD;
  y = y * N % MOD;
  y = y * (N + 1) % MOD;
  y = y * M % MOD;
  y = y * M % MOD;

  ll x = 1;
  x = x * (M - 1) % MOD;
  x = x * M % MOD;
  x = x * (M + 1) % MOD;
  x = x * N % MOD;
  x = x * N % MOD;

  ll ans = (x + y) % MOD;
  ans = ans * mod_inverse(6, MOD) % MOD;
  ans = ans * mod_comb(N * M - 2, K - 2, MOD) % MOD;
  printf("%lld\n", ans);
}

void input() {
  scanf("%lld%lld%lld", &N, &M, &K);
}

int main() {
  input();
  solve();
  return 0;
}

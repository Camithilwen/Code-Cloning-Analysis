#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;

const ll MOD = 998244353LL;
const ll MAX = 2000010LL;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main(int argc, char *argv[]) {
  COMinit();

  ll n, m, k;

  cin >> n >> m >> k;

  ll ans = 0LL;

  for(ll i=0;i<=k;i++){
    ans += ((m*modpow(m-1LL,n-i-1LL)%MOD)*COM(n-1LL,i)) % MOD;
    ans %= MOD;
  }

  if(ans<0LL){
    ans += MOD;
  }

  cout << ans << endl;

  return 0;
}

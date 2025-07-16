#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1e9 + 7;

const int MAX = 1100;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

ll COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

ll modpow(ll a, ll n, ll MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}


int main() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    vector<ll> dp(n+1, 0);
    dp[0] = 1;

    COMinit();

    for (int i = a; i <= b; i++) {
        for (int j = n; j >= 0; j--) {
            for (int k = c; i*k <= j && k <= d; k++) {
                dp[j] += dp[j-i*k] * fac[n-(j-i*k)] % MOD * finv[n-j] % MOD * finv[k] % MOD * modpow(finv[i], k, MOD) % MOD;
                dp[j] %= MOD;
            }
        }
    }

    cout << dp[n] << endl;


    return 0;

}

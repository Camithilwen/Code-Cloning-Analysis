#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const ll MAXN = 2e5+10;
const ll MOD = 1e9+7;

ll H, W, A, B, ans = 0, fac[MAXN], inv[MAXN];

int main() {
    scanf("%lld%lld%lld%lld", &H, &W, &A, &B);
    inv[1] = inv[0] = 1;
    fac[1] = fac[0] = 1;
    for (ll i = 2; i <= MAXN - 10; i++) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        fac[i] = fac[i-1] * i % MOD;
    }
    for (ll i = 2; i <= MAXN - 10; i++) {
        inv[i] = inv[i-1] * inv[i] % MOD;
    }
    for (ll i = 1; i <= H-A; i++) {
        ll tem = (B - 1) + (i - 1);
        ll tql = (W - B - 1) + (H - i);
        ll len = W - B - 1;
        ll now = ((((fac[tem] * inv[i-1] % MOD) * inv[tem-(i-1)] % MOD) % MOD) * (((fac[tql] * inv[len] % MOD) * inv[tql - len] % MOD) % MOD)) % MOD;
        ans = (ans + now) % MOD;
    }
    printf("%lld\n", ans % MOD);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

int n, a[330], dp[300*303], d2[300*303], ans = 1, sum;

int expo(int b, int e) {
    if(e == 0) return 1;
    if(e & 1) return 1ll * b * expo(1LL * b * b % MOD, e >> 1) % MOD;
    return expo(1LL * b * b % MOD, e >> 1);
}

int inv_mod(int x) { return expo(x, MOD - 2); }

int main() {
    scanf("%d", &n);

    dp[0] = d2[0] = 1;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        sum += a[i];
        ans = 3LL * ans % MOD;

        for(int v = n * 300; v >= 0; v--) {
            dp[v] = (2LL * dp[v] % MOD + (v >= a[i] ? dp[v - a[i]] : 0)) % MOD;
            d2[v] =       (d2[v] % MOD + (v >= a[i] ? d2[v - a[i]] : 0)) % MOD;
        }
    }

    for(int i = sum; 2*i >= sum; i--)
        ans = (ans - 3LL * dp[i] % MOD + MOD) % MOD;

    if(sum % 2 == 0) ans = (ans + 3LL * d2[sum/2] % MOD) % MOD;

    printf("%d\n", ans);
    return 0;
}

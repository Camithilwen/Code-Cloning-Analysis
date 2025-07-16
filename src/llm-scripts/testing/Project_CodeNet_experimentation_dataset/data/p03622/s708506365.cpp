#include "bits/stdc++.h"
using namespace std;

static const int MOD = 998244353;

long long Inv(long long a) {
        long long res = 1;
        long long n = MOD - 2;
        while (n > 0) {
                if (n & 1) res = res * a % MOD;
                a = a * a % MOD;
                n >>= 1;
        }
        return res;
}
const int N = 5000001;
long long fact[N];
long long invfact[N];
void init() {
        fact[0] = 1;
        for (int i = 1; i < N; i ++) fact[i] = fact[i - 1] * i % MOD;
        for (int i = 0; i < N; i ++) invfact[i] = Inv(fact[i]);
}
long long C(long long n, long long r) {
        if (n < 0 || r < 0 || n < r) return 0;
        return fact[n] * invfact[n - r] % MOD * invfact[r] % MOD;
}

int main() {
        init();
        int n, m;
        scanf("%d%d", &n, &m);
        if (n < m) swap(n, m);
        long long ans = 0;
        for (int i = 1; i <= m; i ++) {
                long long mul = C(2 * i, i) % MOD;
                mul = mul * C(n + m - 2 * i, n - i) % MOD;
                ans = (ans + mul) % MOD;
        }
        ans = ans * Inv(2 * C(n + m, n)) % MOD;
        ans = (ans + n) % MOD;
        printf("%lld\n", ans);
        return 0;
}

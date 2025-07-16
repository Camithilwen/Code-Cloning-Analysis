#include <bits/stdc++.h>
using namespace std;
using Int = long long;
const int MAX = 2000000;
const int MOD = 998244353;
Int fac[MAX], finv[MAX], inv[MAX];
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
Int COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main()
{
    COMinit();
    int N, M; cin >> N >> M;
    Int a = 0, b = 0, c = 0;
    for (int o = M % 2; o <= M; o += 2) {
        int t = (3 * M - o) / 2;
        a += COM(t + N - 1, N - 1) * COM(N, o);
        a %= MOD;
    }
    for (int o = M % 2; o <= M; o += 2) {
        int t = (3 * M - o) / 2;
        b += N * COM((t - M) + N - 1, N - 1) % MOD * COM(N - 1, o - 1);
        b %= MOD;
    }
    for (int o = M % 2; o <= M; o += 2) {
        int t = (3 * M - o) / 2;
        c += N * COM((t - M - 1) + N - 1, N - 1) % MOD * COM(N - 1, o);
        c %= MOD;
    }
    cout << (a + MOD - b + MOD - c) % MOD << '\n';
    return 0;
}
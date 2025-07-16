#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const long long MOD = 998244353;
const int FACT_MAX = 1000000;
long long fact[FACT_MAX];
long long inv[FACT_MAX];
long long invfact[FACT_MAX];
long long nPr(int n, int r) { return (fact[n] * invfact[n - r]) % MOD; }
long long nCr(int n, int r) {
    return (((fact[n] * invfact[r]) % MOD) * invfact[n - r]) % MOD;
}
void initialize_fact() {
    fact[0] = 1;
    inv[0] = 0;
    inv[1] = 1;
    invfact[0] = 1;
    loop(i, 1, FACT_MAX) fact[i] = (i * fact[i - 1]) % MOD;
    loop(i, 2, FACT_MAX) inv[i] = MOD - ((MOD / i) * inv[MOD % i] % MOD);
    loop(i, 1, FACT_MAX) invfact[i] = (invfact[i - 1] * inv[i]) % MOD;
}

void solve(long long N, long long M, long long K) {
    initialize_fact();

    vector<long long> pow_m(N + 1);
    pow_m[0] = 1;
    rep(i, N) pow_m[i + 1] = (pow_m[i] * (M-1)) % MOD;

    long long ans = 0;
    rep (k, K + 1) {
        long long cmb = M;
        cmb *= nCr(N-1, k);
        cmb %= MOD;
        cmb *= pow_m[N-1-k];
        cmb %= MOD;
        ans += cmb;
        ans %= MOD;
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    long long K;
    scanf("%lld", &K);
    solve(N, M, K);
    return 0;
}

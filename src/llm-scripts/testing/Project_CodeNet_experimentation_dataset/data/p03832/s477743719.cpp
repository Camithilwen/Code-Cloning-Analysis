#include <bits/stdc++.h>

int main() {
    using namespace std;

    constexpr unsigned long MOD = 1000000007;

    unsigned long N;
    cin >> N;

    auto pw = [&MOD](unsigned long a, unsigned long n = 1000000005){
        unsigned long ret = 1;
        while(n){
            if(n & 1)(ret *= a) %= MOD;
            (a *= a) %= MOD;
            n >>= 1;
        }
        return ret;
    };

    vector<unsigned long> fact(N + 1), ifact(N + 1);
    fact[0] = 1;
    for(unsigned long i = 1; i <= N; ++i)fact[i] = fact[i - 1] * i % MOD;
    ifact[N] = pw(fact[N]);
    for(unsigned long i = N; i > 0; --i)ifact[i - 1] = ifact[i] * i % MOD;

    unsigned long A, B, C, D;
    cin >> A >> B >> C >> D;

    vector<vector<unsigned long>> dp(B + 1, vector<unsigned long>(N + 1));
    dp[A - 1][N] = 1;

    for(unsigned long i = A; i <= B; ++i){
        for(unsigned long j = 0; j <= N; ++j){
            dp[i][j] = dp[i - 1][j];
            for(unsigned long k = C, l = j + C * i, m = pw(ifact[i], C); k <= D && l <= N; ++k, l += i, (m *= ifact[i]) %= MOD)dp[i][j] += ((((dp[i - 1][l] * fact[l]) % MOD * ifact[j]) % MOD * m) % MOD * ifact[k]) % MOD;
            dp[i][j] %= MOD;
        }
    }

    cout << dp[B][0] << endl;

    return 0;
}
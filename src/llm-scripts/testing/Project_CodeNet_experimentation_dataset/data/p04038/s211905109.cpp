#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

vector<int64_t> fact, seq_inv, fact_inv;

void create_fact_mod(int num){
    fact[0] = fact[1] = 1;
    for(int i=2; i<=num; i++) fact[i] = fact[i-1] * i % MOD;
}

void create_seq_inv_mod(int num){
    seq_inv[0] = seq_inv[1] = 1;
    for(int i=2; i<=num; i++) seq_inv[i] = (MOD - MOD/i) * seq_inv[MOD%i] % MOD;
}

void create_fact_inv_mod(int num){
    fact_inv[0] = fact_inv[1] = 1;
    for(int i=2; i<=num; i++) fact_inv[i] = fact_inv[i-1] * seq_inv[i] % MOD;
}

void create_mod_tables(int num){
    fact.resize(num+1);
    seq_inv.resize(num+1);
    fact_inv.resize(num+1);
    create_fact_mod(num);
    create_seq_inv_mod(num);
    create_fact_inv_mod(num);
}

int64_t comb_mod(int n, int k){
    return fact[n] * fact_inv[n-k] % MOD * fact_inv[k] % MOD;
}

int main(){
    int N, K;
    cin >> N >> K;
    if(K == 1){
        cout << 1 << endl;
        return 0;
    }
    create_mod_tables(N*K);
    static int64_t dp[2001][2001];
    dp[0][0] = fact[N];
    for(int i=0; i<=N; i++) for(int j=0; j<=i; j++){
        if(i<N) add(dp[i+1][j], dp[i][j]);
        if(i>=j+1) add(dp[i][j+1], dp[i][j] * comb_mod(N*K - i - j*(K-1) - 1, K-2));
    }
    cout << dp[N][N] << endl;
    return 0;
}

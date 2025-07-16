#include <bits/stdc++.h>
using namespace std;

int64_t MOD;
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

int64_t perm_mod(int n, int k){
    return fact[n] * fact_inv[n-k] % MOD;
}

int64_t power_mod(int64_t num, int64_t power){
    int64_t prod = 1;
    num %= MOD;
    while(power > 0){
        if(power&1) prod = prod * num % MOD;
        num = num * num % MOD;
        power >>= 1;
    }
    return prod;
}

int64_t extgcd(int64_t a, int64_t b, int64_t& x, int64_t& y){
    int64_t d = a;
    if(b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }else{
        x = 1; y = 0;
    }
    return d;
}

int64_t inv_mod(int64_t a){
    int64_t x, y;
    extgcd(a, MOD, x, y);
    return (MOD + x%MOD) % MOD;
}

int main(){
    int N;
    cin >> N >> MOD;
    create_mod_tables(10000);

    static int64_t dp[6010][4001];
    dp[3*N][N] = 1;
    for(int i=3*N; i>0; i--) for(int j=0; j<=2*N; j++){
        add(dp[i-1][min(2*N, j+1)], dp[i][j]);
        if(i>=2 && j > 0) add(dp[i-2][j-1], dp[i][j] * (i-1));
        if(i>=3) add(dp[i-3][j], dp[i][j] * (i-1) * (i-2));
    }

    int64_t ans = 0;
    for(int j=N; j<=2*N; j++) add(ans, dp[0][j]);
    cout << ans << endl;
    return 0;
}

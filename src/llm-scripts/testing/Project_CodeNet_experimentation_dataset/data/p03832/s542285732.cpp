#include <bits/stdc++.h>
using namespace std;
long long fac[1010], finv[1010], inv[1010]; 
long long MOD = 1000000007; 
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 1005; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
long long group(int k, int n, int r){
	long long num = COM(r, k*n) * fac[k*n] % MOD; 
	for(int i = 0; i < n; i++){
		num *= finv[k]; num %= MOD; 
	}
	num *= finv[n]; num %= MOD; 
	return num; // r人残っているときにk人のグループをn個作る方法
}
int main(){
	int N, A, B, C, D; 
	cin >> N >> A >> B >> C >> D; 
	COMinit(); 
	long long dp[1010][1010] = {}; // i人のグループまで見てj人使いきってる
	dp[A-1][0] = 1; 
	for(int i = A-1; i < B; i++){
		for(int j = 0; j <= N; j++){
			if(!dp[i][j]) continue; 
			dp[i+1][j] += dp[i][j]; 
			dp[i+1][j] %= MOD; 
			for(int k = C; k <= D; k++){
				if(j + (i+1)*k > N) break; 
				dp[i+1][j + (i+1)*k] += dp[i][j] * group(i+1, k, N-j); 
				dp[i+1][j + (i+1)*k] %= MOD; 
			}
		}
	}
	cout << dp[B][N] << endl; 
}
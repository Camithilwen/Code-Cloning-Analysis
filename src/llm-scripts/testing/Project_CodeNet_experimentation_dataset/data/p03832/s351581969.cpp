#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define llint long long
#define mod 1000000007
#define inf 1e18

using namespace std;
typedef pair<double, llint> P;
typedef pair<llint, P> E;

llint n;
llint a, b, c, d;
llint dp[1005][1005];

const int FACT_MAX = 2005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}

llint comb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n;
	cin >> a >> b >> c >> d;
	
	dp[a-1][0] = 1;
	for(int i = a-1; i < b; i++){
		for(int j = 0; j <= n; j++){
			dp[i+1][j] += dp[i][j],  dp[i+1][j] %= mod;
			llint mul = 1;
			for(int k = 1; k <= d && j+k*(i+1) <= n; k++){
				mul *= comb(n-j-(k-1)*(i+1), i+1), mul %= mod;
				if(k >= c){
					(dp[i+1][j+k*(i+1)] += dp[i][j] * mul % mod * fact_inv[k] % mod) %= mod;
				}
			}
		}
	}
	
	cout << dp[b][n] << endl;

	return 0;
}
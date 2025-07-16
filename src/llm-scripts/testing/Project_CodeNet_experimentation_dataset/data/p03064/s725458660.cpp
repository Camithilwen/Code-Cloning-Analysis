#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;
const ll MAXN = 303;


ll dp[MAXN][MAXN*MAXN];

main(){
	int n;
	cin >> n;
	ll arr[n];
	int S = 0;
	for(int i=0;i<n;++i){
		cin >> arr[i];
		S += arr[i];
	}
	fill(&dp[0][0], &dp[0][0] + MAXN*MAXN*MAXN, 0);
	dp[0][0] = 1;
	for(auto i=0;i<n;++i){
		for(auto j=0;j<MAXN*MAXN;++j){
			dp[i+1][j+arr[i]] += dp[i][j];
			dp[i+1][j+arr[i]]%=MOD;
			dp[i+1][j] += 2LL*dp[i][j];
			dp[i+1][j]%=MOD;
		}
	}
	ll K = 0;
	for(auto i=(S+1)/2;i<=S;++i){
		K += dp[n][i];
	}
	fill(&dp[0][0], &dp[0][0] + MAXN*MAXN*MAXN, 0);
	dp[0][0] = 1;
	ll L = 0;
	if(S%2==0){
		for(auto i=0;i<n;++i){
			for(auto j=0;j<MAXN*MAXN;++j){
				dp[i+1][j+arr[i]] += dp[i][j];
				dp[i+1][j+arr[i]]%=MOD;
				dp[i+1][j] += dp[i][j];
				dp[i+1][j]%=MOD;
			}
		}
		L = dp[n][S/2];
	}
	ll ans = 1;
	for(int i=0;i<n;++i){
		ans *= 3LL;
		ans %= MOD;
	}
	ans += MOD - (3*K)%MOD;
	ans %=MOD;
	ans += 3*L;
	ans %=MOD;
	cout << ans << endl;
}

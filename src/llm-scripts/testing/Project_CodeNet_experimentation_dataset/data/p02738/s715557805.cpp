#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using ll = long long int;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);

#define l_ength size

ll MOD;

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

ll dp[6060][13000];

int main(void){
	int n,i,j;
	ll ans = 0ll;
	std::cin >> n >> MOD;
	n *= 3;
	dp[0][6500] = 1ll;
	for(i=0; i<n; ++i){
		for(j=500; j<=12500; ++j){
			add_mod(dp[i+1][j-1],dp[i][j]);
			add_mod(dp[i+2][j+1],dp[i][j]*(i+1)%MOD);
			add_mod(dp[i+3][j],dp[i][j]*(i+1)*(i+2)%MOD);
		}
	}
	for(j=500; j<=6500; ++j){
		add_mod(ans,dp[n][j]);
	}
	std::cout << ans << std::endl;
	return 0;
}

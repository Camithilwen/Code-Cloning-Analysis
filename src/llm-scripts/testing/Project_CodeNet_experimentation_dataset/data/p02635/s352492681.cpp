#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using ll = long long int;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = 998244353ll;

#define l_ength size

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

ll dp[310][310][310][2];
std::string s;

int main(void){
	int n,m,i,j,k,l;
	ll ans=0ll;
	std::cin >> s;
	std::cin >> l;
	n = s.l_ength();
	l = std::min(l,n);
	std::reverse(s.begin(),s.end());
	dp[0][0][0][0] = 1ll;
	for(i=0; i<n; ++i){
		if(s[i]=='0'){
			for(j=0; j<=l; ++j){
				for(k=0; k<=j; ++k){
					add_mod(dp[i+1][j][k][0],dp[i][j][k][0]);
					if(k){
						add_mod(dp[i+1][j][k][0],dp[i+1][j][k-1][0]);
					}
				}
			}
			for(j=0; j<=l; ++j){
				for(k=0; k<=j; ++k){
					add_mod(dp[i+1][j][k][0],dp[i][j][k][1]);
				}
			}
		}else{
			for(j=0; j<=l; ++j){
				for(k=0; k<=j; ++k){
					add_mod(dp[i+1][j][k][0],dp[i][j][k][0]);
					if(j+1<=l){
						add_mod(dp[i+1][j+1][k][1],dp[i][j][k][0]);
						add_mod(dp[i+1][j+1][k][1],dp[i][j][k][1]);
					}
				}
			}
		}
		/*
		for(j=0; j<=l; ++j){
			for(k=0; k<=j; ++k){
				printf("%d %d %d: %lld, %lld,;\n",i,j,k,dp[i+1][j][k][0],dp[i+1][j][k][1]);
			}
		}
		printf("\n");
		*/
	}
	for(j=0; j<=l; ++j){
		for(k=0; k<=j; ++k){
			add_mod(ans,dp[n][j][k][0]);
		}
	}
	std::cout << ans << std::endl;
	return 0;
}

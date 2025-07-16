#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 45,mx = 1 << 17 + 5;
int n,x,y,z;
int lim,chk,ans = 0;
int dp[N][mx] = {0};
int fa[N][mx] = {0};
int main(){
	scanf("%d%d%d%d",&n,&x,&y,&z);
	lim = 1 << (x+y+z);
	chk = (1 << (x+y+z-1)) + (1 << (y+z-1)) + (1 << (z-1));
	fa[0][0] = 1;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<lim;j++){
			for(int k = 1;k<=10;k++){
				int res = ((j << k) + (1 << (k-1))) % lim; 
				if((res & chk) == chk) dp[i][res] += fa[i-1][j];
				else dp[i][res] += dp[i-1][j];
				dp[i][res] %= mod;
				fa[i][res] = (fa[i][res] + fa[i-1][j]) % mod;
			}
		}
	}
	for(int i = 0;i<lim;i++) ans = (ans + dp[n][i]) % mod;
	printf("%d",ans);
	return 0;
}
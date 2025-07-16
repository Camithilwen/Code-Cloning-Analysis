#include<bits/stdc++.h>
#define re register
#define max(a,b) ((a)>(b)?(a):(b))
const int maxn=305;
char S[maxn];
int dp[2][maxn][maxn],n,m,o,ans;
int main() {
	scanf("%s",S+1);n=strlen(S+1);scanf("%d",&m);
	for(re int p=0;p<=m;++p,o^=1) {
		for(re int i=1;i<=n;i++) dp[o^1][i][i]=1;
		for(re int l=2;l<=n;++l) 
			for(re int i=1,j=i+l-1;j<=n;++i,++j) {
				dp[o^1][i][j]=max(dp[o^1][i][j-1],dp[o^1][i+1][j]);
				if(S[i]==S[j]) dp[o^1][i][j]=(dp[o^1][i][j],dp[o^1][i+1][j-1]+2);
				if(p) dp[o^1][i][j]=max(dp[o^1][i][j],dp[o][i+1][j-1]+2);
			}
		ans=max(ans,dp[o^1][1][n]);
	}
	printf("%d\n",ans);
	return 0;
}

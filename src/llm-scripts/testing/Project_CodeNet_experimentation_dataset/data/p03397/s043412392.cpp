#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
char s[300030];
int n,dp[300030][2][2][3],suf[300030],ans;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);s[n+1]='1';
	dp[0][0][1][0]=1;
	suf[n+1]=suf[n+2]=1;
	for(int i=n;i;--i)suf[i]=s[i]=='?'?(suf[i+1]<<1)%mod:suf[i+1];
	for(int i=1;i<=n+1;++i)
	{
		if(s[i]!='1')
		{
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k)
					for(int l=0;l<3;++l)
						add(dp[i][j][k][(l&1)+1],dp[i-1][j][k][l]);
		}
		if(s[i]!='0')
		{
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k)
				{
					if(!j&&k==1)add(dp[i][1][k^1][0],dp[i-1][j][k][0]);
					else if(j==1&&!k)ans=(ans+1ll*dp[i-1][j][k][0]*suf[i+1])%mod;
					else add(dp[i][j][k^1][0],dp[i-1][j][k][0]);
					add(dp[i][j][k][0],dp[i-1][j][k][1]);
					add(dp[i][j][k^1][0],dp[i-1][j][k][2]);
				}
		}
	//	for(int j=0;j<3;++j)
	//		for(int k=0;k<2;++k)
	//			for(int l=0;l<3;++l)
	//				if(dp[i][j][k][l])
	//					printf("%d %d %d %d %d\n",i,j,k,l,dp[i][j][k][l]);
	//	printf("\n");
	}
	printf("%d",ans);
	return 0;
}

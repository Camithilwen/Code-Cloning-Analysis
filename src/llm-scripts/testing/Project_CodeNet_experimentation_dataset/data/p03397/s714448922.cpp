#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char c[301000];int dp[301000][3][3],hj[301000],mi[301000],mod=1e9+7;
int main()
{
	scanf("%s",c);dp[0][0][0]=1;int n=strlen(c);
	mi[0]=1;for(int i=1;i<=n;i++)mi[i]=(mi[i-1]*2)%mod;
	for(int i=n;i>=1;i--)if(c[i-1]=='?')hj[i]=hj[i+1]+1;else hj[i]=hj[i+1];
	long long ans=0;
	for(int i=1;i<=n;i++)
	for(int x=0;x<=2;x++)
	for(int y=0;y<=2;y++)
	{
		if(c[i-1]=='1')
		{
			if(y==0)
				if(x+1>=3)ans=(ans+(long long)dp[i-1][x][y]*(long long)mi[hj[i+1]])%mod;
				else dp[i][x+1][y]=(dp[i][x+1][y]+dp[i-1][x][y])%mod;
			else dp[i][x][y-1]=(dp[i][x][y-1]+dp[i-1][x][y])%mod;
		}
		if(c[i-1]=='0')
		{
			if(y==2)dp[i][x][1]=(dp[i][x][1]+dp[i-1][x][y])%mod;
			else dp[i][x][y+1]=(dp[i][x][y+1]+dp[i-1][x][y])%mod;
		}
		if(c[i-1]=='?')
		{
			if(y==0)
				if(x+1>=3)ans=(ans+(long long)dp[i-1][x][y]*(long long)mi[hj[i+1]])%mod;
				else dp[i][x+1][y]=(dp[i][x+1][y]+dp[i-1][x][y])%mod;
			else dp[i][x][y-1]=(dp[i][x][y-1]+dp[i-1][x][y])%mod;
			if(y==2)dp[i][x][1]=(dp[i][x][1]+dp[i-1][x][y])%mod;
			else dp[i][x][y+1]=(dp[i][x][y+1]+dp[i-1][x][y])%mod;
		}
	}
	for(int y=0;y<=2;y++)for(int x=y+1;x<=2;x++)ans=(ans+dp[n][x][y])%mod;
	printf("%lld",ans);return 0;
}//01(010,001)可消 000消 dp[i][x][y]表示前i个数，1数量x，0数量y 方案数 
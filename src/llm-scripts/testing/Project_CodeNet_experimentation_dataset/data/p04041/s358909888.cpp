#include <bits/stdc++.h>
using namespace std;

int n,x,y,z,mx,ji;
const long long mod=1e9+7;
long long ans,dp[45][1000010];
int main()
{
	scanf("%d%d%d%d",&n,&x,&y,&z);
	ans=1;
	for(int i=1;i<=n;++i)
	ans=ans*10%mod;
	mx=(1<<(x+y+z))-1;
	ji=(1<<(x+y+z-1));
	ji|=(1<<(y+z-1));
	ji|=(1<<(z-1));
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=mx;++j)
		{
			if(dp[i-1][j]==0)
			continue;
			for(int k=1;k<=10;++k)
			{
				int cur=(j<<k)|(1<<(k-1));
				cur&=mx;//只取后(x+y+z)位
				if((cur&ji)==ji)
				continue;
				dp[i][cur]=(dp[i][cur]+dp[i-1][j])%mod; 
			}
		}
	}
	for(int i=0;i<=mx;++i)
	ans=(ans-dp[n][i]+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}

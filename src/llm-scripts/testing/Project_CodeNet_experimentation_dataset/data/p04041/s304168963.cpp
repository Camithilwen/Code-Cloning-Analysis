#include<iostream>
using namespace std;
int n,x,y,z;
long mod=1e9+7,dp[41][1<<17];
main()
{
	cin>>n>>x>>y>>z;
	int no=1<<z-1|1<<y+z-1|1<<x+y+z-1;
	dp[0][0]=1;
	long ans=1;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=10;j++)
		{
			for(int k=0;k<1<<17;k++)
			{
				int nxt=(k<<j|1<<j-1)&(1<<17)-1;
				if((nxt&no)!=no)(dp[i+1][nxt]+=dp[i][k])%=mod;
			}
		}
		(ans*=10)%=mod;
	}
	for(int i=0;i<1<<17;i++)ans=(ans-dp[n][i]+mod)%mod;
	cout<<ans<<endl;
}
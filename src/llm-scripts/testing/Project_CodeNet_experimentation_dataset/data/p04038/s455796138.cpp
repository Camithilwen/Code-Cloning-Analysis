#include <bits/stdc++.h>
using namespace std;

int n,k;
const long long mod=1e9+7;
long long dp[3010][3010],jie[4000010],ni[4000010];
inline long long ksm(long long x,long long y)
{
	long long res=1;
	while(y)
	{
		if(y&1)
		res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		printf("1\n");
		return 0;
	}
	jie[0]=1;
	for(int i=1;i<=n*k;++i)
	jie[i]=jie[i-1]*i%mod;
	ni[n*k]=ksm(jie[n*k],mod-2);
	for(int i=n*k-1;i>=0;--i)
	ni[i]=ni[i+1]*(i+1)%mod;
	for(int i=1;i<=n;++i)
	dp[i][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
		{
			int x=n*k-i-(j-1)*(k-1)-1;
			dp[i][j]=(dp[i-1][j]+dp[i][j-1]*(n-j+1)%mod*jie[x]%mod*ni[k-2]%mod*ni[x-k+2]%mod)%mod;
		}
	}
	printf("%lld\n",dp[n][n]);
	return 0;
}
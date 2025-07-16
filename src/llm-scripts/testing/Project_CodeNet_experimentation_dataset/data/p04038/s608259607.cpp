#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7,inv2=5e8+4;
inline int poww(long long x,int y)
{
	long long ret=1;
	while(y)
	{
		if(y&1)ret*=x,ret%=MOD;
		x*=x,x%=MOD;
		y>>=1;
	}
	return ret;
}
int n,k;
long long dp[2333][2333];
long long fac[4555555],invfac[4555555];
inline long long c(int a,int b)
{
	return fac[a]*invfac[b]%MOD*invfac[a-b]%MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	if(k==1)return cout<<1<<endl,0;
	fac[0]=1;
	for(int i=1;i<=4000000;i++)fac[i]=fac[i-1]*i%MOD;
	invfac[4000000]=poww(fac[4000000],MOD-2);
	for(int i=4000000;i>=1;i--)invfac[i-1]=invfac[i]*i%MOD;
	dp[n+1][n]=1;
	for(int i=n;i>=1;i--)
	{
		long long sum=0;
		for(int j=n;j>=i;j--)
		{
			sum+=dp[i+1][j];sum%=MOD;
			dp[i][j]=c(n-j+(n-i)*(k-1)+k-2,k-2)*sum%MOD;
//			cerr<<"dp "<<i<<','<<j<<'='<<dp[i][j]<<endl;
		}
	}
	long long sum=0;
	for(int i=1;i<=n;i++)sum+=dp[1][i];
	cout<<sum%MOD*fac[n]%MOD<<endl;
	return 0;
}
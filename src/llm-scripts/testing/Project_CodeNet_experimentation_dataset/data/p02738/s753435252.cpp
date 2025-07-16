#include<cstdio>
#include<algorithm>
using namespace std;
int mod;
int mypow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int n,pw2[6005],pw3[6005],ans=0,fac[6005],invfac[6005];
int main()
{
	scanf("%d%d",&n,&mod);n=3*n;
	pw2[0]=pw3[0]=1;
	pw2[1]=mypow(2,mod-2);
	pw3[1]=mypow(3,mod-2);fac[0]=fac[1]=1;
	for(int i=2;i<=n;i++)pw2[i]=1ll*pw2[i-1]*pw2[1]%mod,pw3[i]=1ll*pw3[i-1]*pw3[1]%mod,fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n]=mypow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	for(int i=0;i<=n/3;i++)
	{
		for(int j=0;i+j<=n/3;j++)
		{
			ans=(ans+1ll*pw2[i]*pw3[j]%mod*invfac[i]%mod*invfac[j]%mod*invfac[n-2*i-3*j])%mod;
		}
	}
	for(int i=1;i<=n;i++)ans=1ll*ans*i%mod;
	printf("%d\n",ans);
	return 0;
}
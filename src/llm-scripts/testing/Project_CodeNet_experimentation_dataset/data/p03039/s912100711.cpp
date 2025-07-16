#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll n,m,k;
ll poww(ll x,ll k)
{
	ll base=x,ans=1;
	while(k)
	{
		if(k&1)ans=ans*base%mod;
		base=base*base%mod;
		k>>=1;
	}
	return ans;
}
ll nok(ll x)
{
	ll ans=1;
	for(int i=1;i<=x;i++)ans=ans*i%mod;
	return ans;
}
int main()
{
	ll ans=0,dlt;
	scanf("%lld %lld %lld",&n,&m,&k);
	dlt=nok(n*m-2)*poww(nok(k-2),mod-2)%mod*poww(nok(n*m-k),mod-2)%mod;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ans=(ans+(1+n-i)*(n-i)/2*m%mod*dlt%mod)%mod;
			ans=(ans+(1+m-j)*(m-j)/2*n%mod*dlt%mod)%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
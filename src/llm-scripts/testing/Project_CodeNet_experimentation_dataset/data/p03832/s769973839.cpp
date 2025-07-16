#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define mod 1000000007
#define ll long long
using namespace std;
ll fac[N],inv[N],f[N];
ll ksm(ll a,ll b=mod-2)
{
	ll ans=1;
	for(;b;b>>=1)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int main()
{
	int n,l,r,lt,rt;
	scanf("%d%d%d%d%d",&n,&l,&r,&lt,&rt);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=ksm(fac[n]);
	for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	f[0]=1;
	for(int i=l;i<=r;i++)
		for(int j=min(i*rt,n);j>=i*lt;j--)
		{
			ll u=ksm(inv[i],lt);
			int v=j-i*lt;
			for(int k=lt;k<=rt;k++)
			{
				f[j]=(f[j]+fac[j]*u%mod*inv[v]%mod*inv[k]%mod*f[v])%mod;
				v-=i,u=u*inv[i]%mod;
				if(v<0) break;
			}
		}
	printf("%d\n",f[n]);
	return 0;
}

#include<cstdio>
typedef long long ll;
const ll mod=998244353;
inline ll rev(ll x)
{ll k=mod-2,r=1;for(;k;k>>=1,(x*=x)%=mod)if(k&1)(r*=x)%=mod;return r;}
ll fac[1111111],inv[1111111];
inline ll C(int n,int r)
{return((((fac[n]*inv[r])%mod)*inv[n-r])%mod);}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n<m)n^=m,m^=n,n^=m;
	fac[0]=inv[0]=1;
	register int i;
	for(i=1;i<=n+m;i++)fac[i]=(fac[i-1]*i)%mod;
	inv[n+m]=rev(fac[n+m]);
	for(i=n+m-1;i;i--)inv[i]=inv[i+1]*(i+1)%mod;
	ll ans=0;
	for(i=1;i<=m;i++)
		(ans+=C(i*2,i)*C(n+m-2*i,n-i))%=mod;
	(((ans*=rev(2*C(n+m,n)))%=mod)+=n+mod)%=mod;
	printf("%lld\n",ans);
}
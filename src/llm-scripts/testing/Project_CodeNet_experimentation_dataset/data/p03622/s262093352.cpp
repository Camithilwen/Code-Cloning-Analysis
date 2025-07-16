/*

https://www.cnblogs.com/SovietPower/p/9757375.html
*/
#include <cstdio>
#include <algorithm>
#define mod 998244353
const int N=1e6;

int fac[N+3],ifac[N+3];

inline int FP(int x,int k)
{
	int t=1;
	for(; k; k>>=1,x=1ll*x*x%mod)
		if(k&1) t=1ll*t*x%mod;
	return t;
}
#define C(n,m) (1ll*fac[n+m]*ifac[n]%mod*ifac[m]%mod)//C(n+m,n)

int main()
{
	int n,m; scanf("%d%d",&n,&m);
	if(n<m) std::swap(n,m);

	int lim=n+m; fac[0]=fac[1]=1;
	for(int i=1; i<=lim; ++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[lim]=FP(fac[lim],mod-2);
	for(int i=lim; i; --i) ifac[i-1]=1ll*ifac[i]*i%mod;

	long long ans=0;
	for(int i=1; i<=m; ++i) ans+=1ll*C(i,i)*C(n-i,m-i)%mod;
	ans=ans%mod*FP(C(n,m),mod-2)%mod*FP(2,mod-2)%mod;
	printf("%lld\n",(ans+n)%mod);

	return 0;
}
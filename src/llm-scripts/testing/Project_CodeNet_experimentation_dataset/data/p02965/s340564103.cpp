#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
const int N=3*1e6+100;
int n,m,fac[N],inv[N],a,b;
inline int m_pow(int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1) ans=(ans*a)%mod;
		b>>=1;
		a=(a*a)%mod; 
	}
	return ans;
}
inline int c(int n,int m)
{
	if (m>n) return 0;
	return (fac[n]*(inv[m]*inv[n-m]%mod)%mod)%mod;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	fac[0]=1;
	for (int i=1;i<=n+3*m;i++) fac[i]=(fac[i-1]*i)%mod;
	inv[n+3*m]=m_pow(fac[n+3*m],mod-2);
	for (int i=n+3*m-1;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%mod;
	for (int i=0;i<=m;i++)
	{
		if ((3*m-i)%2!=0) continue;
		a=(a+(c(n,i)*c(n+(3*m-i)/2-1,n-1))%mod)%mod;
	}
	for (int i=2*m+1;i<=3*m;i++) b=(b+c(n+3*m-i-2,n-2))%mod;
	b=(b*n)%mod;
	printf("%lld\n",(a-b+mod)%mod);
}
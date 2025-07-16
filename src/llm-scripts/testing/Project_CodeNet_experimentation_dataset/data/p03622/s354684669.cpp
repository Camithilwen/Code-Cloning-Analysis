#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int fac[1000005],inv[1000005],n,m;
inline int qpow(int a,int b)
{int tp=a,res=1;
while (b)
{if (b&1) res=1ll*res*tp%mod;
tp=1ll*tp*tp%mod;b>>=1;
}
return res;
}
inline int cal(int a,int b)
{return 1ll*(1ll*fac[a+b]*inv[a]%mod)*inv[b]%mod;}
int main (){
	int i,ans;
	scanf ("%d%d",&n,&m);
	if (n>m) swap(n,m);
	for (fac[0]=1,i=1;i<=n+m;i++)fac[i]=1ll*fac[i-1]*i%mod;
	for (inv[n+m]=qpow(fac[n+m],mod-2),i=n+m-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	int tot=cal(n,m),now=0;
	for (i=1;i<=n;i++)
	{now+=1ll*cal(i,i)*cal(n-i,m-i)%mod;
	if (now>=mod) now-=mod;
	}
	now=1ll*now*qpow(tot,mod-2)%mod;
	now=1ll*now*qpow(2,mod-2)%mod;
	now=(now+m>=mod?now+m-mod:now+m);
	printf ("%d\n",now);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
#define maxn 100005
#define int long long
int h,w,a,b,fac[maxn*2+5],inv[maxn*2+5];
inline int qpow(int x,int a)
{
	int ans=1;
	while(a)
	{
		if(a&1) ans=1ll*ans*x%p;
		x=1ll*x*x%p;
		a>>=1;
	}
	return ans;
}
inline void pre(int x=maxn*2)
{
	fac[0]=inv[0]=1;
	for(int i=1;i<=x;++i)
		fac[i]=1ll*fac[i-1]*i%p;
	inv[x]=qpow(fac[x],p-2);
	for(int i=x-1;i;--i)
		inv[i]=1ll*inv[i+1]*(i+1)%p;
}
inline int c(int x,int y)
{
	if(x<y) return 0;
	return 1ll*fac[x]*inv[y]%p*inv[x-y]%p;
}
signed main()
{
	scanf("%lld%lld%lld%lld",&h,&w,&a,&b);
	pre();
	int ans=c(h+w-2,h-1);
	for(int i=1;i<=b;++i)
		ans-=1ll*c(h-a+i-2,i-1)*c(w-i+a-1,a-1),ans%=p;
	ans=(ans%p+p)%p;
	printf("%lld\n",ans);
	return 0;
}
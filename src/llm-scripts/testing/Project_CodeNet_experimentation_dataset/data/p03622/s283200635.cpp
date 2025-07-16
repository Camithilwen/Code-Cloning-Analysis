#include<cstdio>
#include<algorithm>
using namespace std;
typedef __int128 LL;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
LL read()
{
	LL x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')	f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
void write(LL x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
const LL MOD=998244353;
LL QuickPow(LL x,LL p)
{
	LL base=x,ans=1;
	while(p)
	{
		if(p&1)	ans*=base,ans%=MOD;
		p>>=1;
		base*=base;
		base%=MOD;
	}
	return ans;
}
LL n,m,fac[1000005],inv[1000005];
LL C(LL n,LL m){return fac[n]*inv[m]%MOD*inv[n-m]%MOD;}
int main(){
	n=read(),m=read();
	fac[0]=fac[1]=1;
	for(LL i=2;i<=1000000;++i)	fac[i]=fac[i-1]*i%MOD;
	inv[1000000]=QuickPow(fac[1000000],MOD-2);
	for(LL i=1000000-1;~i;--i)	inv[i]=inv[i+1]*(i+1)%MOD;
	LL ans=0;
	for(LL i=1;i<=min(n,m);++i)
	{
		ans+=C(2*i,i)*C(n-i+m-i,n-i)%MOD;
		ans%=MOD;
	}
	ans*=inv[2];
	/*
	C(2n,n)
	*/
	ans*=inv[n+m];
	ans%=MOD;
	ans*=fac[n];
	ans%=MOD;
	ans*=fac[m];
	ans%=MOD;
	ans+=max(n,m);
	ans%=MOD;
	write(ans);
	puts("");
	return 0;
}
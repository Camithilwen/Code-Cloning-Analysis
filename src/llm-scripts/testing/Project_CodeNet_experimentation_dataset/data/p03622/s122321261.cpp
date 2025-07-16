#include<bits/stdc++.h>
#define mod 998244353
#define maxn 1000005
using namespace std;
typedef long long LL;
int read()
{
    char c=getchar();int f=1,sum=0;
    while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0' && c<='9'){sum=sum*10+c-'0';c=getchar();}
    return sum*f;
}
int n,m;
LL fac[maxn],inv[maxn],ans;
LL ksm(LL a,LL b){LL ret=1;while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}return ret;}
void init(int x)
{
	fac[0]=1;
	for(int i=1;i<=x;i++) fac[i]=fac[i-1]*i%mod;
	inv[x]=ksm(fac[x],mod-2);
	for(int i=x;i>=1;i--) inv[i-1]=inv[i]*i%mod;
}
LL calc(LL x,LL y){return fac[x+y]*inv[x]%mod*inv[y]%mod;}
int main()
{
	n=read();m=read();
	if(n>m) swap(n,m);
	init(n+m);
	for(int i=1;i<=n;i++) ans+=calc(i,i)*calc(n-i,m-i)%mod;
    ans=ans%mod*ksm(calc(n,m)<<1,mod-2)%mod;
    printf("%lld\n",(ans+m)%mod);
	return 0;
}

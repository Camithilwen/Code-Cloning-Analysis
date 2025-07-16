#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
const LL mod=1e9+7;
LL f[1010][1010],n,a,b,c,d,C[1010][1010],inv[1010][1010],fac[1010],finv[1010];
void pre()
{
	inv[0][1]=inv[1][1]=1;fac[0]=fac[1]=1;
	for(LL i=2;i<=1000;i++) inv[i][1]=(mod-mod/i)*inv[mod%i][1]%mod,fac[i]=fac[i-1]*i%mod;
	for(LL i=2;i<=1000;i++) inv[i][1]=inv[i-1][1]*inv[i][1]%mod;
	for(LL i=1;i<=1000;i++)
		for(LL j=2;j<=1000;j++) inv[i][j]=inv[i][1]*inv[i][j-1]%mod;
	for(LL i=1;i<=1000;i++)
		for(LL j=1;j<=i;j++) C[i][j]=fac[i]*inv[i-j][1]%mod;
}
LL get(LL x,LL y,LL i) {return C[x][i*y]*inv[y][i]%mod*inv[i][1]%mod;}
LL dfs(LL x,LL y)
{
	if(f[x][y]!=-1) return f[x][y];
	if(x==0) return 1;
	if(y<a) return 0;
	f[x][y]=0;
	for(LL i=c;i<=d;i++)
	{
		LL num=i*y;
		if(num<=x) (f[x][y]+=dfs(x-num,y-1)*get(x,y,i)%mod)%=mod;
		else break;
	}
	(f[x][y]+=dfs(x,y-1))%=mod;
	return f[x][y];
}
int main()
{
	pre();
	scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
	memset(f,-1,sizeof(f));
	printf("%lld",dfs(n,b));
}
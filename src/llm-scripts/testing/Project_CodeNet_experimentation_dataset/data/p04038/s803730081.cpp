#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=2010;
const int MOD=1e9+7;
int n,k;
long long fac[MAXN*MAXN],inv[MAXN*MAXN],f[MAXN][MAXN];
long long C(long long x,long long y)
{
	return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
long long qpow(long long x,long long y)
{
	long long tmp=1;
	for(;y;y>>=1,x=x*x%MOD)if(y&1)tmp=tmp*x%MOD;
	return tmp;
}
int main()
{
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		printf("1");
		return 0;
	}
	fac[0]=1;
	for(int i=1;i<=n*k;i++)fac[i]=fac[i-1]*i%MOD;
	inv[n*k]=qpow(fac[n*k],MOD-2);
	for(int i=n*k;i>=1;i--)inv[i-1]=inv[i]*i%MOD;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			f[i][j]=f[i-1][j];
			if(!j)continue;
			f[i][j]=(f[i][j]+f[i][j-1]*(n-j+1)%MOD*C(n-i+(n-j+1)*(k-1)-1,k-2))%MOD;
		}
	printf("%lld\n",f[n][n]);
	return 0;
}

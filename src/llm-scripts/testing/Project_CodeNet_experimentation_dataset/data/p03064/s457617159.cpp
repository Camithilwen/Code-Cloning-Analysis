#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=305;
const int MOD=998244353;
int n,m;
int a[N];
long long f[N][N*N],g[N][N*N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),m+=a[i];
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			f[i][j]=f[i-1][j]*2%MOD;
			if(j>=a[i]) f[i][j]=(f[i][j]+f[i-1][j-a[i]])%MOD;
		}
	long long ans=1;
	for(int i=1;i<=n;i++)
		ans=ans*3%MOD;
	for(int j=(m+1)/2;j<=m;j++)
		ans=(ans-f[n][j]*3%MOD+MOD)%MOD;
	if(m%2==0)
	{
		g[0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=m;j++)
			{
				g[i][j]=g[i-1][j];
				if(j>=a[i]) g[i][j]=(g[i][j]+g[i-1][j-a[i]])%MOD;
			}
		ans=(ans+g[n][m/2]*3%MOD)%MOD;
	}
	printf("%lld",ans);
	return 0;
}
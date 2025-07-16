#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;
#define N 6005
#define INF 0x3f3f3f3f
#define LL long long
int n,MOD,f[4][N*2];
int rd()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f*x;
}
int main()
{
	n=rd(),MOD=rd();
	f[0][N]=1;
	for(int i=1;i<=3*n;i++)
	{
		int l=N-(i-1),r=N+(i-1);
		for(int j=l;j<=r;j++)
		{
			for(int k=3;k>=1;k--)
				f[k][j]=f[k-1][j];
			f[0][j]=0;
		}
		for(int j=l;j<=r;j++)
		{
			f[0][j+1]=(f[0][j+1]+f[1][j])%MOD;
			int del=i-1;
			f[0][j-1]=(f[0][j-1]+1ll*f[2][j]*del%MOD)%MOD;
			del=1ll*(i-1)*(i-2)%MOD;
			f[0][j]=(f[0][j]+1ll*f[3][j]*del%MOD)%MOD;
		}
	}
	int ans=0;
	for(int i=N;i<=N+3*n;i++)
		ans=(ans+f[0][i])%MOD;
	printf("%d\n",ans);
	return 0;
}
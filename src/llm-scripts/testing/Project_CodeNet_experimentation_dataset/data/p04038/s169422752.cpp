#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define N 4000011
const int p=1e9+7;
int n,k,dp[2002][2002],inv[N],f[N],finv[N];
inline int C(int nn,int mm)
{
	if(mm==nn||mm==0)return 1;if(nn<mm)return 0;
	return 1ll*f[nn]*finv[mm]%p*finv[nn-mm]%p;
}
int main()
{
	f[1]=finv[1]=inv[1]=1;
	for(int i=2;i<=4000000;i++)
	{
		inv[i]=1ll*(p-p/i)*inv[p%i]%p;
		f[i]=1ll*f[i-1]*i%p;finv[i]=1ll*finv[i-1]*inv[i]%p;
	}
	scanf("%d%d",&n,&k);
	if(k==1){puts("1");return 0;}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)for(int j=0;j<=i;j++)
	{
		dp[i][j]=dp[i-1][j];
		if(j)(dp[i][j]+=1ll*C(n-i+(n-j+1)*(k-1)-1,k-2)*dp[i][j-1]%p)%=p;
	}
	printf("%d\n",1ll*dp[n][n]*f[n]%p);
}

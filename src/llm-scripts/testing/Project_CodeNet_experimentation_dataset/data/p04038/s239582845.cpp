#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
#define upd(a,b) a=add(a,b)
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int add(int a,const int b){a+=b;if(a>=Mod)a-=Mod;return a;}
int sub(int a,const int b){a-=b;if(a<0)a+=Mod;return a;}
int mul(const int a,const int b){return (ll)a*b%Mod;}
int power(int x,int cs)
{
	int ras=1;
	while(cs)
	{
		if(cs&1) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}
const int N=2020;
int n,K,tot,ans=0;
int dp[N][N],sum[N],zp[N*N],fp[N*N];
int C(int a,int b)
{
	if(a<0||b<0||a<b) return 0;
	return mul(zp[a],mul(fp[b],fp[a-b]));
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&K);
	if(K==1)
	{
		puts("1");
		return 0;
	}
	tot=n*K;
	zp[0]=fp[0]=1;
	for(i=1;i<=tot;i++) zp[i]=mul(zp[i-1],i);
	fp[tot]=inv(zp[tot]);
	for(i=tot-1;i>=1;i--) fp[i]=mul(fp[i+1],i+1);
	dp[1][0]=1;
	for(i=2;i<=n;i++)
	{
		memset(sum,0,sizeof(sum));
		for(j=0;j<=i;j++)
		{
			if(j>0) sum[j]=sum[j-1];
			upd(sum[j],dp[i-1][j]);
		}
		for(j=0;j<i;j++)
		{
			upd(dp[i][j],mul(sum[j],C(i*(K-1)+j-1,K-2)));
		}
	}
	for(i=0;i<=n;i++) upd(ans,dp[n][i]);
	ans=mul(ans,zp[n]);
	printf("%d",ans);
	return 0;
}
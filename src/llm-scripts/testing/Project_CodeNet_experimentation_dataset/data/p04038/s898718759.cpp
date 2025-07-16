#include<stdio.h>
#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 4000095
using namespace std;
int f[2005][2005],fac[maxn],inv[maxn];
int add(int a,int b){a+=b; return a>=mod?a-mod:a;}
int ksm(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1) s=1ll*s*a%mod;
	return s;
}
int n,k;
void Pre()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=1ll*fac[i-1]*i%mod;
	inv[maxn-1]=ksm(fac[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int C(int n,int m){return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	Pre();
	scanf("%d%d",&n,&k);
	if(k==1) return puts("1"),0;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			f[i][j]=f[i-1][j];
			if(j) f[i][j]=add(f[i][j],1ll*C(n*k-i-(j-1)*(k-1)-1,k-2)*(n-j+1)%mod*f[i][j-1]%mod);
		}
	}
	printf("%d\n",f[n][n]);
	return 0;
}

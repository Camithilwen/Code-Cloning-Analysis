#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=2005,Mod=1e9+7;
int dp[N][N],fac[N*N],inv[N*N];
inline int C(int n,int m){
	return 1ll*fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
inline int qpow(int a,int b){
	int ans=1;
	while (b){
		if (b&1) ans=1ll*ans*a%Mod;
		a=1ll*a*a%Mod,b>>=1;
	}
	return ans;
}
int main (){
	int n,k;scanf ("%d%d",&n,&k);
	if (k==1) {puts("1");return 0;}
	dp[0][0]=1;fac[0]=1;
	for (int i=1;i<=n*k;i++) fac[i]=1ll*fac[i-1]*i%Mod;
	inv[n*k]=qpow(fac[n*k],Mod-2);for (int i=n*k-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%Mod;
    for (int i=0;i<=n;i++) dp[i][0]=1;
	for (int i=1;i<=n;i++)
        for (int j=0;j<=i;j++)
            dp[i][j]=dp[i-1][j]+1ll*dp[i][j-1]*(n-j+1)%Mod*C(n*k-(i+(j-1)*(k-1))-1,k-2)%Mod,dp[i][j]%=Mod;
    printf ("%d",dp[n][n]);
	return 0;
}
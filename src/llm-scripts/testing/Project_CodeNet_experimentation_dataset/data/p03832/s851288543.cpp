#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005,M=1e9+7;
int n,A,B,C,D,fac[N],inv[N],dp[N][N];
int ksm(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=x*x%M)
		if (y&1)(ans*=x)%=M;
	return ans;	
}
signed main(){
	scanf("%lld%lld%lld%lld%lld",&n,&A,&B,&C,&D);
	dp[0][A-1]=1;
	fac[0]=inv[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	for (int i=0;i<=n;i++)
		for (int j=A;j<=B;j++){
			dp[i][j]=dp[i][j-1];
			for (int k=C,p=ksm(inv[j],C);k<=D;k++,(p*=inv[j])%=M){
				if (i-j*k<0)break;
				(dp[i][j]+=dp[i-j*k][j-1]*p%M*inv[k])%=M;
			}
		}
	printf("%lld\n",dp[n][B]*fac[n]%M);
} 

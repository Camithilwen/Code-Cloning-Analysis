#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define re register
#define LL long long
// #define MOD 1000000007
#define MAXN 6005
using namespace std;
const int ST=6002;
LL n,ans,MOD,dp[MAXN][MAXN<<1];
LL rd(){
	LL x=0,tp=1;char c;c=getchar();
	while(c<'0' || c>'9'){if(c=='-')tp=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x*10+c-'0');c=getchar();}
	return x*tp;
}
int add(int a,int b){return (a+b>=MOD)?(a+b-MOD):a+b;}
int main(){
	// freopen("testdata.in","r",stdin);
	// freopen("shit.out","w",stdout);
	n=rd()*3,MOD=rd();
	dp[0][ST]=1;
	for(int i=0;i<n;i++){
		for(int j=-i;j<=i;j++){
			dp[i+1][ST+j+1]=add(dp[i+1][ST+j+1],dp[i][ST+j]);
			dp[i+2][ST+j-1]=add(dp[i+2][ST+j-1],dp[i][ST+j]*(i+1)%MOD);
			dp[i+3][ST+j]=add(dp[i+3][ST+j],dp[i][ST+j]*(i+1)%MOD*(i+2)%MOD);
		}
	}
	for(int i=0;i<=n;i++)ans=add(ans,dp[n][ST+i]);
	printf("%lld\n",ans);
	// printf("%.2lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
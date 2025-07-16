#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=300+10;
const int MOD=998244353;
int n,a[N],dp[N][N*N],sum;

signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
	
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=sum;j++) {
			dp[i][j]=dp[i-1][j];
			if (j>=a[i]) dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]]*2)%MOD;
		}	
	
	int ans=0;
	for (int i=0;i<=sum/2;i++) ans=(ans+dp[n][i])%MOD;
	
	if (sum%2==0) {
		memset(dp,0,sizeof(dp)); dp[0][0]=1;
		for (int i=1;i<=n;i++)
			for (int j=0;j<=sum;j++) {
				dp[i][j]=dp[i-1][j];
				if (j>=a[i]) dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%MOD;
			}
		ans=((ans-dp[n][sum/2])%MOD+MOD)%MOD;		
	}
	ans=(ans*3)%MOD;
	
	int tmp=1;
	for (int i=1;i<=n;i++) tmp=(tmp*3)%MOD;
	cout<<((tmp-ans)%MOD+MOD)%MOD<<endl;
	return 0;
}
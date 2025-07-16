#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5;
const int mod=1e9+7;
int a[maxn+5],num[maxn+5],dp[maxn+5];
int x[1<<20],y[1<<20];
int n;
void update(int &x,int y)
{
	x=(x+y)%mod;
}
int main()
{

	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),a[i]^=a[i-1],num[i]=num[i-1]+(a[i]==0);
	for(int i=1;i<=n;++i) dp[i]=1;
	for(int i=1;i<=n;++i)
	{
		update(dp[i],(1LL*x[a[i]]*num[i]-y[a[i]])%mod);
		update(x[a[i]],dp[i]);
		update(y[a[i]],1LL*dp[i]*num[i]%mod);
	}
	if(dp[n]<0) dp[n]+=mod;
	if(a[n]>0) cout<<dp[n];
	else
	{
		int ans=1;
		for(int i=1;i<=num[n-1];++i) ans=ans*2%mod;
		for(int i=1;i<=n;++i)
			if(a[i]>0) update(ans,dp[i]);
		if(ans<0) ans+=mod;
		cout<<ans<<endl;
	}
	return 0;
}
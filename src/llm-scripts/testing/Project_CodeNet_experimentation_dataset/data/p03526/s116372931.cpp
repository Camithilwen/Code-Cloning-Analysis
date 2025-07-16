#include <bits/stdc++.h>
using namespace std;
const long long INF=1e18;
struct Node
{
	long long h,p,su;
};
Node N[5005];
bool cmp(Node a,Node b)
{
	if(a.su==b.su)
	{
		return a.h<b.h;
	}
	return a.su<b.su;
}
long long dp[5005];
int ans;
int main() {
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld %lld",&N[i].h,&N[i].p);
		N[i].su=N[i].h+N[i].p;
	}
	sort(N,N+n,cmp);
	for(int i=1;i<=n;i++)
	{
		dp[i]=INF;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j>=0;j--)
		{
			if(dp[j]!=INF&&dp[j]<=N[i].h)
			{
				dp[j+1]=min(dp[j+1],dp[j]+N[i].p);
			}
		}
	}
	ans=0;
	for(int i=0;i<=n;i++)
	{
		if(dp[i]!=INF)
		{
			ans=max(ans,i);
		}
		else
		{
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<int>e[1500001];
int dp[1500001];
int vis[1500001];
int dfs(int u)
{
	if(vis[u]==1){printf("-1");exit(0);}
	if(dp[u]) return dp[u];
	vis[u]=1;
	int ans=1;
	for(int i=0;i<e[u].size();i++)
	{
		//printf("%d::%d %d\n",u,e[u][i],dfs(e[u][i])+1);
		ans=max(ans,dfs(e[u][i])+1);
	}
	vis[u]=0;
	return dp[u]=ans;
}
int main() 
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int pre=0;
		for(int j=1;j<n;j++)
		{
			int x;
			scanf("%d",&x);
			int now=min(i,x)*n+max(i,x);
			e[pre].push_back(now);
			pre=now;
		}
	}
	int ans=dfs(0);
	printf("%d",ans-1);
	return 0;
}
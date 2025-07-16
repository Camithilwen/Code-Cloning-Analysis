%:pragma GCC optimize "-O3"
%:pragma GCC optimize("Ofast")
%:pragma GCC optimize("inline")
%:pragma GCC optimize("fast-math")
%:pragma GCC optimize("unroll-loops")
%:pragma GCC optimize("inline-functions")
%:pragma GCC optimize("no-stack-protector")
%:pragma GCC optimize("inline-small-functions")
%:pragma GCC optimize("inline-functions-called-once")
%:pragma GCC target("sse3","sse2","sse")
#include<bits/stdc++.h>
#define ll long long
#define heap priority_queue
using namespace std;
const ll maxn=15+1;
const ll inf=9e17;
ll ans,sum,dp[maxn][1<<maxn],dis[1<<maxn],g[maxn][maxn],tmp,lim,n,m;
inline ll lowbit(ll x){
	return x&-x;
}
int main()
{
	cin>>n>>m;
	ll u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		--u;
		--v;
		g[u][v]=g[v][u]=w;
		sum+=w;
	}
	lim=(1<<n)-1;
	for(int i=1;i<=lim;i++)
	{
		tmp=log2(lowbit(i));
		dis[i]=dis[i^(1<<tmp)];
		for(int j=0;j<n;j++)
			if(g[tmp][j]&&(i&(1<<j)))
				dis[i]+=g[tmp][j];
	}
	memset(dp,0xc0,sizeof(dp));
	dp[0][1]=0;
	ans=-inf;
	for(int i=1;i<=lim;i++)
	{
		if(!(i&1))
			continue;
		for(int j=0;j<n;j++)
			if(i&(1<<j))
			{
				for(int k=i;k;k=(k-1)&i)
					if(k&(1<<j))
						dp[j][i]=max(dp[j][i],dp[j][i^k^(1<<j)]+dis[k]);
				for(int k=lim^i;k;k-=lowbit(k))
				{
					tmp=log2(lowbit(k));
					if(g[tmp][j]) 
						dp[tmp][i^(1<<tmp)]=max(dp[tmp][i^(1<<tmp)],dp[j][i]+g[tmp][j]);
				}
			}
		if(i&(1<<(n-1)))
			ans=max(ans,dp[n-1][i]);
	}
	cout<<sum-ans<<"\n";
	return 0;
}
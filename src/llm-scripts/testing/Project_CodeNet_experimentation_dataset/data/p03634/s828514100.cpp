#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
const int inf=1e18;
inline int in(){int x;scanf("%lld",&x);return x;}
#define x first
#define y second
int32_t main()
{	
	int n=in();
	vector<vector<pair<int,int>>> g(n);
	int u,v,w;
	for(int i=1;i<n;i++)
	{
		u=in();v=in();w=in();
		u--;v--;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	
	int Q=in();int K=in();K--;
	
	queue<int> q;
	q.push(K);
	vector<int> dis(n,inf);
	dis[K]=0;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(auto v:g[u])
		{
			if(dis[v.x]!=inf)continue;
			dis[v.x]=min(dis[v.x],dis[u]+v.y);
			q.push(v.x);
		}
	}
	while(Q--)
	{
		u=in();v=in();
		cout<<dis[u-1]+dis[v-1]<<"\n";
	}
	
	
}
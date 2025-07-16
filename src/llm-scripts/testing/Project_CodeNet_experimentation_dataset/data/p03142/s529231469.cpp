#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

vector<int> topological_order(const graph& D){
	int n=D.size();
	vector<int> deg(n);
	rep(u,n) for(int v:D[u]) deg[v]++;

	vector<int> res;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		res.emplace_back(u);
		for(int v:D[u]) if(--deg[v]==0) Q.emplace(v);
	}
	return res;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	m+=n-1;
	graph G(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_directed_edge(G,u,v);
	}

	vector<int> dp(n);
	for(int u:topological_order(G)){
		for(int v:G[u]) dp[v]=max(dp[v],dp[u]+1);
	}

	vector<int> ans(n,-1);
	rep(u,n) for(int v:G[u]) if(dp[v]==dp[u]+1) ans[v]=u;
	rep(u,n) printf("%d\n",ans[u]+1);

	return 0;
}

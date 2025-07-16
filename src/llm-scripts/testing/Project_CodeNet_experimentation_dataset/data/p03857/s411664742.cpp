#include <bits/stdc++.h>
using namespace std;

const int maxN = 200010;
typedef long long ll;

int vis[2][maxN];
vector<int> G[2][maxN];

queue<int> Q;
void bfs(int u, int d, int c){
	while(!Q.empty()) Q.pop();
	vis[d][u] = c; Q.push(u);
	while(!Q.empty()){
		u = Q.front(); Q.pop();
		for(int i = 0; i < G[d][u].size(); ++i){
			int v = G[d][u][i];
			if(!vis[d][v]) vis[d][v] = c, Q.push(v);
		}
	}
}

map<ll, int> mp;

int main (){
	int n, k, l, u, v, i, c0 = 0, c1 = 0;
	scanf("%d%d%d", &n, &k, &l);
	while(k--){
		scanf("%d%d", &u, &v);
		G[0][u].push_back(v);
		G[0][v].push_back(u);
	}
	while(l--){
		scanf("%d%d", &u, &v);
		G[1][u].push_back(v);
		G[1][v].push_back(u);
	}
	for(i = 1; i <= n; ++i) if(!vis[0][i]) bfs(i, 0, ++c0);
	for(i = 1; i <= n; ++i) if(!vis[1][i]) bfs(i, 1, ++c1);
	for(i = 1; i <= n; ++i) ++mp[vis[0][i] * 1ll * maxN + vis[1][i]];
	for(i = 1; i <= n; ++i){
		printf("%d", mp[vis[0][i] * 1ll * maxN + vis[1][i]]);
		if(i < n) printf(" ");
	}
	return 0;
}

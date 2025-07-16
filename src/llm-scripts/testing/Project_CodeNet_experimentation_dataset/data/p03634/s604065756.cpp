#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX_N = 1e5+20;
int n;
int a[MAX_N],b[MAX_N],c[MAX_N];
int Q, K;
int x[MAX_N], y[MAX_N];

struct edge { int to,  cost; };
vector<edge> G[MAX_N];
ll dist[MAX_N];

void add_edge(int from, int to, int cost)
{
	G[from].push_back(edge{to, cost});
	G[to].push_back(edge{from, cost});
}

void dfs(int x, ll d)
{
	dist[x] = d;
	for(auto e : G[x]){
		int t = e.to, c = e.cost;
		if(dist[t] == INF){
			dfs(t, d+c);
		}
	}
}
 
void solve()
{
	for(int i=0;i<n-1;++i) add_edge(a[i],b[i],c[i]);
	memset(dist,0x3f,sizeof(dist));
	dfs(K, 0);
	for(int i=0;i<Q;++i){
		cout<<dist[x[i]]+dist[y[i]]<<'\n';
	}
}

int main()
{
	cin >> n;
	for(int i=0;i<n-1;++i){
		cin >> a[i] >> b[i] >> c[i];
	}
	cin >> Q >> K;
	for(int i=0;i<Q;++i){
		cin >> x[i] >> y[i];
	}
	solve();
	return 0;
}
// Enjoy your stay.

#include <bits/stdc++.h>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

const int MAXN = 100010;

int n;
vector<int> g[100010];

int zeit, dis[MAXN], fin[MAXN], low[MAXN], par[MAXN], dep[MAXN];
int kodat[MAXN], koptr[MAXN + 1];
void dfsInfo(int u,int oy,int d){
	dis[u] = low[u] = zeit++; par[u] = oy; dep[u] = d;
	int v;
	rep(i,sz(g[u])) if((v = g[u][i]) != oy){
		if(!~dis[v]){
			dfsInfo(v, u, d + 1);
			low[u] = min(low[u], low[v]);
		} else {
			low[u] = min(low[u], dis[v]);
		}
	}
	fin[u] = zeit++;
}

void dfsInfos(){
	memset(dis, ~0, n*4); zeit = 0;
	rep(u,n) if(!~dis[u]) dfsInfo(u, -1, 0);
	rep(u,n){
		int &j = koptr[u + 1] = koptr[u];
		rep(i,sz(g[u])) if(u == par[g[u][i]]) kodat[j++] = g[u][i];
	}
}

bool produce(int u,int v){
	return (dis[u] <= dis[v] && fin[u] >= fin[v]);
}

int related(int u,int v){
	int s = koptr[u], e = koptr[u+1], h;
	while(s+1 < e){
		h = (s + e) >> 1;
		(dis[kodat[h]] <= dis[v]) ? s = h : e = h;
	}
	return kodat[s];
}

bool isBridge(int u,int v){
	if(dis[u] > dis[v]) swap(u, v);
	return (u == par[v] && dis[v] <= low[v]);
}

int Count[MAXN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int m;
	cin>>n>>m;
	rep(i,m){
		int a,b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	rep(i,n)sort(g[i].begin(),g[i].end());
	dfsInfos();
	Count[0] = -1;
	rep(i,n)rep2(j,koptr[i],koptr[i+1]){
		Count[i] += dis[i] <= low[kodat[j]];
	}
	rep(i,n){
		if(Count[i] > 0)cout<<i<<endl;
	}
	//rep(i,n)cout<<Count[i]<<" ";cout<<endl;
}
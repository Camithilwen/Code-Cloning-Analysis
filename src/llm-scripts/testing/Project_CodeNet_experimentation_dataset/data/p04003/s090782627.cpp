//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll maxm = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, t, d[maxm];
bool vis[maxm];
pair<pll, ll> e[maxn];
vector<ll> g[maxm], p[maxn], dsu[maxm], sz[maxm];
map<ll, ll> mp[maxn];
queue<ll> q;

ll root(ll c, ll v){
	if(dsu[c][v] != v) dsu[c][v] = root(c, dsu[c][v]);
	return dsu[c][v];
}

void Union(ll c, ll v, ll u){
	v = root(c, v);
	u = root(c, u);
	if(v == u) return;
	if(sz[c][v] < sz[c][u]) swap(v, u);
	dsu[c][u] = v;
	sz[c][v] += sz[c][u];
	return;
}

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		cin >> v >> u >> c;
		p[v].pb(c);
		p[u].pb(c);
		if(mp[v][c] == 0){
			dsu[c].pb(dsu[c].size());
			sz[c].pb(1);
			mp[v][c] = dsu[c].size();
		}
		if(mp[u][c] == 0){
			dsu[c].pb(dsu[c].size());
			sz[c].pb(1);
			mp[u][c] = dsu[c].size();
		}
		e[i] = Mp(Mp(v, u), c);
	}
	for(ll i = 0; i < m; i++){
		v = e[i].F.F;
		u = e[i].F.S;
		c = e[i].S;
		Union(c, mp[v][c] - 1, mp[u][c] - 1);
	}
	t = n + 1;
	for(ll i = 1; i < maxm; i++){
		for(ll j = 0; j < dsu[i].size(); j++){
			if(dsu[i][j] == j) sz[i][j] = t++;
		}
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < p[i].size(); j++){
			g[i].pb(sz[p[i][j]][root(p[i][j], mp[i][p[i][j]] - 1ll)]);
			g[sz[p[i][j]][root(p[i][j], mp[i][p[i][j]] - 1ll)]].pb(i);
		}
	}
	q.push(1);
	vis[1] = 1;
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i];
			if(!vis[u]){
				vis[u] = 1;
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
	}
	if(!vis[n]) cout << -1;
	else cout << d[n] / 2;
	
	return 0;
}

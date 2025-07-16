#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define rep(i,l,r) for(int i=(l);i<(r);++i)
typedef long long ll;
typedef pair<int,int> pii;
const int N = 5e5 + 7;
//--------head---------
struct Edge {
	int u, v, c;
	void in() {
		cin >> u >> v >> c;	
	}
} E[N];
int n, m, tot;
map<pii, int> R;
map<pii, int>::iterator it;
vector<pii> e[N];
void ins(int u, int c) {
	pii p = mp(u, c);
	if (R.find(p) == R.end())
		R[p] = ++tot;
}
void addEdge(int u, int v, int c) {
	int x = R[mp(u, c)], y = R[mp(v, c)];
	e[x].pb(mp(v, 0)), e[x].pb(mp(y, 0));
}
bool vis[N];
int dis[N];
priority_queue<pii> que;
int solve() {
	rep(i, 0, tot + 1)
		vis[i] = false, dis[i] = -1;
	que.push(mp(0, 1));
	while (!que.empty()) {
		int u = que.top().second, d = -que.top().first;
		que.pop();
		if (vis[u])
			continue;
		dis[u] = d, vis[u] = true;
		rep(i, 0, sz(e[u])) {
			int v = e[u][i].first, w = e[u][i].second;
			if (!vis[v])
				que.push(mp(-(d + w), v));
		}
	}
	int ans = dis[n];
	rep(i, 0, sz(e[n])) {
		int v = e[n][i].first;
		if (~dis[v] && (ans == -1 || dis[v] < ans))
			ans = dis[v];
	}
	return ans;
}
int main() {
	cin >> n >> m;
	tot = n;
	rep(i, 0, m) {
		E[i].in();
		ins(E[i].u, E[i].c), ins(E[i].v, E[i].c);
	}
	for (it = R.begin(); it != R.end(); ++it) {
		pii p = it->first;
		int v = it->second;
		e[p.first].pb(mp(v, 1));
	}
	rep(i, 0, m) {
		int u, v, c;
		u = E[i].u, v = E[i].v, c = E[i].c;
		addEdge(u, v, c), addEdge(v, u, c);
	}
	cout << solve() << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

vector<int> con[N];

int root[N];
inline int find_root(int u) {
	if (u == root[u]) return root[u];
	return root[u] = find_root(root[u]);
}

int vis[N];
vector<int> cur;
void dfs(int u) {
	vis[u] = 1;
	cur.push_back(u);
	for (int v : con[u]) if (!vis[v]) dfs(v);
}

int cnt[N];
int ans[N];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) root[i] = i;
	while (m--) {
		int u, v; cin >> u >> v;
		int a = find_root(u), b = find_root(v);
		if (a == b) continue;
		root[a] = b;
	}
	while (k--) {
		int u, v; cin >> u >> v;
		con[u].push_back(v), con[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		cur.clear();
		dfs(i);
		for (auto u : cur) cnt[find_root(u)] = 0;
		for (auto u : cur) cnt[find_root(u)]++;
		for (auto u : cur) ans[u] = cnt[find_root(u)];
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
	
	return 0;
}

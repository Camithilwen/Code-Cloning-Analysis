#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

vector<int> con[N];
int vis[N];

bool dfs(int u, int col) {
	vis[u] = col;
	for (int v : con[u]) {
		if (vis[v] && 3 - col != vis[v]) return false;
		if (!vis[v] && !dfs(v, 3 - col)) return false;
	}
	return true;
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		con[u].push_back(v), con[v].push_back(u);
	}
	
	if (!dfs(1, 1)) cout << (long long)n * (n - 1) / 2 - m << "\n";
	else {
		int cnt = 0;
		for (int i = 1; i <= n; i++) cnt += vis[i] == 1;
		cout << (long long)cnt * (n - cnt) - m << "\n";
	}
	
	return 0;
}

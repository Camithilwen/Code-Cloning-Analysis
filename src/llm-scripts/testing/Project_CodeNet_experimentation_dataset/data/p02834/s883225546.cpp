#include <iostream>
#include <vector>
using namespace std;

struct edge
{
	int to, d;
};

vector<vector<edge>> g;
int b[100000];
int n, u, v;

int dfs(int v, int parent) {
	int res = 0;
	for (edge &ne : g[v]) {
		if (ne.to == parent) continue;
		ne.d = 1;
		int now = dfs(ne.to, v) + 1;
		res = max(res, now);
	}
	b[v] = res;
	return res;
}

int main() {
	cin >> n >> u >> v;
	u--; v--;
	g.assign(n, vector<edge>());
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back({b, 0});
		g[b].push_back({a, 0});
	}
	dfs(v, -1);
	int dist = 0;
	for (int i = u; i != v; ) {
		for (edge e : g[i]) {
			if (e.d == 0) {i = e.to; break;}
		}
		dist++;
	}
	int ans = 0;
	while (dist > 2) {
		for (edge e : g[u]) {
			if (e.d == 0) {u = e.to; break;}
		}
		dist -= 2;
		ans++;
	}
	ans += dist + b[u] - 1;
	cout << ans << endl;
	return 0;
}
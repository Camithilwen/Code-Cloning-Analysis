#include <iostream>
#include <vector>
using namespace std;
const int V_MAX = 100000;

struct LowLink
{
	const vector<vector<int>> &g;
	int V;
	vector<vector<int>> dfs_tree;
	vector<int> dfs_roots;
	int pre_order[V_MAX];
	int p_ord = 0;
	int lowlink[V_MAX];
	bool articulation[V_MAX] = {};
	vector<pair<int, int>> bridge;

	LowLink(const vector<vector<int>> &g) : g(g), V(g.size()), dfs_tree(g.size()) {}

	void dfs(int v, int parent) {
		lowlink[v] = pre_order[v] = p_ord;
		p_ord++;
		for (int nv : g[v]) {
			if (nv == parent) continue;
			if (pre_order[nv] == -1) {
				dfs_tree[v].push_back(nv);
				dfs(nv, v);
				lowlink[v] = min(lowlink[v], lowlink[nv]);
			}
			lowlink[v] = min(lowlink[v], pre_order[nv]);
		}
	}

	void calc() {
		p_ord = 0;
		fill(pre_order, pre_order+V_MAX, -1);
		for (int i = 0; i < V; i++) {
			if (pre_order[i] != -1) continue;
			dfs_roots.push_back(i);
			dfs(i, -1);
		}
		for (int i = 0; i < V; i++) {
			for (int j : dfs_tree[i]) {
				if (pre_order[i] < lowlink[j]) bridge.push_back({i, j});
			}
		}
		for (int i = 0, x = 0; i < V; i++) {
			bool ok = false;
			if (x < dfs_roots.size() && dfs_roots[x] == i) {
				if (dfs_tree[i].size() > 1) ok = true;
				x++;
			} else {
				for (int j : dfs_tree[i]) {
					if (pre_order[i] <= lowlink[j]) ok = true;
				}
			}
			articulation[i] = ok;
		}
	}
};

int main() {
	int V, E;
	cin >> V >> E;
	vector<vector<int>> g(V);
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	LowLink L(g);
	L.calc();
	for (int i = 0; i < V; i++) {
		if (L.articulation[i]) cout << i << endl;
	}
	return 0;
}

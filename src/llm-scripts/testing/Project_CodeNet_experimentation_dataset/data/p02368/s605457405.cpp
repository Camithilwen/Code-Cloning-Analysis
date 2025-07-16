#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
	int src, dst;
	Edge() : src(0), dst(0) {}
	Edge(int s, int d) : src(s), dst(d) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;

vector<int> kosaraju(const Graph &g) {
	int n = g.size(), sz = 0; Graph rg(n);
	vector<int> stk, cmp(n, -1), added(n), visited(n), ord(n);
	for(auto &es : g) {
		sz += es.size();
		for(const Edge &e : es) rg[e.dst].emplace_back(e.dst, e.src);
	}
	stk.resize(n + sz); sz = 0;
	for(int i = 0; i < n; i++) {
		if(visited[i]) continue;
		int s = 0; stk[s++] = i;
		while(s != 0) {
			int v = stk[s - 1]; visited[v] = true;
			bool pushed = false;
			for(auto &e : g[v]) {
				int dst = e.dst;
				if(!visited[dst]) { stk[s++] = dst; pushed = true; }
			}
			if(pushed) continue;
			int t = stk[s - 1];
			if(!added[t]) { added[t] = true; ord[n - ++sz] = t; }
			--s;
		}
	}
	int k = 0;
	for(int &u : ord) {
		if(cmp[u] != -1) continue;
		int s = 0; stk[s++] = u;
		while(s != 0) {
			int v = stk[--s]; cmp[v] = k;
			for(auto &e : rg[v]) {
				int d = e.dst;
				if(cmp[d] == -1) stk[s++] = d;
			}
		}
		++k;
	}
	return cmp;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int V, E, Q;
	cin >> V >> E;

	Graph G(V);
	for(int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back({ u, v });
	}

	auto res = kosaraju(G);
	cin >> Q;
	while(Q--) {
		int u, v;
		cin >> u >> v;
		cout << (res[u] == res[v]) << endl;
	}
}
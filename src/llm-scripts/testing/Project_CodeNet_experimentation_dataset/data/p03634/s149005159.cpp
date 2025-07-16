#include "bits/stdc++.h"
using namespace std;
vector<long long>Col(100005);
struct Edge {
	int to, id;
	Edge(int to, long long id) :to(to), id(id) {}
};
vector<Edge>g[100005];

void dfs(int v, long long d = 0, int p = -1) {
	Col[v] = d;
	for (Edge e : g[v]) {
		if (p == e.to) {
			continue;
		}
		dfs(e.to, d + e.id, v);
	}
}

int main() {
	int N;
	cin >> N;
	for (int n = 0; n < N - 1; ++n) {
		int a, b;
		long long c;
		cin >> a >> b >>c;
		a--;
		b--;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	int Q,K;
	cin >> Q >> K;
	K--;
	dfs(K);
	for (int i = 0;i<Q;++i) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		cout << Col[x]+Col[y]<<endl;
	}
	return 0;
}
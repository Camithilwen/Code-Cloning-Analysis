#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct UnionFind {
	vector<int> par;
	UnionFind(int n) :par(n) {
		for (int i = 0; i < n; i++) {
			par[i] = i;
		}
	}
	int root(int x) {
		return par[x] == x ? x : par[x] = root(par[x]);
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	void merge(int x, int y) {
		int rx = root(x), ry = root(y);
		if (rx == ry)return;
		par[rx] = ry;
	}
};

int main() {
	int n; cin >> n;
	vector<long long>x(n), y(n);
	for (int i = 0; i < n; i++)cin >> x[i] >> y[i];
	using P = pair<int, int>; using edge = pair<long long, P>;
	vector<edge>edges;
	vector<int>ids(n);
	for (int i = 0; i < n; i++)ids[i] = i;
	sort(ids.begin(), ids.end(), [&](int i, int j) {return x[i] < x[j]; });
	for (int i = 0; i < n - 1; i++) {
		int u = ids[i], v = ids[i + 1];
		edges.push_back(edge(x[v] - x[u], P(u, v)));
	}
	sort(ids.begin(), ids.end(), [&](int i, int j) {return y[i] < y[j]; });
	for (int i = 0; i < n - 1; i++) {
		int u = ids[i], v = ids[i + 1];
		edges.push_back(edge(y[v] - y[u], P(u, v)));
	}
	sort(edges.begin(), edges.end());
	UnionFind uf(n);
	long long ans = 0;
	for (auto e : edges) {
		int u = e.second.first, v = e.second.second;
		long long cost = e.first;
		if (uf.same(u, v))continue;
		uf.merge(u, v);
		ans += cost;
	}
	cout << ans << endl;
	return 0;
}
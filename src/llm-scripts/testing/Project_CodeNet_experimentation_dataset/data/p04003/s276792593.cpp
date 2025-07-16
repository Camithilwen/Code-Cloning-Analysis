#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  __MAKE_TIME__  Problem: __PROBLEM__ / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

struct UnionFind {
	vector<int> data;
	UnionFind() {}
	UnionFind(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
	void initV(int x) { data[x] = -1; }
};


UnionFind uf(1e5);
vector<vector<PII>> f(const vector<PII>&edge) {
	for (const auto& it : edge) {
		uf.initV(it.first);
		uf.initV(it.second);
	}
	for (const auto& it : edge) {
		uf.unionSet(it.first, it.second);
	}
	int rootid = 0;
	unordered_map<int, int>roots; // mapでもたいしてかわらない
	for (const auto& it : edge) {
		if (roots.find(uf.root(it.first)) == roots.end()) {
			roots[uf.root(it.first)] = rootid++;
		}
	}

	vector<vector<PII>>res(rootid);
	for (const auto& it : edge) {
		res[roots[uf.root(it.first)]].push_back(it);
	}
	return res;

}


VI Dijkstra(vector<vector<PII>>& G, int s) {// BFS
	VI dist(SZ(G), INF);
	dist[s] = 0;
	queue<PII> que;
	que.push(PII(0, s));

	while (!que.empty()) {
		PII p = que.front(); que.pop();
		int v; /* 頂点*/ int d; /* 頂点vまでの距離 */
		tie(d, v) = p;

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			if (dist[nv] > dist[v] + G[v][i].second) {
				dist[nv] = dist[v] + G[v][i].second;
				que.push(PII(dist[nv], nv));
			}
		}
	}
	return dist;
}
int read() { int in; scanf("%d", &in); return in; }
const int Max = 1e6;
vector<PII>Cedge[Max];
int main() {
	LL N = read(), M = read();

	FOR(i, 0, M) {
		int p = read() - 1, q = read() - 1, c = read() - 1;
		Cedge[c].push_back(PII(p, q));
	}
	vector<vector<PII>>G(N + M);
	int cid = N;
	FOR(c, 0, 1e6) {
		auto res = f(Cedge[c]);
		for (auto subedges : res) {
			for (auto e : subedges) {
				G[cid].push_back(PII(e.first, 1));
				G[e.first].push_back(PII(cid, 1));
				G[cid].push_back(PII(e.second, 1));
				G[e.second].push_back(PII(cid, 1));
			}
			cid++;
		}
	}
	auto res = Dijkstra(G, 0);
	LL ans = res[N - 1] / 2;
	if (ans == INF / 2)ans = -1;
	cout << ans << "\n";

	return 0;
}
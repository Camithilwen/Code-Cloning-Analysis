#include <bits/stdc++.h>
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
};


auto f(const vector<PII>&edge) {

	int id = 0;
	map<int, int>M; {
		for (const auto& it : edge) {
			if (M.find(it.first) == M.end()) {
				M[it.first] = id++;
			}
			if (M.find(it.second) == M.end()) {
				M[it.second] = id++;
			}
		}
	}
	const int sz = id;
	UnionFind uf(sz);
	map<int, int>roots;
	for (const auto& it : edge) {
		uf.unionSet(M[it.first], M[it.second]);
	}
	int rootid = 0;
	for (const auto& it : edge) {
		if (roots.find(uf.root(M[it.first])) == roots.end()) {
			roots[uf.root(M[it.first])] = rootid++;
		}
		//if (roots.find(uf.root(M[it.second])) == roots.end()) {
		//	// これはあってはならない
		//	assert(0);
		//	roots[uf.root(M[it.second])] = rootid++;
		// }
	}

	vector<vector<PII>>res(rootid);
	for (const auto& it : edge) {
		res[roots[uf.root(M[it.first])]].push_back(it);
	}
	return res;

}


VL Dijkstra(vector<vector<PLL>>& G, int s) {
	VL dist(SZ(G), LINF);
	dist[s] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL>> que;
	que.push(PLL(0LL, s));

	while (!que.empty()) {
		PLL p = que.top(); que.pop();
		int v; /* 頂点*/ long long d; /* 頂点vまでの距離 */
		tie(d, v) = p;

		if (d > dist[v]) continue;

		FOR(i, 0, (int)G[v].size()) {
			int nv = G[v][i].first;
			if (dist[nv] > dist[v] + G[v][i].second) {
				dist[nv] = dist[v] + G[v][i].second;
				que.push(PLL(dist[nv], nv));
			}
		}
	}
	return dist;
}
int read() { int in; scanf("%d", &in); return in; }

int main() {
	LL N = read(), M = read();

	vector<vector<PII>>Cedge(1e6);
	FOR(i, 0, M) {
		int p = read() - 1, q = read() - 1, c = read() - 1;
		Cedge[c].push_back(PII(p, q));
	}
	vector<vector<PLL>>G(N + 1e6); // 2Nでいい?
	int cid = N;

	FOR(c, 0, 1e6) {
		auto res = f(Cedge[c]);
		for (auto subedges : res) {
			set<int>used;
			for (auto e : subedges) {
				if (used.find(e.first) == used.end()) {
					G[cid].push_back(PLL(e.first, 1));
					G[e.first].push_back(PLL(cid, 1));
					used.insert(e.first);
				}
				if (used.find(e.second) == used.end()) {
					G[cid].push_back(PLL(e.second, 1));
					G[e.second].push_back(PLL(cid, 1));
					used.insert(e.second);
				}

			}
			cid++;
		}
	}
	auto res = Dijkstra(G, 0);
	LL ans = res[N - 1] / 2;
	if (ans == LINF / 2)ans = -1;
	cout << ans << "\n";

	return 0;
}
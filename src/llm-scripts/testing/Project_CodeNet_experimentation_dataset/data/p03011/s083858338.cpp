
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e15;
static const ll mod = 1e9+7;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

struct MaxFlowCalculator {
	int max_flow(int s, int t, const vector<vector<pair<int, int>>>& g) {
		struct edge_ { int to, cap, rev; };
		vector<bool> used(g.size(), false);
		vector<vector<edge_>> G(g.size());
		for (int i = 0; i < g.size(); i++) for (int j = 0; j < g[i].size(); j++)
		{
			int from = i, to = g[i][j].second;
			int cap = g[i][j].first;
			G[from].push_back({ to, cap, (int)G[to].size() });
			G[to].push_back({ from, 0, (int)G[from].size() - 1 });
		}
		auto dfs = [&](auto&& f, int v, int t, int fl)->int {
			if (v == t) return fl;
			used[v] = true;
			rep(i, G[v].size()) {
				edge_& e = G[v][i];
					if (!used[e.to] && e.cap > 0) {
					int d = f(f, e.to, t, min(fl, e.cap));
					if (d > 0) {
						e.cap -= d;
						G[e.to][e.rev].cap += d;
						return d;
					}
				}
			}
			return 0;
		};
		int flow = 0;
		while (1) {
			used.assign(used.size(), false);
			int f = dfs(dfs, s, t, INT_MAX);
			if (f == 0) return flow;
			flow += f;
		}
	}
};

int main() {
	ll p, r, q;
	cin >> p >> r >> q;
	ll a1 = p + r;
	ll a2 = r + q;
	ll a3 = p + q;
	cout << min(a1, min(a2, a3)) << endl;
    return 0;
}

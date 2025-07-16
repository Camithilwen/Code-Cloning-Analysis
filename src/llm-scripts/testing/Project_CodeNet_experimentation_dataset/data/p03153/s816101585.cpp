#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
 
class unionfind {
	vector<int> par, rank;
 
public:
	void init(int n) {
		par.resize(n);
		rank.resize(n);
 
		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
		}
	}
 
	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}
 
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return ;
 
		if (rank[x] < rank[y]) par[x] = y;
		else {
			par[y] = x;
			if (rank[x] == rank[y]) ++rank[x];
		}
	}
 
	bool same(int x, int y) { return (find(x) == find(y)); }
} uf;
 
const int MN = 200010;
 
using P = pair<ll, int>;
 
vector<pii> g[MN];
int col[MN];
ll X[MN];
vector<P> dp[MN];
 
void mergevec(vector<P>& a, vector<P> b) {
	for (auto p : b) {
		a.eb(p);
	}
	sort(ALL(a));
 
	set<int> st;
	vector<P> res;
 
	for (P p : a) {
		if (res.size() == 2) {
			break;
		}
		if (!st.count(p.se)) {
			st.insert(p.se);
			res.eb(p);
		}
	}
	a = res;
}
 
void dfs_up(int v, int p) {
	dp[v].eb(X[v], col[v]);
 
	for (pii e : g[v]) {
		if (e.fi != p) {
			dfs_up(e.fi, v);
 
			vector<P> nx;
 
			for (auto t : dp[e.fi]) {
				nx.eb(t.fi + e.se, t.se);
			}
 
			mergevec(dp[v], nx);
		}
	}
}
 
void dfs_down(int v, int p, int pw) {
	if (p != -1) {
		vector<P> nx;
		for (auto t : dp[p]) {
			nx.eb(t.fi + pw, t.se);
		}
		mergevec(dp[v], nx);
	}
 
	for (pii e : g[v]) {
		if (e.fi != p) {
			dfs_down(e.fi, v, e.se);
		}
	}
}
 
int N, D;
 
int main() {
	cin >> N >> D;
	rep(i, N) cin >> X[i];
 
	rep(i, N-1) {
		int a = i;
		int b = i + 1;
		int c = D;
		g[a].eb(b, c);
		g[b].eb(a, c);
	}
 
	uf.init(N);
	rep(i, N) {
		col[i] = i;
	}
 
	ll ans = 0;
 
	while (true) {
		bool one = true;
		for (int i = 1; i < N; ++i) {
			if (col[i] != col[0]) {
				one = false;
			}
		}
		if (one) {
			break;
		}
 
		rep(i, N) {
			dp[i].clear();
		}
 
		vector<P> mt(N, mp(LLONG_MAX, -1));
 
		dfs_up(0, -1);
		dfs_down(0, -1, -1);
 
		rep(i, N) {
			for (P p : dp[i]) {
				if (p.se != col[i]) {
					mt[col[i]] = min(mt[col[i]], mp(p.fi + X[i], p.se));
					break;
				}
			}
		}
 
		rep(i, N) if (mt[i] != mp(LLONG_MAX, -1)) {
			int u = i, v = mt[i].se;
			ll cost = mt[i].fi;
			if (!uf.same(u, v)) {
				uf.unite(u, v);
				ans += cost;
			}
		}
 
		rep(i, N) {
			col[i] = uf.find(col[i]);
		}
	}
 
	cout << ans << endl;
 
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Template Headers {{{
using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long; using vll = vector<long long>;
template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T> istream &operator>>(istream &, vector<T> &);
template <class T> ostream &operator<<(ostream &, const vector<T> &);
template <class T, class U> istream &operator>>(istream &, pair<T, U> &);
template <class T, class U> ostream &operator<<(ostream &, const pair<T, U> &);
template <class T> struct Inf { static constexpr T inf() { return std::numeric_limits<T>::has_infinity() ? std::numeric_limits<T>::infinty() : std::numeric_limits<T>::max(); } };
template <> struct Inf<int> { static constexpr int inf() { return 0x3f3f3f3f; } };
template <> struct Inf<long long> { static constexpr long long inf() { return 0x3f3f3f3f3f3f3f3fLL; } };
constexpr int INF = Inf<int>::inf(); constexpr ll BINF = Inf<ll>::inf();
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// }}}

int solve() {
	int n, m; cin >> n >> m;
	vvi g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v); g[v].push_back(u);
	}
	int timer = 0;
	vi stTime(n, INF), enTime(n, INF);
	vi low(n);
	vi ans(n);
	function<void(int, int)> dfs = [&] (int u, int p) {
		stTime[u] = timer++;
		low[u] = stTime[u];
		int jai = 0;
		for (int v : g[u]) {
			if (v == p) continue;
			if (stTime[v] >= INF) {
				// tree edge
				dfs(v, u);
				low[u] = min(low[u], low[v]);
				if (low[v] >= stTime[u] && p != -1) ans[u] = 1;
				jai++;
			} else if (enTime[v] >= INF) {
				// back edge
				low[u] = min(low[u], stTime[v]);
			}
		}
		enTime[u] = timer;
		if (p == -1 && jai > 1) ans[u] = 1;
	};
	dfs(0, -1);
	for (int i = 0; i < n; i++) if (ans[i]) cout << i << endl;
	return 0;
}

// Template Main {{{
int main() {
	ios::sync_with_stdio(0);
	// precompute();
	// int t; cin >> t; for (int i=1;i<=t;i++)
	solve();
	// cout << "Case #" << i << ": ", solve();
	return 0;
}

template <class T> istream &operator>>(istream &is, vector<T> &v) {
	for (auto it=v.begin();it!=v.end();++it) is >> *it;
	return is;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
	for (auto it=v.begin();it!=v.end();) os << *it, os << " \n"[++it==v.end()];
	return os;
}

template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) {
	return is >> p.first >> p.second;
}

template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) {
	return os << p.first << ' ' << p.second;
}
// }}}

// vim: fdm=marker


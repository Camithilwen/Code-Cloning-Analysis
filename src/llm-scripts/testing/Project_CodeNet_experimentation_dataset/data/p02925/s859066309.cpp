#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dfs(ll prev, ll now, vector<vector<ll>>& adj, vector<ll>& dp, set<ll>& st) {
	if (dp[now] > 0) return dp[now];
	if (st.find(now) != st.end()) return -1;
	st.insert(now);
	ll ret = 0;
	for (auto i : adj[now]) {
		if (i == prev) continue;
		ll x = dfs(now, i, adj, dp, st);
		if (x == -1) return -1;
		ret = max(ret, x);
	}
	st.erase(now);
	return dp[now] = ret + 1;
}

int main() {
	ll n;
	cin >> n;
	vector<vector<ll>> a(n, vector<ll>(n - 1));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n - 1; j++) {
			cin >> a[i][j];
			a[i][j]--;
		}
	}

	auto idx = [&] (ll i, ll j) {
		if (i > j) swap(i, j);
		ll ret = n * (n - 1) / 2 - (n - i) * (n - i - 1) / 2;
		return ret + j - i - 1;
	}; // {i, j} が対戦する試合の頂点番号

	ll m = n * (n - 1) / 2;
	vector<vector<ll>> adj(m);
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n - 2; j++) {
			ll u = idx(i, a[i][j]), v = idx(i, a[i][j + 1]);
			adj[u].push_back(v);
		}
	}

	vector<ll> dp(m, 0);
	ll ans = 0;
	for (ll i = 0; i < m; i++) {
		set<ll> st;
		ll x = dfs(-1, i, adj, dp, st);
		if (x == -1) {
			cout << -1 << endl;
			return 0;
		} else ans = max(ans, x);
	}

	cout << ans << endl;
}
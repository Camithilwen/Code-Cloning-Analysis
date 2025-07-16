#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll; 
typedef long double ld;
typedef pair<ll, ll> pll;

const ll N = 2e5 + 30, Mod = 1e9 + 7;
const ll SQ = 330;

ll n, m;
vector<ll> G[N], R[N];
ll id[N], ans[N], root;
ll M[N];
vector<ll> T;
void DFS(ll v) {
	M[v] = 1;
	for (auto u : G[v]) 
		if (!M[u])
			DFS(u);
	T.pb(v);
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n - 1 + m; i ++) {
		ll v, u;
		cin >> v >> u;
		G[v].pb(u);
		R[u].pb(v);
	}
	for (int i = 1; i <= n; i ++) {
		if (R[i].size()) continue;
		DFS(i);
	}
	reverse(all(T));
	root = T[0];
	for (int i = 0; i < n; i ++) {
		id[T[i]] = i;
	}
	for (int i = 1; i <= n; i ++) {
		ll pos = -1, v = 0;
		for (auto u : R[i]) {
			if (id[u] > pos) {
				pos = id[u];
				v = u;
			}
		}
		ans[i] = v;
	}
	for (int i = 1; i <= n; i ++) {
		cout << ans[i] <<  '\n';
	}
}
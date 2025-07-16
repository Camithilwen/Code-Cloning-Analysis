#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int N = 1e5 + 10;
vector<int> g[N];
int p[N], dp[N], ans, k;

void dfs(int v) {
	dp[v] = 1;
	for (auto u : g[v]) {
		dfs(u);
		dp[v] = max(dp[v], dp[u] + 1);
	}
	if (dp[v] == k - 1 && p[v] != 1) {
		dp[v] = 0;
		ans++;
	}
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
	int n;
	cin >> n >> k;
	k++;
	int x;
	cin >> x;
	if (x != 1) {
		ans++;
	}
	p[1] = 1;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		g[x].pb(i);
		p[i] = x;
	}
	dfs(1);
	cout << ans << '\n';
}
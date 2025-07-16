#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 10000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll n, W; ll w[345678], v[345678], dp1[5000][23456], dp2[5000][23456];
void solve1() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= W; j++) {
			if (i == 0) {
				if (j >= w[i]) { dp1[i][j] = v[i]; }
				continue;
			}
			if (j < w[i]) {
				dp1[i][j] = dp1[i - 1][j];
			}
			else {
				dp1[i][j] = max(dp1[i - 1][j], dp1[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	return;
}
void solve2() {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= W; j++) {
			if (j < w[i]) {
				dp2[i][j] = dp2[i + 1][j];
			}
			else {
				dp2[i][j] = max(dp2[i + 1][j], dp2[i + 1][j - w[i]] + v[i]);
			}
		}
	}
	return;
}
signed main() {
	ll m, a = 0, b = 0, cnt = 0, ans = 0; cin >> n >> W;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	W--; solve1(); solve2();
	for (int h = 0; h < n; h++) {
		if (h == 0) { ans = max(dp2[1][W] + v[0], ans); continue; }
		if (h == n - 1) { ans = max(ans, dp1[n - 2][W] + v[n - 1]); continue; }
		for (int i = 0; i <= W; i++) {
			ans = max(ans, dp1[h - 1][i] + dp2[h + 1][W - i] + v[h]);
		}
	}
	cout << ans << endl;
	return 0;
}
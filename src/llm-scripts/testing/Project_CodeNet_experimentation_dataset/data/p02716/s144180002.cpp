#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll, ll>;
const ll MOD = 998244353;
const int inf = 1e9 + 10;
const ll INF = 4e18;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0}, dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<ll> a(n + 5);
	rep(i, n) cin >> a[i];
	if (n == 2) {
		cout << max(a[0], a[1]) << endl;
		return 0;
	}
	vvl dp(n + 7, vl(3, -INF));
	rep(i, 3) dp[i][i] = 0;
	rep(i, n) {
		rep(j, 3) {
			if (dp[i][j] == -INF) continue;
			dp[i + 2][j] = max(dp[i + 2][j], dp[i][j] + a[i]);
			if (j < 2) dp[i + 3][j + 1] = max(dp[i + 3][j + 1], dp[i][j] + a[i]);
			if (j < 1) dp[i + 4][j + 2] = max(dp[i + 4][j + 2], dp[i][j] + a[i]);
		}
	}
	ll ans = -INF;
	if (n % 2)
		rep(i, 3) ans = max(ans, dp[n - 1 + i][i]);
	else
		rep(i, 2) ans = max(ans, dp[n + i][i]);
	cout << ans << endl;
	return 0;
}

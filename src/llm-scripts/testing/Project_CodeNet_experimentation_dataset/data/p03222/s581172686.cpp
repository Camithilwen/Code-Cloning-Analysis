#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int h, n, k;
	cin >> h >> n >> k;
	vector<vector<ll>> table(n, vector<ll>(n));
	rep(bit, 1 << (n - 1)) {
		vector<int> a(n - 1);
		int p = bit;
		rep(i, n - 1) {
			if (p & 1) a[i] = 1;
			p >>= 1;
		}
		bool flag = 0;
		rep(i, n - 2) {
			if (a[i] + a[i + 1] == 2) flag = 1;
		}
		if (flag) continue;
		vector<int> T(n);
		rep(i, n) T[i] = i;
		rep(i, n - 1) {
			if (a[i] == 1) swap(T[i], T[i + 1]);
		}
		rep(i, n) table[i][T[i]]++;
	}
	vector<vector<ll>> dp(h + 1, vector<ll>(n));
	dp[0][0] = 1;
	rep(i, h) rep(j, n) rep(k, n) dp[i + 1][k] = (dp[i + 1][k] + dp[i][j] * table[j][k] % MOD) % MOD;
	cout << dp[h][k - 1] << endl;
	return 0;
}
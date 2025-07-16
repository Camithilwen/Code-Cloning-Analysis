#include <bits/stdc++.h>

#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define pii pair<int, int>
#define mp make_pair
#define f first
#define ll long long
#define ld long double
#define s second
#define vec vector<int>

using namespace std;

const int N = (int) 300 + 10;
const int M = (int) 2018 * 2018;
const int K = (int) 15;
const int INF = (int) 1e9 + 7;
const int mod = (int) 998244353;
const ld EPS = (ld) 1e-9;
const ll LINF = (ll) 1e18;

int n, k;
string s;
int dp[N][N][N];

void upd_max(int &x, int y) {
	x = max(x, y);
}

int main() {
	#ifdef sony
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	srand(time(0));
	cin >> s >> k;
	n = sz(s);
	for (int i = 0; i < n; i++) {
		dp[i][i][0] = 1;
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i + len - 1 < n; i++) {
			int j = i + len - 1;
			for (int sum = 0; sum <= k; sum++) {
				if (s[i] == s[j]) {
					upd_max(dp[i][j][sum], dp[i + 1][j - 1][sum] + 2);
				} else {
					if (sum)
						upd_max(dp[i][j][sum], dp[i + 1][j - 1][sum - 1] + 2);
					upd_max(dp[i][j][sum], dp[i + 1][j][sum]);
					upd_max(dp[i][j][sum], dp[i][j - 1][sum]);
				}
			}
		}
	}
	int ans = 0;
	for (int sum = 0; sum <= k; sum++) {
		ans = max(ans, dp[0][n - 1][sum]);
	}
	cout << ans;
	return 0;	
}
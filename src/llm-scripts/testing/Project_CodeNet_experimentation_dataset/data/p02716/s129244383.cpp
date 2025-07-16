#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;
const ll inf = 1e18;
int n, v[mxn];
map <int, ll> dp[mxn];

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &v[i]);
	dp[0][0] = 0;
	rep(i, n) {
		for (int j = max(0, i / 2 - 5); j <= i / 2 + 5; ++ j) {
			dp[i + 1][j] = dp[i].find(j) == dp[i].end() ? -inf : dp[i][j];
			if (j) {
				ll old = dp[max(0, i - 1)].find(j - 1) == dp[max(0, i - 1)].end() ? -inf : dp[max(0, i - 1)][j - 1];
				dp[i + 1][j] = max(dp[i + 1][j], old + v[i]);
			}
		}
	}
	printf("%lld\n", dp[n][n / 2]);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector <ll> a(n+1), dp[3];
	for (int i=0; i<=2; i++) {
		dp[i].resize(n+1);
		for (int j=1; j<=n; j++) {
			dp[i][j] = -1e18;
		}
	}
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=2; j++) {
			if (i-j-2 < 1) continue;
			for (int k=0; k<=2-j; k++) {
				dp[j+k][i] = max(dp[j+k][i], dp[k][i-j-2]+a[i]);
			}
		}
		if (i <= 3) {
			dp[max(0, i-2)][i] = a[i];
		}
	}
	ll ans;
	if ((n&1)) {
		ans = max(max(max(dp[1][n], dp[2][n]), max(dp[0][n-1], dp[1][n-1])), dp[0][n-2]);
	} else {
		ans = max(dp[1][n], max(dp[0][n], dp[0][n-1]));
	}
	cout << ans;
	return 0;
}

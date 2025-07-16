#include <bits/stdc++.h>
using namespace std;

const int MN = 20123, INF = 5012345, MOD = 1000 * 1000 * 1000 + 7;
int inv[INF], fict[INF], invf[INF], dp[MN][MN];

void fact() {
	fict[0] = inv[0] = invf[0] = 1;
	fict[1] = inv[1] = invf[1] = 1;
	for (int i = 2; i < INF; i++) {
		inv[i] = 1ll * inv[MOD % i] * (MOD - MOD / i) % MOD;
		fict[i] = 1ll * fict[i - 1] * i % MOD;
		invf[i] = 1ll * invf[i - 1] * inv[i] % MOD;
	}
}

int chose(int a, int b) {
	return 1ll * fict[b] * invf[a] % MOD * invf[b - a] % MOD;
}

int main() {
	fact();
	int n, k;
	cin >> n >> k;
  	if (k == 1)
      return cout << 1, 0;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++) {
			if (j > i)
    	          continue;
			dp[i][j] = dp[i - 1][j];
			if (j)
				dp[i][j] = (dp[i][j] + 1ll * dp[i][j - 1] * chose(k - 2, n * k - (j - 1) * (k - 1) - i - 1) % MOD) % MOD;
        }
	cout << 1ll * dp[n][n] * fict[n] % MOD;
}

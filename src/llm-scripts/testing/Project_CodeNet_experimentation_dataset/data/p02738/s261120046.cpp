#include <iostream>
using namespace std;

const int BASE = 6200;
int N, mod;
int dp[6009][12409][3];
long long ret[12409];

void solve(int p1, int p2) {
	// 最大値を更新する場合
	for (int i = 0; i <= 2; i++) {
		int r = 0;
		if (i == 0) r = -1;
		if (i == 1) r = 1;
		dp[p1][p2][0] += 1LL * dp[p1 - 1][p2 - r][i] % mod;
		if (dp[p1][p2][0] >= mod) dp[p1][p2][0] -= mod;
	}

	// 最大値を更新しない場合
	for (int i = 1; i <= 2; i++) {
		dp[p1][p2][i] += 1LL * (p1 - 1LL) * dp[p1 - 1][p2][i - 1] % mod;
		if (dp[p1][p2][i] >= mod) dp[p1][p2][i] -= mod;
	}
}

int main() {
	cin >> N >> mod;
	dp[1][BASE][0] = 1;

	for (int i = 2; i <= 3 * N; i++) {
		for (int j = 1; j <= BASE * 2 - 1; j++) {
			solve(i, j);
		}
	}

	for (int i = 1; i <= BASE * 2 - 1; i++) {
		for (int j = 0; j <= 2; j++) {
			int r = 0;
			if (j == 0) r = -1;
			if (j == 1) r = 1;
			ret[i + r] += dp[3 * N][i][j];
		}
	}

	long long Answer = 0;
	for (int i = 0; i <= BASE; i++) Answer += ret[i];
	cout << Answer % mod << endl;
	return 0;
}
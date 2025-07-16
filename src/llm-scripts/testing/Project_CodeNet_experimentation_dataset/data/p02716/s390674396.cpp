#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	constexpr Int INF = 1e18;
	int N;
	cin >> N;
	vector<Int> a(N);
	for (int i = 0; i < N; ++i) { cin >> a[i]; }

	int skip = 1 + N % 2;
	vector<vector<Int>> dp(N + 2, vector<Int>(skip + 1, -INF));
	dp[0][0] = 0;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= skip; ++j) {
			if (j < skip) {
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
			}
			if (i < N) {
				dp[i + 2][j] = max(dp[i + 2][j], dp[i][j] + a[i]);
			}
		}
	}
	cout << dp[N + 1][skip] << endl;

	return 0;
}

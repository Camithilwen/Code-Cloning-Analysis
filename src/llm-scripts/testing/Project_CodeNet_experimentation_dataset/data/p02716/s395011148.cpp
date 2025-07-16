#include <iostream>
#include <algorithm>
using namespace std;

long long N, A[1 << 18];
long long dp[1 << 18][2][20];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 20; j++) {
			dp[i][0][j] = -(1LL << 60);
			dp[i][1][j] = -(1LL << 60);
		}
	}
	dp[0][0][10] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 6; j <= 14; j++) {
			if (dp[i - 1][0][j] != (1LL << 60)) {
				dp[i][1][j + 1] = max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i]);
				dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][0][j]);
			}
			if (dp[i - 1][1][j] != (1LL << 60)) {
				dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j]);
			}
		}
	}

	long long V = 10LL + (N / 2) - (N - (N / 2));
	long long T1 = dp[N][0][V];
	long long T2 = dp[N][1][V];
	cout << max(T1, T2) << endl;
	return 0;
}
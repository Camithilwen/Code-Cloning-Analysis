#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int N, M, a[114], b[114], c[114], g[19][19], sum[32777], val[32777], dp[19][32777], dp2[32777];
int main() {
	cin >> N >> M;
	int all_cost = 0;
	for (int i = 0; i < M; i++) {
		cin >> a[i] >> b[i] >> c[i]; a[i]--, b[i]--;
		sum[(1 << a[i]) + (1 << b[i])] += c[i];
		g[a[i]][b[i]] = g[b[i]][a[i]] = c[i];
		all_cost += c[i];
	}
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			if (c[i] < c[j]) {
				swap(a[i], a[j]);
				swap(b[i], b[j]);
				swap(c[i], c[j]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 1 << N; j++) {
			dp[i][j] = -inf;
		}
	}
	dp[0][1] = 0;
	for (int i = 3; i < 1 << N; i += 2) {
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				int sb = i - (1 << j);
				for (int k = 0; k < N; k++) {
					if ((sb & (1 << k)) && g[j][k] != 0) {
						dp[j][i] = max(dp[j][i], dp[k][sb] + g[j][k]);
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 1 << N; j++) {
			if (!(j & (1 << i))) {
				sum[j + (1 << i)] += sum[j];
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < 1 << N; i++) {
		if ((i & 1) && (i & (1 << (N - 1)))) {
			int sb = (1 << N) - i - 1;
			for (int j = sb; j >= 0; j--) {
				j &= sb;
				val[j] = 0;
				for (int k = 0; k < N; k++) {
					if (i & (1 << k)) {
						val[j] = max(val[j], sum[j + (1 << k)]);
					}
				}
			}
			dp2[0] = 0;
			for (int j = sb; j >= 0; j--) {
				j &= sb;
				if (j == sb) continue;
				int rj = sb - j;
				dp2[rj] = 0;
				for (int k = rj; k > 0; k = (k - 1) & rj) {
					dp2[rj] = max(dp2[rj], dp2[rj - k] + val[k]);
				}
			}
			ret = max(ret, dp2[sb] + dp[N - 1][i]);
		}
	}
	cout << all_cost - ret << endl;
	return 0;
}
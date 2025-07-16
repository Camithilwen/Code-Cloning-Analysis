#include<bits/stdc++.h>
using namespace std;
const int N = 105;

int n, m, ex, ey;
char s[N][N], a[N][N];
short ans, dp[N][N][N][N], sum[N][N];

int Sum(int U, int L, int D, int R) {
	if (U > D) swap(U, D);
	if (L > R) swap(L, R);
	return sum[D][R] + sum[U - 1][L - 1] - sum[D][L - 1] - sum[U - 1][R];
}

void Upd(short &x, short y) {
	x = max(x, y);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; ++j) {
			if (s[i][j] == 'E') {
				ex = i;
				ey = j;
			}
			if (s[i][j] == 'o') sum[i][j] = 1;
			sum[i][j] -= sum[i - 1][j - 1];
			sum[i][j] += sum[i][j - 1] + sum[i - 1][j];
		}
	}
	for (short a = ex; a >= 1; --a) {
		for (short c = ey; c >= 1; --c) {
			for (short b = ex; b <= n; ++b) {
				for (short d = ey; d <= m; ++d) {
					short U = b - ex + 1, D = n - ex + a;
					short L = d - ey + 1, R = m - ey + c;
					short now = dp[a][b][c][d];
					Upd(ans, now);
					if (a > U)
						Upd(dp[a - 1][b][c][d], now + Sum(a - 1, max(L, c), a - 1, min(R, d)));
					if (b < D)
						Upd(dp[a][b + 1][c][d], now + Sum(b + 1, max(L, c), b + 1, min(R, d)));
					if (c > L)
						Upd(dp[a][b][c - 1][d], now + Sum(max(U, a), c - 1, min(D, b), c - 1));
					if (d < R)
						Upd(dp[a][b][c][d + 1], now + Sum(max(U, a), d + 1, min(D, b), d + 1));
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}

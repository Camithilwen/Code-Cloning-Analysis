#include <bits/stdc++.h>
using namespace std;
int n, m, ex, ey;
char a[105][105];
short dp[101][101][101][101], sr[105][105], sc[105][105];
inline void getmax(short &x, short y) {
	if (x < y) x = y;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf(" %s", a[i] + 1);
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 'E') {
				ex = i;
				ey = j;
				a[i][j] = '.';
			}
			sr[i][j] = sc[i][j] = (a[i][j] == 'o');
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sr[i][j] += sr[i][j - 1];
			sc[i][j] += sc[i - 1][j];
		}
	}
	int ans = 0;
	for (int l = 0; l <= ey - 1; l++) {
		for (int r = 0; r <= m - ey; r++) {
			for (int u = 0; u <= ex - 1; u++) {
				for (int d = 0; d <= n - ex; d++) {
					ans = max(ans, (int)dp[l][r][u][d]);
					if (l + r < ey - 1) getmax(dp[l + 1][r][u][d], dp[l][r][u][d] + sc[min(n - u, ex + d)][ey - l - 1] - sc[max(d, ex - u - 1)][ey - l - 1]);
					if (l + r < m - ey) getmax(dp[l][r + 1][u][d], dp[l][r][u][d] + sc[min(n - u, ex + d)][ey + r + 1] - sc[max(d, ex - u - 1)][ey + r + 1]);
					if (u + d < ex - 1) getmax(dp[l][r][u + 1][d], dp[l][r][u][d] + sr[ex - u - 1][min(m - l, ey + r)] - sr[ex - u - 1][max(r, ey - l - 1)]);
					if (u + d < n - ex) getmax(dp[l][r][u][d + 1], dp[l][r][u][d] + sr[ex + d + 1][min(m - l, ey + r)] - sr[ex + d + 1][max(r, ey - l - 1)]);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
#include <stdio.h>
int n, m, l, g, e;
int a[15], b[15];
int x[15][15], y[15][15];
int ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		for (int j = 0; j < a[i]; j++) {
			scanf("%d%d", x[i] + j, y[i] + j);
			x[i][j]--;
		}
	}
	m = 1;
	for (int i = 0; i < n; i++) {
		m *= 2;
	}
	for (int i = 0; i < m; i++) {
		l = i;
		g = 1;
		e = 0;
		for (int j = 0; j < n; j++) {
			b[j] = l % 2;
			l /= 2;
			e += b[j];
		}
		for (int j = 0; j < n; j++) {
			if (b[j]) {
				for (int k = 0; k < a[j]; k++) {
					if (b[x[j][k]] != y[j][k]) {
						g = 0;
					}
				}
			}
		}
		if (g) {
			if (ans < e)ans = e;
		}
	}
	printf("%d\n", ans);
}

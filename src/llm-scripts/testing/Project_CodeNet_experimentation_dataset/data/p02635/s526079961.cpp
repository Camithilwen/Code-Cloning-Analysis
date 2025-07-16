#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline void Add(int &x, int y) { x += y; if (x >= mod) x -= mod; }
char s[305];
int len, n, K, a[305], f[305][305][305];
int main() {
	scanf("%s %d", s + 1, &K);
	len = strlen(s + 1);
	n = 0;
	for (int i = 1, lst = 0; i <= len + 1; i++) {
		if (i == len + 1 || s[i] == '0') {
			a[++n] = i - lst - 1;
			lst = i;
		}
	}
	reverse(a + 1, a + 1 + n);
	f[0][0][0] = 1;
	int ps = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= ps; j++) {
			for (int k = 0; k <= ps; k++) if (f[i - 1][j][k]) {
				for (int l = 0; l <= a[i]; l++) {
					Add(f[i][j + a[i] - l][k + a[i] - l], f[i - 1][j][k]);
				}
			}
		}
		for (int k = 0; k <= ps; k++) {
			int sum = 0;
			for (int j = ps; j >= 0; j--) {
				Add(f[i][j][k], sum);
				Add(sum, f[i - 1][j][k]);
			}
		}
		ps += a[i];
	}
	int ans = 0;
	for (int k = 0; k <= min(K, ps); k++) {
		Add(ans, f[n][0][k]);
	}
	printf("%d\n", ans);
	return 0;
}
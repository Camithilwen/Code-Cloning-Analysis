#include <bits/stdc++.h>

typedef long long LL;

const int N = 2e3, M = 4e6, MOD = 1e9 + 7;

int n, k, f[N + 5][N + 5], fac[M + 5], ifac[M + 5];

inline void add(int &x, const int &y) {
	(x += y) >= MOD && (x -= MOD);
}
inline int pow(int x, int k) {
	int ans = 1;
	for (; k > 0; k >>= 1, x = (LL)x * x % MOD) {
		if (k & 1) {
			ans = (LL)ans * x % MOD;
		}
	}
	return ans;
}
inline int inv(int x) {
	return pow(x, MOD - 2);
}
void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = (LL)fac[i - 1] * i % MOD;
	}
	ifac[n] = inv(fac[n]);
	for (int i = n; i >= 1; i--) {
		ifac[i - 1] = (LL)ifac[i] * i % MOD;
	}
}
inline int binom(int n, int m) {
	return (LL)fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}
int main() {
	scanf("%d%d", &n, &k);
	if (k == 1) {
		printf("1\n");
		return 0;
	}
	init(n * k);
	f[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n && j <= i; j++) {
			if (i < n) {
				add(f[i + 1][j], f[i][j]);
			}
			if (j < n) {
				add(f[i][j + 1], (LL)f[i][j] * (n - j) % MOD * binom(n * k - i - j * (k - 1) - 1, k - 2) % MOD);
			}
		}
	}
	printf("%d\n", f[n][n]);
	return 0;
}
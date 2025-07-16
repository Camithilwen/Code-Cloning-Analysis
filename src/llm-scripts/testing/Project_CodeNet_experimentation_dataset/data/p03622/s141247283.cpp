#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, P = 998244353;
int n, m, ans, inv[N], fac[N];
int qp (int a, int b) { int c = 1; for (; b; b >>= 1, a = 1ll * a * a % P) if (b & 1) c = 1ll * c * a % P; return c; }
int main () {
	scanf("%d%d", &n, &m); if (n < m) n ^= m ^= n ^= m;
	inv[0] = inv[1] = 1; for (int i = 2; i <= n + m; ++i) inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
	fac[0] = 1; for (int i = 1; i <= n + m; ++i) fac[i] = 1ll * fac[i - 1] * i % P, inv[i] = 1ll * inv[i] * inv[i - 1] % P;
	for (int i = 1; i <= m; ++i) ans = (1ll * fac[i << 1] * inv[i] % P * inv[i] % P * fac[n + m - (i << 1)] % P * inv[n - i] % P * inv[m - i] + ans) % P;
	return printf("%d\n", (1ll * ans * qp(1ll * fac[n + m] * inv[n] % P * inv[m] % P * 2 % P, P - 2) + n) % P), 0;
}
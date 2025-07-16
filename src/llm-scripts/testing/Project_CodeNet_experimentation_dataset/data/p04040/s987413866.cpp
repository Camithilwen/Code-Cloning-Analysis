#include <cstdio>
#include <algorithm>
#include <vector>
#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

inline int read()
{
	int data = 0, w = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') w = -1, ch = getchar();
	while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();
	return data * w;
}

const int N(2e5 + 10), Mod(1e9 + 7);
int fac[N], inv[N], f[N], n, m, A, B;
int C(int n, int m) { return 1ll * fac[n + m] * inv[m] % Mod * inv[n] % Mod; }
int fastpow(int x, int y)
{
	int ans = 1;
	for (; y; y >>= 1, x = 1ll * x * x % Mod)
		if (y & 1) ans = 1ll * ans * x % Mod;
	return ans;
}

int main()
{
	n = read() - 1, m = read() - 1, A = read() - 1, B = read() - 1, fac[0] = inv[0] = 1;
	if (A == n || B == m) return puts("0"), 0;
	for (int i = 1; i <= n + m; i++) fac[i] = 1ll * fac[i - 1] * i % Mod;
	inv[n + m] = fastpow(fac[n + m], Mod - 2);
	for (int i = n + m - 1; i; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % Mod;
	int ans = C(n, m);
	for (int i = 0; i <= A; i++)
		ans = (ans - 1ll * C(i, m - B - 1) * C(n - i, B) % Mod + Mod) % Mod;
	printf("%d\n", ans);
	return 0;
}

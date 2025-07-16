#if 0
date +%Y.%m.%d

题解先咕着。
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 6005;
ll f[maxn][maxn << 1];
ll inv[maxn];

int main () {
	int n = read * 3, mod = read;

	inv[1] = 1;
	for (int i = 2; i <= n; i ++)
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;

	f[0][maxn + 0] = 1;
	f[1][maxn + 1] = inv[1];
	f[2][maxn + 2] = inv[2];
	f[2][maxn - 1] = inv[2];
	for (int s = 3; s <= n; s ++)
		for (int i = maxn - s; i <= maxn + s; i ++)
			f[s][i] = (f[s - 1][i - 1] + f[s - 3][i] + f[s - 2][i + 1]) * inv[s] % mod;

	ll ans = 0;
	for (int i = maxn; i <= maxn + n; i ++)
		ans += f[n][i];
	ans %= mod;
	for (int i = 1; i <= n; i ++)
		(ans *= i) %= mod;
	printf("%lld\n", ans);
}

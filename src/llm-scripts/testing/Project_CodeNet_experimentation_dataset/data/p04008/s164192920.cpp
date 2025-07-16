#include <bits/stdc++.h>

const int N = 100054;

int n, K, ans;
int p[N], fc[N], nc[N], f[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void link(int x, int px) {nc[x] = fc[px], fc[px] = x;}

void dfs(int x, int dep = 0) {
	for (int y = fc[x]; y; y = nc[y]) dfs(y, dep + 1), up(f[x], f[y] + 1);
	if (dep > 1 && f[x] >= K - 1) ++ans, f[x] = -1;
}

int main() {
	scanf("%d%d%d", &n, &K, &ans), ans = ans != 1;
	for (int i = 2; i <= n; ++i) scanf("%d", p + i), link(i, p[i]);
	dfs(1), printf("%d\n", ans);
	return 0;
}
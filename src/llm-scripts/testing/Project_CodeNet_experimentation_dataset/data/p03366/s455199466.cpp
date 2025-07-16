#include <iostream>

using i64 = long long;

i64 abs(i64 x) {
	return x < 0 ? -x : x;
}

const int N = 100000 + 7;

int n, s;
int x[N], p[N];

i64 dfs(int l, int r, i64 u, i64 v) {
	if (s < x[l]) return x[r] - s;
	if (s > x[r]) return x[l] - s;
	if (u + p[l] >= v + p[r]) {
		i64 t = dfs(l, r - 1, u + v + p[r], 0);
		return x[r] - (t > 0 ? x[r - 1] : x[l]) + abs(t);
	}
	if (u + p[l] < v + p[r]) {
		i64 t = dfs(l + 1, r, 0, u + v + p[l]);
		return x[l] - (t > 0 ? x[r] : x[l + 1]) - abs(t);
	}
}

int main() {
//	freopen("code.in", "r", stdin);
//	freopen("code.out", "w", stdout);

	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", x + i, p + i);
	printf("%lld\n", abs(dfs(1, n, 0, 0)));
	return 0;
}

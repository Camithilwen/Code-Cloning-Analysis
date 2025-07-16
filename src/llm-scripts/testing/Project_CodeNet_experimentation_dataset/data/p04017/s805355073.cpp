#include <bits/stdc++.h>

const int MAXN = 100010;
int xs[MAXN], D, n, Q;
int R[MAXN][20];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> xs[i];
	std::cin >> D >> Q;
	for (int i = 1; i <= n; ++i)
		R[i][0] = std::upper_bound(xs + 1, xs + 1 + n, xs[i] + D) - xs - 1;
	for (int i = 1; i < 20; ++i)
		for (int j = 1; j <= n; ++j)
			R[j][i] = R[R[j][i - 1]][i - 1];
	while (Q --> 0) {
		int x, y, t = 0; std::cin >> x >> y; if (x > y) std::swap(x, y);
		for (int i = 19; ~i; --i) if (R[x][i] < y) t += 1 << i, x = R[x][i];
		std::cout << t + 1 << '\n';
	}
	return 0;
}

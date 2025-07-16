#include <bits/stdc++.h>
#define ctz __builtin_ctz

const int N = 648;

int n, D1, D2;
int a[N][N];

void coloring(int dist, int bit) {
	int i, j, L = ctz(dist) / 2; dist >>= 2 * L;
	switch (dist & 3) {
		case 0: throw "gg"; break;
		case 1: for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) a[i][j] |= ((i ^ j) >> L & 1) << bit; break;
		case 2: for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) a[i][j] |= (i >> L & 1) << bit; break;
	}
}

int main() {
	int i, j, c, d, col[4] = {0};
	scanf("%d%d%d", &n, &D1, &D2), d = n * n, n *= 2, coloring(D1, 0), coloring(D2, 1);
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j) ++col[ a[i][j] ];
	c = std::max_element(col, col + 4) - col;
	for (i = 0; i < n && d; ++i)
		for (j = 0; j < n && d; ++j)
			if (a[i][j] == c) --d, printf("%d %d\n", i, j);
	return 0;
}
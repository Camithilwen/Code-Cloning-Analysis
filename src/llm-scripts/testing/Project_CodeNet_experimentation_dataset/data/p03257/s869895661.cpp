#include <bits/stdc++.h>

typedef long long ll;
const int N = 540;

int n;
int pn = 0, c[7930], p[1054];
ll a[N][N];

void sieve(int n) {
	int i, j, v;
	memset(c, -1, sizeof c);
	for (i = 2; i <= n; ++i) {
		if (!~c[i]) p[pn] = i, c[i] = pn++;
		for (j = 0; (v = i * p[j]) <= n && j <= c[i]; ++j) c[v] = j;
	}
}

int main() {
	int i, j, *q;
	scanf("%d", &n), sieve(7929);
	q = p + (n - 1);
	for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) if ((i ^ j) & 1)
		a[i][j] = p[(i + j - 1) / 2] * q[(j - i + n - 1) / 2];
	for (i = 0; i < n; ++i) for (j = 0; j < n; ++j) if (!((i ^ j) & 1)) {
		ll &s = a[i][j]; s = 1;
		if (i          || j         ) s *= p[(i + j - 2) / 2];
		if (i != n - 1 || j != n - 1) s *= p[(i + j) / 2];
		if (i          || j != n - 1) s *= q[(j - i + n) / 2];
		if (i != n - 1 || j         ) s *= q[(j - i + n - 2) / 2];
		++s;
	}
	if (n == 2) a[1][1] = a[1][1] * 2 - 1;
	for (i = 0; i < n; ++i) for (j = 0; j < n; ++j)
		printf("%lld%c", a[i][j], j == n - 1 ? 10 : 32);
	return 0;
}
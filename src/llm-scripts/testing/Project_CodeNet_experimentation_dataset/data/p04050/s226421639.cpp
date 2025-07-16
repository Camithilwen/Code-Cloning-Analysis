#include <bits/stdc++.h>

const int N = 108;

int n;
int a[N], b[N];

int main() {
	int i, mid;
	scanf("%*d%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	if (n == 1) return *a == 1 ? puts("1\n1\n1") : printf("%d\n2\n1 %d\n", *a, *a - 1), 0;
	mid = std::partition(a, a + n, [] (const int x) -> bool {return x % 2;}) - a;
	if (mid > 2) return puts("Impossible"), 0;
	a[n] = *a;
	for (i = 1; i <= n; ++i) printf("%d%c", a[i], i == n ? 10 : 32);
	memcpy(b + 1, a + 1, n << 2), ++b[1], --b[n], n -= !b[n];
	printf("%d\n", n);
	for (i = 1; i <= n; ++i) printf("%d%c", b[i], i == n ? 10 : 32);
	return 0;
}
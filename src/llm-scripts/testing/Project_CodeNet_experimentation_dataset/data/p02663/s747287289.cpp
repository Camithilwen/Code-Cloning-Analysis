#include <cstdio>

int main() {
	int a, b, c, d, e, tot = 0;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	if (c < a) c += 24;
	tot += (c - a) * 60 + (d - b);
	printf("%d", tot - e);
	return 0;
}

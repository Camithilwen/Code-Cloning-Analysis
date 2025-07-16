#include <stdio.h>
#include <algorithm>
int k, t;
int a[100];
int main() {
	scanf("%d%d", &k, &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", a + i);
	}
	std::sort(a, a + t);
	k = k - a[t - 1];
	k = a[t - 1] - k - 1;
	if (k < 0)k = 0;
	printf("%d\n", k);
}
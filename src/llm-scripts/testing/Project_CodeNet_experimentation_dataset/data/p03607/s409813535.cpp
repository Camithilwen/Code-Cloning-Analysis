#include <stdio.h>
#include <algorithm>
int n, t, x;
int a[100000];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	std::sort(a, a + n);
	t = 1;
	for (int i = 0; i < n; i++) {
		if (i == n - 1 || a[i] != a[i + 1]) {
			if (t % 2)x++;
			t = 1;
		}
		else t++;
	}
	printf("%d\n", x);
}
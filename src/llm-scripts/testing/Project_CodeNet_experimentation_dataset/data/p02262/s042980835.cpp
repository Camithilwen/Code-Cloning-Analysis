#include <stdio.h>
#include <math.h>

int n;
int a[1000000];
int cnt;

void insertionSort(int g) {
	for (int i = g; i < n; i ++) {
		int v = a[i];
		int j = i - g;
		while (j >= 0 && a[j] > v) {
			a[j + g] = a[j];
			j -= g;
			cnt ++;
		}
		a[j + g] = v;
	}
}

void shellSort() {
	int g[100000];
	g[0] = 1;
	int m = 0;
	while (g[m] <= n) {
		g[m + 1] = 3 * g[m] + 1;
		m ++;
	}
	printf("%d\n", m);
	for (int i = m - 1; i >= 0; i --) {
		if (i < m - 1) printf(" ");
		printf("%d", g[i]);
	}
	puts("");
	for (int i = m - 1; i >= 0; i --) {
		insertionSort(g[i]);
	}
	printf("%d\n", cnt);
	for (int i = 0; i < n; i ++) {
		printf("%d\n", a[i]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%d", &a[i]);
	}
	shellSort();
	return 0;
}
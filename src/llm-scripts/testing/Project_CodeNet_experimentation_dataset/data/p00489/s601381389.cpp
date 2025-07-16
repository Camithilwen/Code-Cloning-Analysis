#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<cctype>
#include<string.h>
#include <stdlib.h>

#define PI 3.1415926
void swap(int* x, int* y) {
	int a = *x;
	int b = *y;
	*x = b;
	*y = a;
}
int factorial(int n);
int sum(int n, int*);
int ave(int n, int*);
int min(int n, int*), min(int n, int m);
int max(int n, int*), max(int n, int m);

int main() {
	int N, X[200] = { 0 }, a, b, c, d, Y[200];
	scanf("%d", &N);
	for (int i = 1; i <= N*(N - 1) / 2; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (c == d) {
			X[a]++;
			X[b]++;
		}
		else if (c < d) {
			X[b] += 3;
		}
		else {
			X[a] += 3;
		}
	}
	int p = 1;
	for (int i = 1; i <= N; i++) {
		p = 1;
		//printf("%d\n", X[i]);
		for (int j = 1; j <= N; j++) {
			if (X[i] < X[j]) {
				p++;
			}
		}
		printf("%d\n", p);
	}
	return 0;
}

int factorial(int n) {
	if (n > 0) {
		return n * factorial(n - 1);
	}
	else {
		return 1;
	}
}
int sum(int n, int *all) {
	int total = 0;
	for (int i = 0; i < n; ++i) {
		total += all[i];
	}
	return total;
}
int ave(int n, int *all) {
	int total = 0;
	for (int i = 0; i<n; ++i) {
		total += all[i];
	}
	return total / n;
}
int min(int n, int *all) {

	int min = all[0];
	for (int i = 1; i < n; ++i) {
		if (all[0] > all[i]) {
			min = all[i];
		}
	}
	return min;
}
int max(int n, int *all) {
	int max = all[0];
	for (int i = 1; i<n; ++i) {
		if (all[0]<all[i]) {
			max = all[i];
		}
	}
	return max;
}
int max(int n, int m) {
	if (n >= m) {
		return n;
	}
	else {
		return m;
	}
}
int min(int n, int m) {
	if (n >= m) {
		return m;
	}
	else {
		return n;
	}
}
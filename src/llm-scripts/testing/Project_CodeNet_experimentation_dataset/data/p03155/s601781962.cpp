#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

int n, h, w;

int main() {
	scanf("%d %d %d", &n, &h, &w);
	printf("%d\n", (n - h + 1) * (n - w + 1));
	return 0;
}
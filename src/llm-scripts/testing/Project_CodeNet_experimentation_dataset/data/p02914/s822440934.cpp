#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef uint64_t ull;
typedef  int64_t sll;

static const ull MOD = 1000000007LL;

int n;
int k;
int q;

ull a[200019];

ull umin (ull a, ull b) {
	return (a < b) ? a : b;
}
ull umax (ull a, ull b) {
	return (a > b) ? a : b;
}

ull solve () {
	sll i, j, ki;
	ull res = 0;

	ull allxor = 0;
	for (i = 0; i < n; i++) {
		allxor ^= a[i];
	}
	for (i = 0; i < n; i++) {
		a[i] &= ~allxor;
	}

	ull rank = 0;
	for (i = 59; i >= 0; i--) {
		for (j = rank; j < n; j++) {
			if (a[j] & (1LL << i)) break;
		}
		if (j == n) {
			continue;
		}

		if (j > rank) a[rank] ^= a[j];
		for (j = rank + 1; j < n; j++) {
			a[j] = umin(a[j], a[j] ^ a[rank]);
		}

		rank++;
	}
	ull x = 0;
	for (i = 0; i < n; i++) {
		x = umax(x, x ^ a[i]);
	}

	res = (x * 2) + allxor;

	return res;
}

int main(void){

	scanf("%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}

	printf("%lld\n", solve());

	return 0;
}

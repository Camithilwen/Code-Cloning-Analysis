// A.

#include <stdio.h>

typedef long long LL;

char buffer[3072000];
LL cnt[20][20];
LL sum[20][20];
LL n;
LL ans;

int main(int argc, char* argv[]) {
	char c, *bufptr = buffer;
	fread(buffer, 1, 3072000, stdin);
	while ((c = *bufptr++) >= '0') {
		n = (n * 10) + (c - '0');
	}
	for (LL i = 0; i < n; ++i) {
		LL x = 0, two = 0, five = 0, df = 0;
		while ((c = *bufptr++) >= ' ') {
			if (c == '.') {
				df = -1;
			} else {
				x = (x * 10) + c - '0';
				five += df;
			}
		}
		two = __builtin_ctzll(x);
		x >>= two;
		two += five;
		while (x % 5 == 0) {
			++five;
			x /= 5;
		}
		if (two > 9) two = 9;
		if (five > 9) five = 9;
		cnt[10 + two][10 + five] += 1;
		sum[10 - two][10 - five] += 1;
	}
	for (int i = 0; i < 20; ++i) {
		for (int j = 1; j < 20; ++j) {
			sum[i][j] += sum[i][j - 1];
		}
	}
	for (int i = 1; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			sum[i][j] += sum[i - 1][j];
		}
	}
	for (int i = -9; i <= 9; ++i) {
		for (int j = -9; j <= 9; ++j) {
			ans += sum[10 + i][10 + j] * cnt[10 + i][10 + j];
			if (i >= 0 && j >= 0) {
				ans -= cnt[10 + i][10 + j];
			}
		}
	}
	printf("%lld\n", ans >> 1);
	return 0;
}

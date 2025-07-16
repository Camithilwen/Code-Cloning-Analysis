#include <cstdio>

typedef long long LL;
const int MX = 10005, MP = 2005;
const int MN = 505;

bool ip[MX];
int p[MP], pc;
inline void Sieve(int N) {
	for (int i = 2; i <= N; ++i) {
		if (!ip[i]) p[++pc] = i;
		for (int j = 1, k; j <= pc; ++j) {
			if ((k = p[j] * i) > N) break;
			ip[k] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

int N, A[MN], B[MN];

int main() {
	Sieve(10000);
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) A[i] = p[i & 1 ? i / 2 + 1 : N + N - i / 2 + 1];
	for (int i = 1; i <= N; ++i) B[i] = p[(i & 1 ? N - i / 2 : N + i / 2) + (N & 1)];
	A[0] = A[N + 1] = B[0] = B[N + 1] = 1;
	for (int i = 1; i <= N; ++i, puts(""))
		for (int j = 1; j <= N; ++j)
			if ((i + j) % 2) printf("%lld ", (LL)A[(i + j) / 2] * A[(i + j) / 2 + 1] * B[(N + i - j + (N & 1)) / 2] * B[(N + i - j + (N & 1)) / 2 + 1] + 1);
			else printf("%d ", A[(i + j) / 2] * B[(N + i - j + (N & 1)) / 2]);
	return 0;
}

// Luogu : PinkRabbit
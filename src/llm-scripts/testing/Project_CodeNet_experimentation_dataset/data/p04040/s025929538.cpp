#include <bits/stdc++.h>

using namespace std;

const long long r = 1e9 + 7;

long long fac[200001];

long long f(long long a, long long p) {
	if (p == 1)
		return a;

	long long ret = f(a, p / 2);
	ret = ret * ret % r;
	if (p % 2 == 1)
		ret = ret * a % r;

	return ret;
}

long long c(int n, int m) {
	return fac[n] * f(fac[m] * fac[n - m] % r, r - 2) % r;
}

int main() {
	fac[0] = 1;
	for (int i = 1; i <= 200000; ++i)
		fac[i] = fac[i - 1] * i % r;

	int n, m, a, b;
	scanf("%d %d %d %d", &n, &m, &a, &b);
	a = n - a;

	long long ans = 0;
	for (int i = 1; i <= a; ++i) 
		ans = (ans + c(b + i - 2, b - 1) * c(m - b + n - i - 1, n - i) % r) % r;

	printf("%lld", ans);

	return 0;
}
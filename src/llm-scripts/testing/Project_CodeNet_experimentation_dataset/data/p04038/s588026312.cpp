%:pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
const int M = 4e6 + 5;
const int mod = 1e9 + 7;

int n, k, dp[N][N], fac[M], ifac[M];

inline int mul(int a, int b) {
	return (long long) a * b % mod;
}
inline int add(int a, int b) {
	return (a += b) >= mod ? a - mod : a;
}
inline int Pow(int a, int b) {
	int r = 1;
	for(; b; b >>= 1, a = mul(a, a))
		if(b & 1) r = mul(r, a);
	return r;
}

void pre(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; ++i)
		fac[i] = mul(fac[i - 1], i);
	ifac[n] = Pow(fac[n], mod - 2);
	for(int i = n - 1; ~i; --i)
		ifac[i] = mul(ifac[i + 1], i + 1);
}
inline int C(int n, int m) {
	if(n < 0 || m < 0 || n < m) return 1;
	return mul(fac[n], mul(ifac[m], ifac[n - m]));
}

int main() {
	cin >> n >> k;
	if(k == 1) return 0 * putchar('1');
	pre(M - 1);
	dp[0][0] = 1;
	for(int i = 0; i <= n; ++i)
		for(int j = i +(!i); j <= n; ++j) {
			if(i) dp[i][j] = dp[i - 1][j];
			dp[i][j] = add(dp[i][j], mul(dp[i][j - 1], C(i + j * (k - 1) - 1, k - 2)));
		}
	printf("%d\n", mul(dp[n][n], fac[n]));
	return 0;
}

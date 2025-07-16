#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = 2e3 + 6, MOD = 1e9 + 7;
int n, k;
int F[MAX_N * MAX_N];
int D[MAX_N * MAX_N];
int dp[MAX_N][MAX_N];

int _sum(int a, int b) {
	int c = a + b;
	if (MOD <= c)
		c -= MOD;

	return c;
}

int _mul(int a, int b) {
	int res = 1LL * a * b % MOD;
	return res;
}

int _pow(int a, int b) {
	if (!b)
		return 1;

	int res = _pow(a, b >> 1);
	res = _mul(res, res);

	if (b & 1)
		res = _mul(res, a);

	return res;
}

int choose(int a, int b) {
	if (b < a || min(a, b) < 0)
		return 0;

	return _mul(F[b], _mul(D[a], D[b - a]));
}

void pre_process() {
	F[0] = 1;
	for (int i = 1; i < MAX_N * MAX_N; i++)
		F[i] = _mul(F[i - 1], i);

	D[0] = 1;
	for (int i = 1; i < MAX_N * MAX_N; i++)
		D[i] = _pow(F[i], MOD - 2);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	pre_process();
	cin >> n >> k;
	
	if (k == 1) {
		cout << "1\n";
		return 0;
	}

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++)
			dp[i][j] = _sum(_mul(dp[i][j - 1], choose(k - 2, n * k - i - (j - 1) * (k - 1) - 1)), dp[i - 1][j]);
	}

	cout << _mul(dp[n][n], F[n]) << "\n";
	return 0;
}

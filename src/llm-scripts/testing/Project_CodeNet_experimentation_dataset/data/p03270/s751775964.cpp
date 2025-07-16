#include <bits/stdc++.h>
#define mo 998244353
#define int long long
using namespace std;

const int N = 100001;
int f[N], inv[N], k, n;

inline int read() {
	int x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * flag;
}


inline int qp(int base, int pow) {
	int res = 1;
	while (pow) {
		if (pow & 1)
		res = res * base, res %= mo;
		base = base * base;
		base %= mo;
		pow >>= 1;
	}
	return res;
}

inline void pre() {
	f[0] = 1;
	for (register int i = 1; i <= 100000; ++i) {
		f[i] = f[i - 1] * i;
		f[i] %= mo;
	}
	inv[100000] = qp(f[100000], mo - 2);
	for (register int i = 99999; i >= 0; --i) {
		inv[i] = inv[i + 1] * (i + 1) % mo;
	}
}

inline int C(int n, int m) {
	if (n < m) return 0;
	return f[n] * inv[n - m] % mo * inv[m] % mo;
}

void solve(int x) {
	int t = 0;
	for (int i = 1; i <= x / 2; ++i) {
		int a = i, b = x - i;
		if (a <= k && b <= k) t++;
	}
//	printf("%lld %lld\n", x, t);
	int flag = 1, w = t, res = 0;
	for (int i = 1; i <= t; ++i) {
		(res += C(n + k - 1 - 2 * i, k - 1) * flag * C(t, i) % mo) %= mo;
		w--;
		flag = -flag;
	}
	int ans = (C(n + k - 1, k - 1) - res + mo) % mo;
	printf("%lld\n", ans);
}

signed main() {
	pre();
	k = read(), n = read();
	for (int i = 2; i <= 2 * k; ++i) {
		solve(i);
	}
	return 0;
}
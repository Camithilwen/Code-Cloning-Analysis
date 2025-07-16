#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000, mod = 998244353, inv2 = (mod + 1) / 2;
int n, m, s, w, d, w2, ans;
int fac[maxn + 10], ifac[maxn + 10], inv[maxn + 10];

inline int add(int x, int y) {
	x += y; return x < mod ? x : x - mod;
}
inline int dec(int x, int y) {
	x -= y; return x < 0 ? x + mod : x;
}
inline int mul(int x, int y) {
	return 1ll * x * y % mod;
}

void prework() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= maxn; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = i == 1 ? 1 : dec(0, mul(mod / i, inv[mod % i]));
		ifac[i] = mul(ifac[i - 1], inv[i]);
	}
}

int comb(int x, int y) {
	return y < 0 || y > x ? 0 : mul(fac[x], mul(ifac[y], ifac[x - y]));
}

int f(int x, int y) {
	return comb(x + y, x);
}

int main() {
	prework();
	scanf("%d%d", &n, &m);
	w = comb(n + m - 1, n); w2 = comb(n + m - 1, m); d = 1;
	s = add(s, add(w, w2));
	for (int i = m - 2; i >= -n - 1; --i) {
		ans = add(ans, mul(s, inv[d]));
		++d;
		if (d & 1) {
			w = add(w, mul(f(i + d / 2, n - d / 2), f(m - (i + d / 2) - 2, d / 2)));
			w2 = add(w2, mul(f(m - d / 2, n - (d - d / 2)), f(d / 2, d - d / 2 - 2)));
		} else {
			w = dec(w, mul(f(i + d / 2, n - d / 2), f(m - (i + d / 2) - 1, d / 2 - 1)));
			w2 = dec(w2, mul(f(m - d / 2, n - (d - d / 2)), f(d / 2 - 1, d - d / 2 - 1)));
		}
		s = add(s, add(w, w2));
	}
	printf("%d", mul(ans, mul(ifac[n + m], mul(fac[n], fac[m]))));
}
#include <bits/stdc++.h>

const int mod = 998244353;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
const int MAXS = 1000010;
int fac[MAXS], inv[MAXS];
int C(int a, int b) { return a < b ? 0 : (LL) fac[a] * inv[b] % mod * inv[a - b] % mod; }
int main() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i != MAXS; ++i) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[mod % i], mod - mod / i);
	}
	for (int i = 2; i != MAXS; ++i) inv[i] = mul(inv[i - 1], inv[i]);
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n, m; std::cin >> n >> m;
	int ans = std::max(n, m), a2 = 0;
	for (int i = std::min(n, m); i; --i)
		reduce(a2 += mul(C(i * 2, i), C(n + m - i * 2, n - i)) - mod);
	a2 = pow(mul(C(n + m, n), 2), mod - 2, a2);
	reduce(ans += a2 - mod);
	std::cout << ans << std::endl;
	return 0;
}

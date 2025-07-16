#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
const int mod = 998244353;
typedef long long ll;
#define int long long
int fac[maxn], inv[maxn];
int n, m;
int pw(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = (ll)res * a % mod;
		a = (ll)a * a % mod, n >>= 1;
	}
	return res;
}
int INV(int a) {
	return pw(a, mod - 2);
}
void pre() {
	fac[0] = 1;
	for(int i = 1; i < maxn; i++) fac[i] = (ll)fac[i - 1] * i % mod;
	inv[maxn - 1] = INV(fac[maxn - 1]);
	for(int i = maxn - 2; i >= 0; i--) inv[i] = (ll)inv[i + 1] * (i + 1) % mod;
}
int C(int n, int m) {
	return (ll)fac[n] * inv[m] % mod * (ll)inv[n - m] % mod;
}
int H(int n, int m) {
	return C(n + m - 1, m);
}
void add(int& a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}
void sub(int& a, int b) {
	a -= b;
	if(a < 0) a += mod;
}
int32_t main() {
	pre();
	scanf("%lld%lld", &n, &m);
	int ans = 0;
	for(int i = 0; i <= min(n, m); i++) if((3 * m - i) % 2 == 0) {
		add(ans, C(n, i) * H(n, (3 * m - i) / 2) % mod);
	}
	int tmp = 0;
	for(int i = 0; i <= min(n, m); i++) if((m - i) % 2 == 0) {
		add(tmp, C(n, i) * H(n, (m - i) / 2) % mod);
	}
	for(int i = 0; i <= min(n - 1, m); i++) if((m - i) % 2 == 0) {
		sub(tmp, C(n - 1, i) * H(n - 1, (m - i) / 2) % mod);
	}
	tmp = (ll)tmp * n % mod;
	sub(ans, tmp);
	printf("%lld\n", ans);
	return 0;
}

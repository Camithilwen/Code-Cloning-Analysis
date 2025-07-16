#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll; 
const int N = 100010;
const ll mod = 1e9 + 7;

ll fac[N << 1], inv[N << 1];
int h, w, a, b;

ll power(ll a, int b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod; b >>= 1;
	}
	return ans;
}

ll C(int n, int m) {
	return fac[m] * inv[n] % mod * inv[m - n] % mod;
}

ll Calc(int h, int w) {return C(h - 1, h + w - 2);}

int main() {
	scanf("%d%d%d%d", &h, &w, &a, &b);
	fac[0] = inv[0] = 1; 
	a = h - a + 1;
	for(int i = 1; i <= 200000; ++i) fac[i] = 1LL * fac[i - 1] * i % mod;
	for(int i = 1; i <= 200000; ++i) inv[i] = power(fac[i], mod - 2);
	ll ans = 0;
	for(int i = b + 1; i <= w; ++i) {
		ans = (ans + 1LL * Calc(a - 1, i) * Calc(h - a + 1, w - i + 1) % mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
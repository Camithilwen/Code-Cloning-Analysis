#include <cstdio>
#include <algorithm>
using namespace std;
const int mod = 998244353;
typedef long long LL;
const int MAXN = 1e6 + 6;
LL n , m , fac[MAXN] , inv[MAXN] , finv[MAXN];
int main() {
	scanf("%lld %lld" , &n , &m);
	fac[0] = 1;
	for (LL i = 1; i <= n + m; ++i) fac[i] = fac[i - 1] * i % mod;
	finv[1] = inv[1] = 1;
	finv[0] = 1;
	for (LL i = 2; i <= n + m; ++i) inv[i] = (mod - mod / i) * inv[mod % i] % mod , finv[i] = finv[i - 1] * inv[i] % mod;
	LL ans = 0;
	for (int k = 1; k <= min(n , m); ++k) {
		ans = (ans + inv[2] * fac[n - k + m - k] % mod * finv[m - k] % mod * finv[n - k] % mod * fac[2 * k] % mod * finv[k] % mod * finv[k] % mod * finv[n + m] % mod * fac[n] % mod * fac[m] % mod) % mod;
	}
	ans = (ans + max(n , m)) % mod;
	printf("%lld" , ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 4000 + 10;
int n, k;
ll inv[maxn], fac[maxn], facinv[maxn], ans[maxn];
void init()
{
	inv[0] = inv[1] = 1;
	fac[0] = facinv[0] = 1;
	for(int i = 1; i < maxn; ++i)
		fac[i] = fac[i - 1] * i % mod;
	for(int i = 2; i < maxn; ++i)
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1; i < maxn; ++i)
		facinv[i] = facinv[i - 1] * inv[i] % mod;
}
ll C(ll m, ll n)
{
	return fac[m] * facinv[m - n] % mod * facinv[n] % mod;
}
ll norm(ll x)
{
	while(x > 0) x -= mod;
	while(x < 0) x += mod;
	return x;
}
int main()
{
	init();
	scanf("%d%d", &k, &n);
	for(int j = 2; j <= k + 1; ++j)
	{
		ll ret = 0;
		int t = j >> 1;
		for(int i = 0; i <= t && n - 2 * i >= 0; ++i)
		{
			ll tmp = C(t, i) * C(n - 2 * i + k - 1, k - 1) % mod;
			if(i & 1)
				ret = norm(ret - tmp);
			else
				ret = norm(ret + tmp);
 		}
 		ans[j] = ans[2 * k - j + 2] = ret;
 	}
 	for(int j = 2; j <= 2 * k; ++j)
 		printf("%lld\n", ans[j]);
 	return 0;
}
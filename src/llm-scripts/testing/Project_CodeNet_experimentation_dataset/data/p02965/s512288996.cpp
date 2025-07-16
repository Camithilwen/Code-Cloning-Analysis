#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define rg register
using std::cin;
using std::cout;
const int Maxn = 2e7 + 5, Mod = 998244353;
typedef long long ll;
typedef ll arr[Maxn];
ll Add(ll x, ll y) { return (x += y) >= Mod ? x - Mod : (x < 0 ? x + Mod : x); }
ll min(ll x, ll y) { return x < y ? x : y; }
ll max(ll x, ll y) { return x > y ? x : y; }
inline ll read()
{
	rg ll res = 0, sign = 1;
	rg char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			sign = -1;
		ch = getchar();
	}
	do
	{
		res = (res << 3) + (res << 1) + (ch ^ 48);
		ch = getchar();
	} while (isdigit(ch));
	return res * sign;
}
int n, m;
arr fac, inv, invfac;
ll ans;
ll qp(ll x, int y)
{
	ll res = 1;
	while (y)
	{
		if (y & 1)
			res = res * x % Mod;
		x = x * x % Mod;
		res >>= 1;
	}
	return res;
}
ll C(int x, int y) { return fac[x] * invfac[y] % Mod * invfac[x - y] % Mod; }
int main()
{
	fac[0] = inv[1] = invfac[0] = 1;
	for (rg int i = 1; i <= 20000000; i++)
	{
		fac[i] = fac[i - 1] * i % Mod;
		if (i > 1)
			inv[i] = (Mod - Mod / i) * inv[Mod % i] % Mod;
		invfac[i] = invfac[i - 1] * inv[i] % Mod;
	}
	rg int tmp;
	cin >> n >> m;
	ans = 1;
	for (rg int i = 1; i < n; i++)
		ans = ans * (3 * m + i) % Mod;
	ans = ans * invfac[n - 1] % Mod;
	ans = Add(ans, -(n * C(m - 1 + n - 1, n - 1) % Mod));
	if (n > m)
	{
		tmp = min(3 * m, n);
		for (rg int i = m + 2; i <= tmp; i += 2)
			ans = Add(ans, -(C(n, i) * C((3 * m - i) / 2 + n - 1, n - 1) % Mod));
	}
	cout << ans << '\n';
	return 0;
}
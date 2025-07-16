#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
ll powMod(ll a, ll k)
{
	ll ret = 1;
	while(k)
	{
		if(k & 1) ret = ret * a % mod;
		a = a * a % mod; k >>= 1;
	}
	return ret;
}
ll inv(ll a) { return powMod(a, mod - 2);}
ll C(int n, int m) 
{
	ll a = 1, b = 1;
	for(int i = 1; i <= m; ++i) 
	{
		a = a * i % mod;
		b = b * (n - i + 1) % mod;
	}
	return b * inv(a) % mod;
}
int main()
{
	ll n, m, k;
	cin >> n >> m >> k;
	ll ans = C(n * m - 2, k - 2);
	ll A = n * n % mod * C(m + 1, 3) % mod;
	ll B = m * m % mod * C(n + 1, 3) % mod;
	ans = ans * (A + B) % mod;
	cout << ans << endl;
	return 0;
}
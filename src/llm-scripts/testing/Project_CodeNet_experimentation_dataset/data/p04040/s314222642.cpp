#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(),v.end()

const int maxn = 3e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int h, w, a, b;
ll fact[maxn], invfact[maxn], dp[maxn];

ll comb(int n, int r)
{
	return (fact[n] * (invfact[r] * invfact[n - r] % mod) % mod);
}

ll powmod(ll a, ll b)
{
	if (!b)
		return 1;
	ll tmp = powmod(a, b / 2);
	tmp = tmp * tmp % mod;
	if (b & 1)
		tmp = tmp * a % mod;
	return tmp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fact[0] = invfact[0] = 1;
	for (int i = 1; i < maxn; i++)
		fact[i] = fact[i - 1] * i % mod, invfact[i] = powmod(fact[i], mod - 2);

	scanf("%d %d %d %d", &h, &w, &a, &b);
	for (int i = 0; i < h - a; i++)
		dp[i] = comb(i + b - 1, i);

	ll ans = 0;
	for (int i = 0; i < h - a; i++)
		ans = (ans + dp[i] * comb(w - b - 1 + h - i - 1, w - b - 1) % mod) % mod;
	printf("%lld\n", ans);
}


#include<bits/stdc++.h>
#define ll long long int
#define f first
#define s second
#define pb push_back
#define PII pair<ll,ll>
ll const MOD = 998244353;
ll const N = 1000005;
ll const LN = 20;
ll const inf = 8e18;
using namespace std;

ll n, m, a[N];

ll cnt[N];


ll fact[N];
ll ifact[N];
ll bexpo (ll x, ll n, ll m)
{
	ll r = 1;
	x = x % m;
	while (n > 0)
	{
		if (n % 2) { r = (r * x) % m; }
		x = (x * x) % m;
		n = n / 2;
	}
	return r;
}
ll ncr (ll n, ll r)
{
	if (r > n) { return 0; }
	ll ans = fact[n];
	ans = (ans * ifact[r]) % MOD;
	ans = (ans * ifact[n - r]) % MOD;
	return ans;
}
void pre()
{
	fact[0] = 1;
	ifact[0] = 1;
	for (ll i = 1; i < N; i++) { fact[i] = (fact[i - 1] * i) % MOD; }
	ifact[N - 1] = bexpo (fact[N - 1], MOD - 2, MOD);
	for (ll i = N - 2; i > 0; i--)
	{ ifact[i] = (ifact[i + 1] * (i + 1)) % MOD; }
}
int main()
{
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	pre();
	ll n, k;
	cin >> k >> n;
	for (ll i = 2; i <= 2 * k; i++)
	{
		set<ll>st;
		for (ll j = 1; j <= k; j++)
		{
			if (j >= i)
			{
				continue;
			}
			ll oo = i - j;
			if (oo > k) { continue; }
			st.insert (oo);
			st.insert (j);
		}
		cnt[i] = (st.size() + 1) / 2;
	}
	for (ll i = 2; i <= 2 * k; i++)
	{
		if (1)
		{
			ll tot = ncr (n + k - 1, k - 1);
			for (ll j = 1; j <= cnt[i]; j++)
			{
				ll temp = ncr (cnt[i], j);
				temp *= ncr (n - 2 * j + k - 1, k - 1);
				temp %= MOD;
				if (j % 2) { tot -= temp; }
				else { tot += temp; }
				tot %= MOD;
				if (tot < 0) { tot += MOD; }
			}
			cout << tot << '\n';
		}
	}
	return 0;
}

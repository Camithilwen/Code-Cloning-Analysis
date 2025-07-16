#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define MOD 1000000007
#define all(c) c.begin(), c.end()
#define peek(v)      \
	for (auto i : v) \
		cout << i << ' ';

void solve()
{
	vector<ll> v(1001, 0);
	ll n, k;
	cin >> n;
	for (ll i = 2; i <= n; i++)
	{
		k = i;
		for (ll j = 2; k > 1;)
		{
			if (k % j == 0)
				k /= j, v[j]++;
			else
				j++;
		}
	}
	ll res = 1;
	for (ll i : v)
		res = res * (i + 1) % MOD;
	cout << res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	cerr << "\n\n~" << 500 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}
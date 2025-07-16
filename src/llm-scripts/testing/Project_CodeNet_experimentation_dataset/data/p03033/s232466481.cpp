#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0)
//#define MULTI_TEST
//#define GOOGLE
#ifdef LOCAL
#include "debugger.h"
#else
#define db(...)
#endif
#define ll long long
#define v32 vector<int>
#define v64 vector<ll>
#define s32 set<int>
#define s64 set<ll>
#define p32 pair<int, int>
#define p64 pair<ll, ll>
#define sz(v) (ll)(v).size()
#define fi first
#define se second
#define ln '\n'
const ll MOD = 1e9 + 7;
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }

void solve(int tc)
{
	int n, q;
	cin >> n >> q;
	map<ll, vector<p64>> hol;
	for (int i = 0; i < n; i++)
	{
		ll si, fi, xi;
		cin >> si >> fi >> xi;
		hol[xi].push_back({si, fi});
	}
	s64 peeps;
	map<ll, ll> ans;
	v64 D(q, 0);
	for (int i = 0; i < q; i++)
	{
		cin >> D[i];
		peeps.insert(D[i]);
	}
	for (auto itr : hol)
	{
		sort(itr.se.begin(), itr.se.end());
		for (auto x : itr.se)
		{
			ll si = x.fi, fi = x.se;
			ll xi = itr.fi;
			auto l = peeps.lower_bound(si - xi);
			auto r = peeps.upper_bound((2 * fi - 2 * xi - 1) / 2);
			if (r != peeps.begin())
				r--;
			else
				continue;
			queue<ll> rem;
			for (auto lol = l; lol != peeps.end() && *lol <= *r; lol++)
				ans[*lol] = xi, rem.push(*lol);
			while (sz(rem))
			{
				peeps.erase(rem.front());
				rem.pop();
			}
		}
	}
	for (ll x : D)
	{
		if (!ans.count(x))
			cout << -1 << ln;
		else
			cout << ans[x] << ln;
	}
	return;
}

int main()
{
#ifndef LOCAL
	FASTIO;
#endif
	int t = 1;
#ifdef LOCAL
	clock_t start, stop;
	start = clock();
#endif
#ifdef MULTI_TEST
	cin >> t;
#endif
	for (int tc = 1; tc < t + 1; tc++)
	{
#ifdef GOOGLE
		cout << "Case #" << tc << ": ";
#endif
		solve(tc);
	}
#ifdef LOCAL
	stop = clock();
	cerr << "Time :" << fixed << setprecision(5) << double(stop - start) / double(CLOCKS_PER_SEC) << "s" << ln;
#endif
	return 0;
}

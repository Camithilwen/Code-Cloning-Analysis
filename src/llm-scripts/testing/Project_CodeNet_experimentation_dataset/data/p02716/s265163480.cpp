// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dp[200005][4];

vector < ll > vec;

const ll mn = -1e18;

ll solve(ll pos, ll skip)
{
	ll &ret = dp[pos][skip];

	if(ret != mn) return ret;

	if(pos >= vec.size())
	{
		if(vec.size() & 1)
			if(skip == 2) return ret = mn + 2;

		return ret = 0;
	}

	ret = solve(pos + 2, skip) + vec[pos];

	if(skip) ret = max(ret, solve(pos + 1, skip - 1));

	return ret;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		vec.clear();
		vec.resize(n);

		for(ll i = 0; i < n; i++) cin >> vec[i];

		for(ll i = 0; i <= n + 3; i++) for(ll j = 0; j < 4; j++) dp[i][j] = mn;

		ans = solve(0,(n % 2) + 1);

		cout << ans << "\n";

    }


}




#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr(i,k) for(i=0;i<k;i++)
#define deb(x) cerr<<#x<<"  = "<<x<<endl;
#define deb2(x,y) cerr<<#x<<" ="<<x<<endl<<#y<<" ="<<y<<endl;
#define SZ(x) (x).size();
#define ll long long
#define mod 1000000007
#define ff first
#define ss second
#define pb push_back
#define em emplace_back
#define ulli unsigned long long int
#define inf 1e18
#define endl "\n"
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
void solve();

int main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	t = 1;

	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

ll dp[10001][101][2];

ll calc(string &k, ll pos, ll D, ll d, ll tight)
{
	if (dp[pos][d][tight] != -1)
		return dp[pos][d][tight];

	ll ub = tight ? (k[pos] - '0') : 9;

	if (pos == k.length() - 1)
	{
		ll ans = 0;
		for (ll x = 0; x <= ub; x++)
		{
			if (x % D == d)
				ans++;
		}

		return ans;
	}

	ll ans = 0;
	for (ll x = 0; x <= ub; x++)
	{
		ans = (ans + calc(k, pos + 1, D, (D + d - x % D) % D, tight && (x == ub))) % mod;
	}


	return dp[pos][d][tight] = ans;



}

inline void solve()
{
	ll D, i;
	string k;
	cin >> k >> D;

	memset(dp, -1, sizeof dp);

	cout << (mod + calc(k, 0, D, 0, 1) - 1) % mod << endl;
}

#include <bits/stdc++.h>
#include<string>
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define len(s) s.length()
#define all(v) v.begin(),v.end()
const ll INF = LONG_MAX;
const int N = 2e5 + 5;
const ll mod = 1000000007 ;
using namespace std;

ld dp[15][15];

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);


	ll tc = 1;
	// cin >> tc;

	while (tc--) {

		ll m;
		ll i, j;

		ll n;
		ll k;
		ll h1, m1, h2, m2;
		cin >> h1 >> m1 >> h2 >> m2 >> k;

		ll ans = (h2 * 60 + m2 - (h1 * 60 + m1) - k);

		cout << ans << endl;


	}
}
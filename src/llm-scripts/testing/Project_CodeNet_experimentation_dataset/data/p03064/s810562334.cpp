#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define REP(NAME, NUM) for (int NAME = 0; NAME < (NUM); ++NAME)
#define BREP(NAME, NUM) for (int NAME = (NUM)-1; NAME >= 0; --NAME)
#define ALL(NAME) (NAME).begin(), (NAME).end()

#define cMOD 998244353;

int main()
{
	ll n = 0;
	cin >> n;
	vector<ll> a( n, 0 );
	REP(i,n)cin>>a[i];
	ll sum = 0;
	REP(i,n) sum += a[i];
	
	vector<ll> dp( sum + 1, 0 );
	vector<ll> dp2( sum + 1, 0 );

	dp[0] = 1;
	dp2[0] = 1;
	REP( i, n ) BREP( j, sum + 1 )
	{
		dp[j] *= 2;
		if( a[i] <= j ) dp[j] += dp[j - a[i]];
		dp[j] %= cMOD;
		
		if( a[i] <= j ) dp2[j] += dp2[j - a[i]];
		dp2[j] %= cMOD;
		//cout << i << " " << j << " " << dp2[j] << endl;
	}
	
	ll ans = 0;
	for( int i= ( sum + 1 ) / 2; i <= sum; ++i )
		ans = ( ans + dp[i] ) % cMOD;

	ll all = 1;
	REP( i, n ) all = ( all * 3 ) % cMOD;

	ans = all - ans * 3;
	if( sum % 2 == 0 ) ans = ans + dp2[sum/2] * 3;
	while( ans < 0 ) ans += cMOD;
	ans %= cMOD;

	cout << ans << endl;
	return 0;
}
/**
 *		author:  zvm
 *		created: 25.09.2020 13:51:29
**/

#include <bits/stdc++.h>

using namespace std ;

typedef long long int ll ;
const ll INF = 1e18 ;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	int n ;
	cin >> n ;

	vector<int> a(n), b(n), c(n);

	for( int i = 0 ; i < n ; ++i ) {
		cin >> a[i] ;
	}
	for( int i = 0 ; i < n ; ++i ) {
		cin >> b[i] ;
	}
	for( int i = 0 ; i < n ; ++i ) {
		cin >> c[i] ;
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());

	vector<pair<int,ll>> good(n);
	for( int i = 0 ; i < n ; ++i ) {
		good[i].first = b[i] ;
		good[i].second = c.end() - upper_bound(c.begin(),c.end(),b[i]) ;
	}

	for( int i = n-2 ; i >= 0 ; --i ) {
		good[i].second += good[i+1].second ;
	}

	ll ans = 0 ;
	for( int i = 0 ; i < n ; ++i ) {
		pair<int,ll> to_find{a[i],INF};
		auto pos = upper_bound(good.begin(),good.end(),to_find) ;
		if( pos != good.end() ) {
			ans += (*pos).second ;
		}
	}
	
	cout << ans << endl ;
}

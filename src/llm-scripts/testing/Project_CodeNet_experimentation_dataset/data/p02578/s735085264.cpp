#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int ans = 0 ;
	int mx = 0 ;
	for(int i = 0 ; i < n ; i++){
		mx = max(mx , a[i]) ;
		ans += mx - a[i] ;
	}
	cout << ans ;
	return 0 ;
}


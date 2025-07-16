#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

const int bound = 1000*1000+10;
bool besucht[bound];

void init(){
	for( int i = 0; i < bound; ++i ) besucht[i] = false;
}

int no(){
	cout << 0 << endl;
	return 0;
}

int main(){
	int n, m; cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for( auto &k : a ){
		cin >> k;
		if( besucht[k] ) return no();
		besucht[k] = true;
	}
	init();
	for( auto &k : b ){
		cin >> k;
		if( besucht[k] ) return no();
		besucht[k] = true;
	}
	sort( a.begin(), a.end() );
	sort( b.begin(), b.end() );
	ll ans = 1;
	for( int k = 1; k <= n*m; ++k ){
		bool ares = binary_search( a.begin(), a.end(), k );
		bool bres = binary_search( b.begin(), b.end(), k );
		ll comb = 1;
		if( !bres ) comb *= (b.end() - lower_bound( b.begin(), b.end(), k ));
		if( !ares ) comb *= (a.end() - lower_bound( a.begin(), a.end(), k ));
		if( !ares && !bres ) comb -= n*m-k;
		ans *= comb;
		ans %= mod;
	}
	cout << ans << endl;
}
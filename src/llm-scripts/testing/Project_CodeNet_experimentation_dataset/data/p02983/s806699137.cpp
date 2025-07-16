#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll l, r;
	cin >> l >> r;
	ll ans = 2018;
	chmin(r, l+2019);
	for(ll i = l; i < r; ++i){
		for(ll j = i+1; j <= r; ++j){
			chmin(ans, (i*j)%2019);
		}
	}
	cout << ans << endl;
	return 0;
}

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
	ll n, m;
	cin >> n >> m;
	for(ll i = m/n; i >= 1; --i){
		ll r = m - i * n;
		if(r < 0) continue;
		if(r%i == 0){
			cout << i << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}

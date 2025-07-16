#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, mod = 1;
	cin >> n;
	if(n == 0){
		cout << 0 << endl;
		return 0;
	}
	string ans = "";
	while(n != 0){
		ll nex = mod * (-2);
		ll hoge = (n % nex != 0);
		ans += to_string(hoge);
		n -= hoge * mod;
		mod = nex;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}
#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

ll gcd(ll x, ll y){
	if(x%y == 0) return y;
	else return gcd(y, x%y);
}

int main(){
	ll a, b;
	cin >> a >> b;
	ll c = gcd(a, b);
	ll sqc = static_cast<ll>(sqrt(c));
	ll ans = 0;
	for(ll i = 2; i <= sqc; i++){
		ll k = 0;
		while (c% i == 0) {
			c/=i;
			k++;
		}
		if(k != 0) ans++;
	}
	if(c != 1) ans++;
	cout << ans+1 << endl;
}

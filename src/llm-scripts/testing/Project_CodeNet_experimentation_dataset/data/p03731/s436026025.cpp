#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define pb push_back
#define fi first
#define se second

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	ll n, m; cin >> n >> m;
	ll t[200005];
	rep(i, 0, n) cin >> t[i];
	ll ans = 0;
	rep(i, 1, n){
		if((t[i]-t[i-1])>m) ans += m;
		else ans += t[i]-t[i-1];
	}
	ans += m;
	cout << ans << endl;
	return 0;
}
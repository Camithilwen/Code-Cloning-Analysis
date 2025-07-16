#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

const int mod = 2019;
const int INF = 1e16;
int main() {
	ll l, r;
	cin >>l >>r;
	ll ans(INF);
	for (ll i = l; i < r; ++i) {
		for (ll j = l + 1; j <= r; ++j) {
			ll ii = i % mod;
			ll jj = j % mod;
			ll can = ii * jj;
			can %= mod;
			ans = min(ans, can);
			if (ans == 0) {
				cout << 0;
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}
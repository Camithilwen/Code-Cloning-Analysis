#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
ll c[200100], d[200100]; 


int main() {
	int m;
	cin >> m;
	rep(i,m) cin >> d[i] >> c[i];
	ll s = 0, len = 0;
	rep(i,m) {
		s += c[i] * d[i];
		len += c[i];
	}
	ll ans = (len-1) + ((s-1)/9);
	cout << ans << endl;

	return 0;
}
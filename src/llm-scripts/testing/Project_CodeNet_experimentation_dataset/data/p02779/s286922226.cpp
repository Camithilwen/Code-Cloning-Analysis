#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	map<ll, ll> mp;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		mp[a]++;
	}
	ll cnt = 0;
	for (auto u : mp) {
		if (1 < u.second) cnt++;
	}
	string ans = "YES";
	if (1 <= cnt) ans = "NO";
	cout << ans << endl;
    return 0;
}
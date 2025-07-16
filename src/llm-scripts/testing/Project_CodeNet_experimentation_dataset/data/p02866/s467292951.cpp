#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n; cin >> n;
	int p = n + 5;
	vector<ll> num(p, 0);
	ll initial;
	ll maximumValue = 0;
	for (int i = 0; i < n; i++) {
		ll d; cin >> d;
		num[d]++;
		maximumValue = max(maximumValue, d);
		if (i == 0) initial = d;
	}
	if (initial != 0 || 2 <= num[0]) {
		cout << 0 << endl;
		return 0;
	}
	const ll mod = 998244353;
	ll ans = 1;
	for (int i = 2; i <= maximumValue; i++) {
		int tmpCnt = num[i];
		while (tmpCnt--) {
			ans *= num[i - 1];
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}
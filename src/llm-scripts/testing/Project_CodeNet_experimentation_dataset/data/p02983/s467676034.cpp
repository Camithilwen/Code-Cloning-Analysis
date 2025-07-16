#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll l,r,ans=2e9;
	cin >> l >> r;
	if (r-l+1 <= 2019) {
		for (ll i=l; i<r; i++) {
			for (ll j=i+1; j<=r; j++) {
				ans = min(ans, ((i%2019)*(j%2019))%2019);
			}
		}
		cout << ans << '\n';
	} else {
		cout << 0 << '\n';
	}
	return 0;
}

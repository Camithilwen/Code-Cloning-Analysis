#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	ll n, ans = 0;
	cin >> n;
	vector<ll> a(n), b(n), c(n);
	rep(i,n) cin >> a[i];
	sort(a.begin(), a.end());
	rep(i,n) cin >> b[i];
	sort(b.begin(), b.end());
	rep(i,n) cin >> c[i];
	sort(c.begin(), c.end());

	for (int i = 0; i < n; i++) {
		ll L = -1 , R = n;

		while (abs(L - R) > 1) {
			int mid = (L + R) / 2;
			if (a[mid] < b[i]) L = mid;
			else R = mid;
		}
		ll down = L;

		L = -1; R = n;

		while (abs(L - R) > 1) {
			int mid = (L + R) / 2;
			if (c[mid] > b[i]) R = mid;
			else L = mid;
		}
		ll up = R;
		ans += (down + 1) * (n - up);
	}
	cout << ans << endl;
	return 0;
}
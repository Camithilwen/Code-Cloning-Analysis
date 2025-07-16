#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll x; cin >> x;
	ll ans = 0;
	ll quo = x / 11;
	ll mod = x % 11;
	if (mod == 0) {
		ans = quo * 2;
	}
	else if (1 <= mod && mod <= 6) {
		ans = quo * 2 + 1;
	}
	else { // 6 < mod <= 11
		ans = quo * 2 + 2;
	}

	cout << ans << endl;
	return 0;
}
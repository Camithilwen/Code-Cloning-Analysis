#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	const ll p = 26;
	string  ans = "";
	ll tmp = n;
	while (true) {
		tmp--;
		ll mod = tmp % p;
		string mod_s{ (char)('a' + mod) };
		ans += mod_s;
		if (tmp / p == 0) break;
		tmp /= p;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
    return 0;
}
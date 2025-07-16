#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<utility>
#include<map>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll p, ll n, ll m) {
	if (n == 0) return 1;
	else if (n == 1) return p % m;
	else if (n % 2 == 1) return p * pow_mod(p, n - 1, m) % m;
	else {
		ll tmp = pow_mod(p, n / 2, m);
		return (tmp * tmp) % m;
	}
}

ll gcd(ll x, ll y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

ll com_mod(ll n, ll k, ll m) {
	if (k == 0) return 1;
	else {
		ll x = 1;
		ll y = 1;
		for (ll i = 0; i < k; i++) {
			x = (x * (n - i)) % m;
			y = (y * (i + 1)) % m;
		}
		ll res = (x * pow_mod(y, m - 2, m)) % m;
		return res;
	}
}

int main() {
	int r; cin >> r;
	if (r < 1200)cout << "ABC" << endl;
	else if (r < 2800) cout << "ARC" << endl;
	else cout << "AGC" << endl;
	return 0;
}
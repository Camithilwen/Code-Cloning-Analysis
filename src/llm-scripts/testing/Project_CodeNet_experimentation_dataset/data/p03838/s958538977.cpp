#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	ll x, y,ans=0;
	cin >> x >> y;
	if (x * y == 0) {
		ans = abs(x) + abs(y);
		if (y < x)ans++;
	}
	else if (x * y < 0) {
		ans = abs(abs(x) - abs(y)) + 1;
	}
	else if (0 < x * y) {
		ans = abs(abs(x) - abs(y));
		if (y < x)ans += 2;
	}
	cout << ans << endl;
	return 0;
}


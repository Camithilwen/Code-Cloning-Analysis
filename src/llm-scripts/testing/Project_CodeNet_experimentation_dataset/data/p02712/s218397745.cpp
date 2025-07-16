#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	ll n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0 || i % 5 == 0) continue;
		ans += i;
	}
	cout << ans << endl;
	return 0;
}

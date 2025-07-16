#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e5 + 10;
int n, a[maxn];
int c0, c1, cnt, GCD;

bool solve() {
	c1 = 0, c0 = 0, cnt = 0, GCD = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			c1++;
			cnt++;
			continue;
		}
		if (a[i] % 2) {
			c1++;
			a[i]--;
		}
		else
			c0++;
		GCD = __gcd(GCD, a[i]);
	}
	if (c0 % 2) 		 return 1;
	if (cnt || c1 > 1) return 0;
	for (int i = 0; i < n; i++) a[i] /= GCD;
	return !solve();
}
int32_t main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (solve())
		cout << "First";
	else
		cout << "Second";
	return 0;
}
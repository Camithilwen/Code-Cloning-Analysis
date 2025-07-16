#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mn = INT_MAX;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		if (i + 1 < n && a[i] < 0) {
			a[i + 1] *= -1;
			a[i] *= -1;
		}
		res += abs(a[i]);
		mn = min(mn, abs(a[i]));
	}
	if (a[n - 1] < 0) res -= 2 * mn;
	cout << res;
	return 0;
}
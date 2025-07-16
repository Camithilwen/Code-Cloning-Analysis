#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)

int main() {
	int n, m;
	int s, c;
	int ans = 0;
	cin >> n >> m;
	vector<int> a(3);
	a[0] = a[1] = a[2] = 10;
	rep(i, m) {
		cin >> s >> c;
		if (a[s - 1] != 10 && a[s - 1] != c) {
			cout << -1 << endl;
			return 0;
		}
		else {
			a[s - 1] = c;
		}
	}
	if (a[0] == 0 && n != 1) {
		cout << -1 << endl;
		return 0;
	}
	else {
		if (a[0] == 10) {
			if (n == 1)a[0] = 0;
			else a[0] = 1;
		}
		for (int i = 1; i<n; i++) {
			if (a[i] == 10)a[i] = 0;
		}
		rep(i, n) {
			ans += a[i] * pow(10, n - i - 1);
		}
	}
	cout << ans << endl;

	return 0;
}

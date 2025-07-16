#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	const int inf = 1e9 + 1e8;
	int n, k; cin >> n >> k;
	vector<int> x(n);
	int pos = 0;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		if (x[i - 1] < 0 && x[i] > 0) pos = i;
		if (x[i] == 0) {
			pos = i;
			k--;
			flag = true;
		}
	}
	if (x[pos] < 0) pos = n;
	if (flag) {
		for (int i = pos; i + 1 < n; i++) x[i] = x[i + 1];
		n--;
	}
	int ans = k == 0 ? 0 : inf;
	for (int i = 0; i < n; i++) {
		if (i < pos) {
			int cnt = pos - i;
			if (cnt >= k) {
				ans = min(ans, -x[i]);
			} else {
				if (k + i - 1 < n) ans = min(ans, -2 * x[i] + x[k + i - 1]);
			}
		} else {
			int cnt = i - pos + 1;
			if (cnt >= k) {
				ans = min(ans, x[i]);
			} else {
				if (i - k + 1 >= 0) ans = min(ans, 2 * x[i] - x[i - k + 1]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}

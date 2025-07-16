#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	reverse(b.begin(), b.end());
	int start = -1, fin = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] == b[i]) {
			if (start == -1) start = i;
			fin = i;
		}
	}
	bool bad = 0;
	if (start != -1) {
		for (int i = 0, j = start; j <= fin; ++i) {
			if (i == start) i = fin + 1;
			if (i == n) {
				bad = 1;
				break;
			}
			if (a[i] != b[j] && b[j] != b[i]) {
				swap(b[i], b[j++]);
			}
		}
	}
	if (bad) {
		cout << "No" << '\n';
	} 
	else {
		cout << "Yes" << '\n';
		for (int i = 0; i < n; ++i) {
			if (i) cout << " ";
			cout << b[i];
		}
		cout << '\n';
	}

	return 0;
}
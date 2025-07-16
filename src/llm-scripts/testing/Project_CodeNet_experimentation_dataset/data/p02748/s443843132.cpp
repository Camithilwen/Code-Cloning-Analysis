#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int na, nb, nt;
	cin >> na >> nb >> nt;
	vector<int> a(na), b(nb);
	for (int i = 0; i < na; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < nb; i++) {
		cin >> b[i];
	}
	int ans = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
	for (int i = 0; i < nt; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		x--; y--;
		ans = min(ans, a[x] + b[y] - c);
	}
	cout << ans << '\n';
}

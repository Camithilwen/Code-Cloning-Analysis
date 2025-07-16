#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, a[300][300], c[300], ans;
bool removed[300];

int main() {
	cin >> n >> m;
	ans = n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			--a[i][j];
		}

	for (int i = 0; i < m; ++i) { //iコ除外
		fill(c, c + m, 0);
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (removed[a[j][k]])
					continue;
				++c[a[j][k]];
				break;
			}
		}

		int idx = 0;
		for (int j = 0; j < m; ++j)
			if (c[j] > c[idx])
				idx = j;
		ans = min(ans, c[idx]);
		removed[idx] = 1;
	}
	cout << ans << endl;
}

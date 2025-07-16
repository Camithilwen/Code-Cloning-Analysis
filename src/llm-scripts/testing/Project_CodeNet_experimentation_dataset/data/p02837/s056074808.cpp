#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int x[20][20], y[20][20],a[20];
int main() {
	int n;
	cin >> n;
	rep(i,n) {
		cin >> a[i];
		rep(j,a[i]) {
			cin >> x[i][j] >> y[i][j];
			x[i][j]--;
		}
	}

	int ans = 0;
	rep(bit, (1<<n)) {
		bool ok = true;
		rep(i,n) {
			if (!((bit >> i) & 1)) continue;
			rep(j,a[i]) {
				if (((bit>>x[i][j]) & 1) ^ y[i][j]) ok = false;
			}
		}
		if (ok) ans = max(ans, __builtin_popcount(bit));
	}
	cout << ans << endl;
	return 0;
}
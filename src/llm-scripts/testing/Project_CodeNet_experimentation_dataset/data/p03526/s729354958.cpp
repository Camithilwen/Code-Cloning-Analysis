#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const long long inf = 1e18;

int n, H[N], P[N];
int a[N];
long long f[N][N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> H[i] >> P[i], a[i] = i;
	sort(a + 1, a + n + 1, [&](int x, int y) {
		return H[x] + P[x] < H[y] + P[y];
	});
	
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) f[i][j] = inf;
	}

	f[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			f[i][j] = f[i-1][j];
			if (j > 0 && H[a[i]] >= f[i-1][j-1]) {
				f[i][j] = min(f[i][j], f[i-1][j-1] + P[a[i]]);
			}
		}
	}

	for (int i = n; i >= 0; --i) if (f[n][i] != inf) {
		cout << i << endl; return 0;
	}
}
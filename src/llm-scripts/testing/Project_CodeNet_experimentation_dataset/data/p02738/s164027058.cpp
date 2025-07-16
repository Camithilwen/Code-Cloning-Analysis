#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxN = 2000 + 5;
int n;
LL P;
LL f[maxN * 3][maxN];

int main() {
	cin >> n >> P;
	f[0][0] = 1;
	for(int i = 0; i <= n * 3; ++i) {
		for(int j = 0; j <= i / 2 && j <= n; ++j) {
			(f[i + 1][j] += f[i][j]) %= P;
			(f[i + 2][j + 1] += f[i][j] * (i + 1)) %= P;
			(f[i + 3][j + 1] += f[i][j] * (i + 2) % P * (i + 1)) %= P;
		}
	}
	LL ans = 0;
	for(int j = 0; j <= n; ++j) (ans += f[3 * n][j]) %= P;
	cout << ans << endl;
	return 0;
}

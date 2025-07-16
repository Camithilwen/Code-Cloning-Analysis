/* In the name of Allah */
#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int n, m, q, a[N][N], dp[N][N][3];

int get(int b, int xl, int xr, int yl, int yr) {
	return dp[xr][yr][b] - dp[xl][yr][b] - dp[xr][yl][b] + dp[xl][yl][b];
}

void read_input() {
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
}

void solve() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			dp[i][j][0] = (a[i][j] && a[i][j + 1]) + dp[i - 1][j][0] + dp[i][j - 1][0] - dp[i - 1][j - 1][0];
			dp[i][j][1] = (a[i][j] && a[i + 1][j]) + dp[i - 1][j][1] + dp[i][j - 1][1] - dp[i - 1][j - 1][1];
			dp[i][j][2] = a[i][j] + dp[i - 1][j][2] + dp[i][j - 1][2] - dp[i - 1][j - 1][2];
		}
}

void write_output() {
	while (q--) {
		int xl, xr, yl, yr;
		cin >> xl >> yl >> xr >> yr;
		cout << get(2, xl - 1, xr, yl - 1, yr) - get(1, xl - 1, xr - 1, yl - 1, yr) - get(0, xl - 1, xr, yl - 1, yr - 1) << endl;
	}
}

int main() {
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	read_input(), solve(), write_output();
	return 0;
}

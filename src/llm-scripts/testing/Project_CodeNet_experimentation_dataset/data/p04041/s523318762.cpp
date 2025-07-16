#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int dp[45][(1 << 17) + 5];
int main() {
	int n, X, Y, Z;
	cin >> n >> X >> Y >> Z;
	int ban = (1 << Z - 1) | (1 << Y + Z - 1) | (1 << X + Y + Z - 1);
	dp[0][0] = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 1; j < 11; ++j) {
			for(int S = 0; S < 1 << 17; ++S) {
				int nxt = (S << j | 1 << j - 1) & ((1 << 17) - 1);
				if((nxt & ban) != ban) {
					dp[i + 1][nxt] = (dp[i + 1][nxt] + dp[i][S]) % P;
				}
			}
		}
	}
	int ans = 1;
	for(int i = 0; i < n; ++i) {
		ans = 1LL * ans * 10 % P;
	}
	for(int S = 0; S < 1 << 17; ++S) {
		ans = (ans - dp[n][S] + P) % P;
	}
	cout << ans << '\n';
	return 0;
}
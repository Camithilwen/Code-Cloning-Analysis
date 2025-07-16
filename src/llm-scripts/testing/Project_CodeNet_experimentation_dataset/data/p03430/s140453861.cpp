#include <bits/stdc++.h>
using namespace std;
string s;
int n, dp[305][305][305];
int go(int l, int r, int k) {
	if (dp[l][r][k] != -1) return dp[l][r][k];
	if (l == r) {
		return dp[l][r][k] = 1;
	}
	if (l + 1 == r) {
		if (s[l] == s[r] || k) {
			return dp[l][r][k] = 2;
		} else {
			return dp[l][r][k] = 1;
		}
	}
	dp[l][r][k] = max(go(l + 1, r, k), go(l, r - 1, k));
	if (s[l] == s[r]) {
		dp[l][r][k] = max(dp[l][r][k], go(l + 1, r - 1, k) + 2);
	} else if (k) {
		dp[l][r][k] = max(dp[l][r][k], go(l + 1, r - 1, k - 1) + 2);
	}
	return dp[l][r][k];
}
int main() {
	int k;
	cin >> s >> k;
	n = s.size();
	memset(dp, -1, sizeof(dp));
	cout << go(0, n - 1, k) << endl;
	return 0;
}
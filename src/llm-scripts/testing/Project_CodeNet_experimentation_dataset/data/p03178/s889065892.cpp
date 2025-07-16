#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxD = 110, mxN = 1e4 + 5, mod = 1e9 + 7;
string K;
int D, n;
vector<int> digits;
ll dp[mxN][mxD][2];

ll rec(int idx, int sum, int flag) {
	if (idx == n) {
		if (sum % D == 0) {
			return 1;
		}
		return 0;
	}
	if (dp[idx][sum][flag] != -1) {
		return dp[idx][sum][flag];
	}
	int limit = (flag == 1)? digits[idx] : 9;
	ll ans = 0;
	for (int i = 0; i <= limit; i++) {
		if (i == digits[idx]) {
			ans = (ans + rec(idx + 1, (sum + i) % D, flag)) % mod;
		} else {
			ans = (ans + rec(idx + 1, (sum + i) % D, 0)) % mod;
		}
	}
	return dp[idx][sum][flag] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> K >> D;
	n = (int) K.length();
	for (char it : K) {
		digits.push_back(it - '0');
	}
	memset(dp, -1, sizeof(dp));
	ll ans = rec(0, 0, 1);
	ans = (ans - 1 + mod) % mod;
	cout << ans;
	
	return 0;
}

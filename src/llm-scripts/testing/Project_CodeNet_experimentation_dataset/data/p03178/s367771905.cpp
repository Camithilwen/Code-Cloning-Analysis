#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MOD 1000000007
#define ar array
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int32_t main() {
	fast_io;

	// int t; cin >> t;
	// while (t--) {

	// }
	string K; cin >> K;
	int D; cin >> D;
	int len = (int) K.size();
	vector<vector<int>> dp(D, vector<int> (2));

	for (int digit = 0; digit < K[0] - '0'; digit++) {
		dp[digit % D][true]++;
	}
	dp[(K[0] - '0') % D][false]++;

	for (int pos = 1; pos < len; pos++) {
		vector<vector<int>> new_dp(D, vector<int> (2));
		for (int sum = 0; sum < D; sum++) {
			for (bool choose_any_digit : {false, true}) {
				for (int digit = 0; digit < 10; digit++) {
					if (digit > K[pos] - '0' && !choose_any_digit) {
						break;
					}
					new_dp[(sum + digit) % D][choose_any_digit || digit < K[pos] - '0'] += dp[sum][choose_any_digit];
					new_dp[(sum + digit) % D][choose_any_digit || digit < K[pos] - '0'] %= MOD;
				}
			}	
		}
		dp = new_dp;
	}
	int res = (dp[0][true] + dp[0][false]);
	res--;
	if (res < 0) {
		cout << res + MOD << endl;
	}
	else {
		cout << res << endl;
	}

	return 0;
}
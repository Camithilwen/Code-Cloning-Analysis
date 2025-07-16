#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<vector<long long>>dp(n, vector<long long>(2, 0));
	dp[0][0] = v[0];
	dp[0][1] = -v[0];
	for (int i = 1; i < n - 1; i++) {
		dp[i][0] = max(dp[i - 1][0] + v[i], dp[i - 1][1] - v[i]);
		dp[i][1] = max(dp[i - 1][0] - v[i], dp[i - 1][1] + v[i]);
	}
	cout << (max(dp[n - 2][0] + v[n - 1], dp[n - 2][1] - v[n - 1])) << endl;
}
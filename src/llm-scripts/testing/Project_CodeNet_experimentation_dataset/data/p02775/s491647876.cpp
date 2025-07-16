#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, k = 0, ans = 0;
	string s;
	cin >> s;
	vector<vector<ll>> dp(s.size() + 1, vector<ll>(2, 0));
	dp[0][1] = 1;
	rep(i, s.size()) {
		int n = s[i] - '0';
		dp[i + 1][0] = min(dp[i][0] + n, dp[i][1] + 10 - n);
		dp[i + 1][1] = min(dp[i][0] + n + 1, dp[i][1] + 10 - n - 1);
	}
	cout << dp[s.size()][0] << "\n";
	return 0;
}
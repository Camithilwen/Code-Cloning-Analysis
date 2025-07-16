#include <iostream>
#include <vector>
#define pb push_back
#define mp make_pair
using namespace std;

const long long INF = 2e18 + 18;

vector<long long> dp, cost;
vector<vector<long long> > c; 

void solve() {
	int n; cin >> n;
	c.resize(n, vector<long long>(n));
	dp.resize((1 << n), -INF);
	cost.resize((1 << n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	}
	for (int mask = 0; mask < (1 << n); mask++) {
		long long res = 0;
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				for (int j = i + 1; j < n; j++) {
					if (mask & (1 << j)) {
						res += c[i][j];
					}
				}
			}
		}
		cost[mask] = res;
	}
	dp[(1 << n) - 1] = 0;
	for (int mask = (1 << n) - 1; mask >= 0; mask--) {
		for (int submask = mask; ; submask = (submask - 1) & mask) {
			dp[mask - submask] = max(dp[mask - submask], dp[mask] + cost[submask]);
			if (submask == 0) break;
		}
	}
	cout << dp[0] << endl;
}

int main() {
	solve();
	return 0;
}
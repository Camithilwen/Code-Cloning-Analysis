#include <iostream>
using namespace std;
const long long OO = (long long) 1e18;
 
const int N = 200008;
int n;
long long a[N];
 
long long dp[N][3];
// dp[i][j] is maximum possible sum choosing (i+1-j)/2 elements from first i
// elements. This is NOT a floor! So half the dp elements will be impossible
// solely because it's impossible to choose half an element.
 
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
 
	dp[0][0] = -OO;
	dp[0][1] = 0;
	dp[0][2] = -OO;
	dp[1][0] = a[0];
	dp[1][1] = -OO;
	dp[1][2] = 0;
 
	for (int i = 2; i <= n; i++) {
		// note that we are computing dp[i] using a[i-1] and dp[i-1]
		for (int j = 0; j < 3; j++) {
			// take a[i-1]
			dp[i][j] = dp[i-2][j] + a[i-1];
 
			if (j) {
				// we have slack; don't take a[i-1]
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
			}
		}
	}
 
	cout << dp[n][n % 2 == 0 ? 1 : 2];
}
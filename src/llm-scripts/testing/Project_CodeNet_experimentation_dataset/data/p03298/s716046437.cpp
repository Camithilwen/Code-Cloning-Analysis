#include <bits/stdc++.h>
using namespace std;

long long ans, n;
 
int main() {
    string s;
    cin >> n >> s;
    for (int i = 0; i < (1 << n); i++) {
        string lr, lb;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j))
                lr += s[j];
            else
                lb += s[j];
        }
 	//cerr << lr << " " << lb << "\n";
        long long dp[40][20];
        memset(dp, 0, sizeof dp);
        dp[n * 2][0] = 1;
        for (int j = n * 2 - 1; j >= n; j--) {
            for (int k = 0; k <= (int)lr.size(); k++) {
                dp[j][k] += (k > 0) * dp[j + 1][k - 1] * (s[j] == lr[k - 1]);
                dp[j][k] += dp[j + 1][k] * (s[j] == lb[(n * 2 - j) - k - 1]);
            }
        }        
		ans += dp[n][(int)lr.size()];
    }
    cout << ans;
    return 0;
}
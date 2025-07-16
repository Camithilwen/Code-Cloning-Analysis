#include<bits/stdc++.h>

using namespace std;

#define int long long

int dp[10010][110];
int mod = 1e9 + 7;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int d;
	cin >> d;
	int n = s.size();
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < 10; k++) {
                dp[i + 1][(j + k) % d] += dp[i][j];
                dp[i + 1][(j + k) % d] %= mod;
            }
        }
	}
	int sum = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i] - '0'; j++) {
            ans += dp[n - i - 1][(d - (sum + j) % d) % d];
            ans %= mod;
        }
        sum += s[i] - '0';
	}
	if (sum % d == 0) {
        ans++;
	}
	ans += mod - 1;
	ans %= mod;
	cout << ans << endl;
	return 0;
}

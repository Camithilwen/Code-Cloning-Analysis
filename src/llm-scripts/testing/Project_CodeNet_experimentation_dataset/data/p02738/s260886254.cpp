#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; ll MOD; cin >> n >> MOD;
    vector<vector<ll>> dp(3 * n + 1, vector<ll>(n + 1, 0));
    dp[0][0] = 1;
    for (ll i = 0; i < 3 * n; i++) {
        for (ll j = 0; j <= n; j++) {
            if (i + 1 <= 3 * n) ( dp[i+1][j] += dp[i][j] ) %= MOD;
            if (i + 2 <= 3 * n && j + 1 <= n) ( dp[i+2][j+1] += dp[i][j] * (i + 1) ) %= MOD;
            if (i + 3 <= 3 * n && j + 1 <= n) ( dp[i+3][j+1] += dp[i][j] * (i + 1) * (i + 2) ) %= MOD;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) ( ans += dp[3*n][i] ) %= MOD;
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1)));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j <= n - 1; j++) {
            for (int l = 0; l <= k; l++) {
                if (i == j) {
                    dp[i][j][l] = 1;
                } else if (i + 1 == j) {
                    dp[i][j][l] = 2;
                    if (l == 0 && s[i] != s[j]) {
                        dp[i][j][l] = 1;
                    }
                } else {
                    dp[i][j][l] = max(dp[i + 1][j][l], dp[i][j - 1][l]);
                    // dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j - 1][l] + 1);
                    if (s[i] == s[j]) {
                        dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j - 1][l] + 2);
                    } else if (l != 0) {
                        dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j - 1][l - 1] + 2);
                    }
                }
            }
        }
    }
    cout << dp[0][n - 1][k] << '\n';
    return 0;
}

#include "bits/stdc++.h"

#define int long long

using namespace std;

const int mod = 1e9 + 7;

int32_t main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> score(1 << n);
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
                continue;
            }
            for (int j = 0; j < i; j++) {
                if ((mask & (1 << j)) == 0) {
                    continue;
                }
                score[mask] += a[i][j];
            }
        }
    }
    vector<int> dp(1 << n, 0);
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int submask = mask; submask > 0; submask--, submask &= mask) {
            dp[mask] = max(dp[mask], score[submask] + dp[mask ^ submask]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}

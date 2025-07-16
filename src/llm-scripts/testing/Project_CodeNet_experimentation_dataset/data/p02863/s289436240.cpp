#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
#define int long long
int dp[6006], n, m, x, y, res;
pair<int, int> p[3003];
int32_t main() {
    DAU
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> p[i].first >> p[i].second;
    sort(p + 1, p + n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        tie(x, y) = p[i];
        for (int j = m - 1; j >= 0; --j)
            if (dp[j])
                dp[j + x] = max(dp[j + x], dp[j] + y);
    }
    for (int i = 1; i <= m + 3000; ++i)
        res = max(res, dp[i]);
    cout << res - 1;
    PLEC
}

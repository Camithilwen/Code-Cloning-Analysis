#include <iostream>
#include <algorithm>

using namespace std;

const long long mod = 1e9 + 7;
const int inf = 1e5 + 9, maxn = 2e2 + 9;
long long dp[maxn][inf], s[inf];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n);
    for (int i = 0; i < inf; i++) {
        dp[0][i] = i % s[0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] += dp[i - 1][j % s[i]] * 1LL + dp[i - 1][j] * i * 1LL;
            dp[i][j] %= mod * 1LL;
        }
    }
    cout << dp[n - 1][x] << '\n';
    return 0;
}

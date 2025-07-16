#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 998244353;

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    ll ans = 1LL, sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
        ans *= 3LL;
        ans %= M;
    }

    vector<vector<ll>> dp(500, vector<ll>(100000, 0));
    vector<vector<ll>> dp2(500, vector<ll>(100000, 0));
    dp[0][0] = dp2[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i + 1][j + a[i]] += dp[i][j];
            dp[i + 1][j + a[i]] %= M;
            dp[i + 1][j] += 2 * dp[i][j];
            dp[i + 1][j] %= M;

            dp2[i + 1][j + a[i]] += dp2[i][j];
            dp2[i + 1][j + a[i]] %= M;
            dp2[i + 1][j] += dp2[i][j];
            dp2[i + 1][j] %= M;
        }
    }

    ll x = 0;
    for (int i = (sum + 2 - 1) / 2; i <= sum; i++) {
        x += dp[N][i];
        x %= M;
    }

    ans -= 3 * x;
    if (sum % 2 == 0) ans += 3 * dp2[N][sum / 2];

    cout << (ans % M + M) % M << endl;
}
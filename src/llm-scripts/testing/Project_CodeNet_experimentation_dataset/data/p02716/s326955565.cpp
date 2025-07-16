#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
#define MAXN 200001
#define INF -200000000000000
ll a[MAXN];
ll dp[MAXN][3];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1][0] = a[1];
    dp[1][1] = a[2];
    dp[1][2] = a[3];
    for (int i = 2; i <= n / 2; i++) {
        dp[i][0] = dp[i - 1][0] + a[i * 2 - 1];
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) + a[i * 2];
        if (n % 2) dp[i][2] = max(dp[i - 1][2], max(dp[i - 1][1], dp[i - 1][0])) + a[i * 2 + 1];
    }
    if (n % 2) cout << max(max(dp[n / 2][2], dp[n / 2][1]), dp[n / 2][0]) << endl;
    else cout << max(dp[n / 2][1], dp[n / 2][0]) << endl;
    return 0;
}
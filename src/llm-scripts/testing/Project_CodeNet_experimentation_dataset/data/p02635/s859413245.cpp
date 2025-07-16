#include <bits/stdc++.h>

const int mod = 998244353;

const int max_N = 305;

using LL = long long;

int n, K, a[max_N];

LL dp[max_N][max_N][max_N];
// 前 i 个空隙, 共 j 个 1, 用了 k 步

char s[max_N];

int main() {
    scanf("%s", s);
    n = 1;
    for (int i = 0; i < max_N && s[i]; ++i) {
        if (s[i] == '0') {
            ++n;
        } else {
            ++a[n];
        }
    }
    for (int i = 2; i <= n; ++i) {
        a[i] += a[i - 1];
    }
    scanf("%d", &K);
    K = std::min(K, a[n]);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = a[i - 1]; j <= a[n]; ++j) {
            for (int k = 0; k <= K; ++k) {
                // 不移动 i, 且从后往 i 移动 m 步
                for (int m = 0; j + a[i] - a[i - 1] + m <= a[n] && k + m <= K; ++m) {
                    int j1 = j + a[i] - a[i - 1] + m;
                    dp[i][j1][k + m] = (dp[i][j1][k + m] + dp[i - 1][j][k]) % mod;
                }
                // 移动 i, 且从 i 往前移动 m 步
                for (int m = a[i] - a[i - 1]; m && j + a[i] - a[i - 1] - m <= a[n]; --m) {
                    int j1 = j + a[i] - a[i - 1] - m;
                    dp[i][j1][k] = (dp[i][j1][k] + dp[i - 1][j][k]) % mod;
                }
            }
        }
    }
    /*
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= a[n]; ++j) {
            for (int k = 0; k <= K; ++k) {
                if (dp[i][j][k]) {
                    printf("dp[%d][%d][%d] = %lld\n", i, j, k, dp[i][j][k]);
                }
            }
        }
    }*/
    LL ans = 0;
    for (int k = 0; k <= K; ++k) {
        ans = (ans + dp[n][a[n]][k]) % mod;
    }
    printf("%lld\n", ans);
}
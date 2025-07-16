#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 6005;
const int Maxm = 2005;

int n, mod;
int dp[Maxn][Maxm];

int main()
{
    scanf("%d %d", &n, &mod);
    dp[0][0] = 1;
    for (int i = 1; i <= 3 * n; i++)
        for (int j = 0; j <= n; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            if (i >= 2 && j >= 1)
                dp[i][j] = (dp[i][j] + ll(dp[i - 2][j - 1]) * (i - 1)) % mod;
            if (i >= 3 && j >= 1)
                dp[i][j] = (dp[i][j] + ll(dp[i - 3][j - 1]) * (i - 1) % mod * (i - 2)) % mod;
        }
    int res = 0;
    for (int j = 0; j <= n; j++)
        res = (res + dp[3 * n][j]) % mod;
    printf("%d\n", res);
    return 0;
}

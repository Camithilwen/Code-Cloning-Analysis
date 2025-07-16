#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 50;
const ll inf = 1e18;
const int mod = 998244353;
int sum,n;
int a[maxn];
ll dp[305][305 * 305];
ll ans = 1;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i),sum += a[i], ans = (ans * 3) % mod;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= sum; ++j)
        {
            dp[i][j] = dp[i - 1][j] * 2 % mod;
            if (j >= a[i])
                dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % mod;
        }
    }
    for (int i = (sum + 1) / 2; i <= sum; ++i)
        ans = (ans - dp[n][i] * 3 % mod + mod) % mod;
    if (sum % 2 == 0)
    {
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= sum; ++j)
            {
                dp[i][j] = dp[i - 1][j] % mod;
                if (j >= a[i])
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % mod;
            }
        }
        ans = (ans + dp[n][sum / 2] * 3) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
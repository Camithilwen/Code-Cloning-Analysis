#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;

const int maxn = 16, maxmask = 1ll << 16;

int n, a[maxn][maxn], dp[maxmask];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    for(int i = 0; i < (1 << n); i++)
    {
        for(int j = 0; j < n; j++)
            for(int k = j + 1; k < n; k++)
                if((i & (1ll << j)) && (i & (1ll << k)))
                    dp[i] += a[j][k];
        for(int j = i; j > 0; j = (j - 1) & i)
            dp[i] = max(dp[i], dp[j] + dp[i ^ j]);
    }
    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}
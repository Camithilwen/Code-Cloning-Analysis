//thuanqvbn03
#include <bits/stdc++.h>

using namespace std;

int n;
int a[16][16];
long long dp[1 << 16];

int GetBit(int num, int pos)
{
    return (num >> pos) & 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int m = (1 << n) - 1;
    for (int i = 1; i <= m; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (GetBit(i, j))
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (GetBit(i, k))
                    {
                        dp[i] += a[j][k];
                    }
                }
            }
        }
        int t = m / 2;
        for (int j = 1; j <= t; j = ((i & j) == j ? j + 1 : j + (j & -j)))
        {
            if ((i & j) == j)
            {
                dp[i] = max(dp[i], dp[j] + dp[i ^ j]);
            }
        }
    }
    cout << dp[m];
    return 0;
}
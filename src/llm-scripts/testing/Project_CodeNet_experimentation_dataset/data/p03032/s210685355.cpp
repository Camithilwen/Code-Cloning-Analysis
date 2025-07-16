#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 50 + 5, mod = 1e9 + 7;
int n, k;
int a[N], dp[N][N][102];

int solve(int l, int r, int left)
{
    if (l > r)
        return 0;
    if (dp[l][r][left] != -1)
        return dp[l][r][left];
    int ans = 0;
    if (a[l] < 0)
    {
        if (left > 0)
            ans = max(ans, solve(l + 1, r, left - 1) + a[l]);
        if (left > 1)
            ans = max(ans, solve(l + 1, r, left - 2));
    }
    if (a[l] >= 0 && left > 0)
        ans = max(ans, solve(l + 1, r, left - 1) + a[l]);
    if (a[r] < 0)
    {
        if (left > 0)
            ans = max(ans, solve(l, r - 1, left - 1) + a[r]);
        if (left > 1)
            ans = max(ans, solve(l, r - 1, left - 2));
    }
    if (a[r] >= 0 && left > 0)
        ans = max(ans, solve(l, r - 1, left - 1) + a[r]);
    return dp[l][r][left] = ans;
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << solve(0, n - 1, k);
    return 0;
}
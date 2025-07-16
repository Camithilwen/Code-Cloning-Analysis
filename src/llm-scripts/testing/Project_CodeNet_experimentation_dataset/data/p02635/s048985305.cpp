#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 302;

const int MOD = 998244353;

int n, k;

string s;

int m;

int a[N_MAX];
int spa[N_MAX];

int dp[N_MAX][N_MAX][N_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> k;
    n = s.size();
    s = " " + s;
    for(int i = 1; i <= n; i++)
        if(s[i] == '1')
            a[i - (++m) + 1]++;
    for(int i = 1; i <= n; i++)
        spa[i] = spa[i - 1] + a[i];
    k = min(k, n);
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int sp = spa[i]; sp <= spa[n]; sp++)
            for(int sum = 0; sum <= k; sum++)
            {
                for(int x = 1; x <= sum && (a[i] - x) <= sp && x <= a[i]; x++)
                {
                    dp[i][sp][sum] += dp[i - 1][sp - (a[i] - x)][sum - x];
                    if(dp[i][sp][sum] >= MOD)
                        dp[i][sp][sum] -= MOD;
                }
                for(int x = 0; (a[i] + x) <= sp; x++)
                {
                    dp[i][sp][sum] += dp[i - 1][sp - (a[i] + x)][sum];
                    if(dp[i][sp][sum] >= MOD)
                        dp[i][sp][sum] -= MOD;
                }
            }
    int ans = 0;
    for(int i = 0; i <= k; i++)
    {
        ans += dp[n][spa[n]][i];
        if(ans >= MOD)
            ans -= MOD;
    }
    cout << ans << "\n";
    return 0;
}

//thuanqvbn03
#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100005;
const int Mod = 1000000007;

int n, D;
string s;
long long dp[MaxN], tmp[MaxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cin >> D;
    n = s.size();
    for (int i = s[0] - '0' - 1; i >= 0; i--)
    {
        dp[i % D]++;
    }
    int Sums = (s[0] - '0') % D;
    for (int i = 1; i < n; i++)
    {
        int x = s[i] - '0';
        for (int k = 0; k < D; k++)
        {
            tmp[k] = tmp[k] + dp[k];
            tmp[k + 10] = tmp[k + 10] - dp[k] + Mod;
        }
        tmp[Sums]++;
        tmp[Sums + x]--;
        Sums = (Sums + x) % D;
        dp[0] = tmp[0];
        tmp[0] = 0;
        for (int k = 1; k < D + 10; k++)
        {
            dp[k] = (tmp[k] + dp[k - 1]) % Mod;
            tmp[k] = 0;
        }
        for (int k = D; k < D + 10; k++)
        {
            dp[k % D] = (dp[k % D] + dp[k]) % Mod;
        }
    }
    long long ans = (dp[0] + (Sums % D == 0) - 1 + Mod) % Mod;
    cout << ans;
    return 0;
}
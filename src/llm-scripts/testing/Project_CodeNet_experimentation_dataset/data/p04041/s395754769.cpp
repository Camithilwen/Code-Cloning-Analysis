#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mo 1000000007
int i,j,k,m,n,x,y,z,S,Ans,ans,dp[41][1<<17];
inline ll Pow(ll x,ll d) {
    ll ans = 1, y = x;
    for (; d; y = y * y % mo, d >>= 1)d & 1 ? ans = ans * y % mo : 0;
    return ans;
}
int main() {
    cin >> n >> x >> y >> z;
    S = (1 << x + y + z) - 1;
    ans = (1 << x - 1) | (1 << x + y - 1) | (1 << x + y + z - 1);
    dp[0][0] = 1;
    for (i = 1; i <= n; ++i)
        for (j = 0; j <= S; ++j)
            if (dp[i - 1][j])
                for (k = 1; k <= 10; ++k) {
                    int o = ((j << k) | (1 << k - 1)) & S;
                    if ((o & ans) == ans)(Ans += 1ll * dp[i - 1][j] * Pow(10, n - i) % mo) %= mo;
                    else (dp[i][o] += (dp[i - 1][j]) % mo) %= mo;
                }
    printf("%d\n", Ans);
}
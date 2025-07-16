#include <bits/stdc++.h>

#define name "vd"
#define ini freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define oo 1e9 + 7;
#define PII pair<int, int>
#define long long long
using namespace std;

const int NMAX = 1e4 + 5;
const int MOD = 1e9 + 7;
string s;
int d, n, nxt;
long dp[NMAX][2][105];

int main()
{
    //ini;
    fastio;
    cin >> s >> d;
    n = s.size();
    s = "0" + s;

    memset(dp, 0, sizeof dp);

    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int lss = 0; lss <= 1; lss++){
            for (int j = 0; j < d; j++){
                for (int dg = 0; dg <= 9; dg++){
                    if (!dp[i - 1][lss][j]) continue;
                    if (!lss && dg > (s[i] - '0')) continue;

                    if (!lss && dg == (s[i] - '0')) nxt = 0;
                    else nxt = 1;

                    dp[i][nxt][(j + dg) % d] += dp[i - 1][lss][j] % MOD;
                }
            }
        }
    }

    cout << ((dp[n][0][0] + dp[n][1][0] - 1) % MOD + MOD) % MOD;
    return 0;
}

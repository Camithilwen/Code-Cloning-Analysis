#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <cstring>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define INF 1e18

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

const ll MOD = 1e9 + 7;

ll fastPow(ll x, ll n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return fastPow(x * x % MOD, n / 2);
    else
        return x * fastPow(x, n - 1) % MOD;
}

ll fac[112345];
void combInit(int mx)
{
    fac[0] = 0;
    fac[1] = 1;
    for (int i = 2; i <= mx; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
}

ll modDiv(ll a, ll b)
{
    return a * fastPow(b, MOD - 2) % MOD;
}

int main()
{
    combInit(11234);

    ll perm[1010][1010];

    for (int i = 1; i <= 1000; i++)
    {
        perm[i][1] = i;
        for (int j = 2; j <= 1000; j++)
        {
            perm[i][j] = perm[i][j - 1] * (i - j + 1);
            perm[i][j] %= MOD;
        }
    }

    int n, a, b, c, d;

    cin >> n >> a >> b >> c >> d;

    ll dp[1010][1010];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = a; j <= b; j++)
        {
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;

            for (int k = c; k <= d; k++)
            {
                if (i - j * k < 0)
                    break;
                dp[i][j] += dp[i - j * k][j - 1] * modDiv(perm[n - i + j * k][j * k], fastPow(fac[j], k) * fac[k] % MOD);
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[n][b] << endl;

    return 0;
}
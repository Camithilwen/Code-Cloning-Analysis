#include "bits/stdc++.h"
#define ll long long
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<ll, ll> pairs;
typedef pair<ll, pairs> tpl;
ll c[4];
double dp[301][301][301];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, a;
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> a, c[a]++;
    dp[0][0][0] = 0;
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            for (ll k = 0; k <= n; k++)
            {
                double z = n - (i + j + k), val = 1;
                if (z == n)
                    continue;
                if (i + j + k > n)
                    continue;
                if (i > 0)
                    val += (1.0 * i / n) * dp[i - 1][j + 1][k];
                if (j > 0)
                    val += (1.0 * j / n) * dp[i][j - 1][k + 1];
                if (k > 0)
                    val += (1.0 * k / n) * dp[i][j][k - 1];
                if (z > 0)
                    val /= (1.0 - 1.0 * z / n);
                dp[i][j][k] = val;
            }
        }
    }

    cout << setprecision(9) << fixed << dp[c[3]][c[2]][c[1]];
}
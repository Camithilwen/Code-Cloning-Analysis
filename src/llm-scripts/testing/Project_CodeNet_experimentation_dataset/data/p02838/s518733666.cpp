#include <bits/stdc++.h>
using namespace std;

//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ll mul(ll x,ll y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

ll add(ll x,ll y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

ll sub(ll x,ll y)
{
    ll ret = ((x % MOD) - (y % MOD)) % MOD;
    if (ret < 0)
        ret += MOD;
    return ret;
}

ll modpow(ll x,ll y)
{
    if (!y) return 1;
    ll z = modpow(x,y / 2);
    z = mul(z,z);
    if (y & 1) z = mul(z,x);
    return z;
}

ll inv(ll x)
{
    return modpow(x,MOD - 2);
}

ll bagi(ll x,ll y)
{
    return mul(x,inv(y));
}

ll pref[65][300010];
ll tab[300010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for (ll i = 1 ; i <= n ; i++)
    {
        for (ll j = 0 ; j < 60 ; j++)
            pref[j][i] = pref[j][i - 1];
        ll ta;
        cin >> ta;
        for (ll j = 0 ; j < 60 ; j++) if (ta & (1ll << j))
        {
            pref[j][i]++;
        }
        tab[i] = ta;
    }
    ll ans = 0;
    for (ll i = 1 ; i <= n ; i++)
    {
        ll pengali = 1;
        ll rem = n - i;
        for (ll j = 0 ; j < 60 ; j++)
        {
            ll satu = pref[j][n] - pref[j][i];
            ll nol = rem - satu;
            // cout << j << ": " << satu << " " << nol << endl;
            if (tab[i] & (1ll << j))
                ans = add(ans,mul(nol,pengali));
            else
            {
                // cout << "yo\n";
                ans = add(ans,mul(satu,pengali));
            }
            pengali = mul(pengali,2ll);
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
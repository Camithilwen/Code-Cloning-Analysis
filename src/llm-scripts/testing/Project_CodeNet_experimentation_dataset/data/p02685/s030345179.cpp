#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 4e5 + 5;
const ll mod = 998244353;

ll fac[N], inv[N];

ll power(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

void init()
{
    fac[0] = inv[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fac[i] = i * fac[i - 1] % mod;
        inv[i] = power(fac[i], mod - 2);
    }
}

ll ncr(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    return fac[n] * inv[r] % mod * inv[n - r] % mod;
}
// https://betrue12.hateblo.jp/entry/2020/05/11/093054
signed main()
{
    init();

    ll n, m, k;
    cin >> n >> m >> k;

    ll ans = 0;
    for (ll i = 0; i <= k; i++)
    {
        ll curr = ncr(n - 1, i) * m % mod * power(m - 1, n - 1 - i) % mod;
        ans = (ans + curr) % mod;
    }
    cout << ans << endl;
    return 0;
}
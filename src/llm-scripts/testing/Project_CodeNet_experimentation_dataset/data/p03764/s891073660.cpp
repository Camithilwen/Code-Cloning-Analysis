#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5 + 5, mod = 1e9 + 7;

ll x[N], y[N], sumY;

int main()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll ans = 0, temp;
    for(ll i = 0 ; i < n ; i++) scanf("%lld", x + i);
    for(ll i = 0 ; i < m ; i++) scanf("%lld", y + i);
    for(ll i = 1 ; i < m ; i++)
    {
        sumY += (((i * (m - i)) % mod) * ((y[i] - y[i - 1]) % mod)) % mod;
        sumY %= mod;
    }
    for(ll i = 1 ; i < n ; i++)
    {
        temp = (((i * (n - i)) % mod) * ((x[i] - x[i - 1]) % mod)) % mod;
        ans += (temp * sumY) % mod;
        ans %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//---------------------------------------------------------------------------------------------------
ll MOD = 998244353;
ll f[101010], rf[101010];
ll inv(ll x) {
    ll res = 1;
    ll k = MOD - 2;
    ll y = x;
    while (k) {
        if (k & 1) res = (res * y) % MOD;
        y = (y * y) % MOD;
        k /= 2;
    }
    return res;
}
void init() {
    f[0] = 1;
    for(int i = 1; i < 101010; i++) f[i] = (f[i - 1] * i) % MOD;
    for(int i = 0; i < 101010; i++) rf[i] = inv(f[i]);
}
ll C(int n, int k) {
    if(n < k) return 0;
    ll a = f[n]; // = n!
    ll b = rf[n-k]; // = (n-k)!
    ll c = rf[k]; // = k!

    ll bc = (b * c) % MOD;

    return (a * bc) % MOD;
}
ll H(int k, int n)
{
    return C(n+k-1, k-1);
}
//---------------------------------------------------------------------------------------------------

int main()
{
    init();
    int k, n;
    cin >> k >> n;
    for(int i = 2; i <= 2 * k; i++)
    {
        ll ans = 0;
        int num;
        if(i <= k+1)
        {
            num = i/2;
        }
        else
        {
            num = (2*k-i+2)/2;
        }

        for(int j = 0; j <= num; j++)
        {
            ll tmp = 0;
            if(i % 2 != 0)
            {
                tmp = H(k, n-2*j) * C(num, j);
            }
            else
            {
                tmp = (H(k-1, n-2*j) * C(num-1, j) + H(k-1, n-2*j-1) * C(num-1, j)) % MOD;
            }
            if(j % 2 != 0)
            {
                ans = (ans - tmp + MOD) % MOD;
            }
            else
            {
                ans = (ans + tmp + MOD) % MOD;
            }
        }
        cout << ans << endl;
    }
}

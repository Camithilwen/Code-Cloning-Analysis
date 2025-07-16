#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll mod = 1e9+7;
int main()
{
    int n;
    cin>>n;
    vector<ll> a(n);
    ll s1 = 0, s2 = 0;
    for (int i=0; i<n; i++) {
        cin>>a[i];
        s1 += a[i];
        s2 += (a[i] * a[i]);
        s1 %= mod;
        s2 %= mod;
    }
    ll res = (s1 * s1 - s2);
    res %= mod;
    while (res < 0) res += mod;
    ll ans;
    if (res % 2) ans = (res + mod) / 2;
    else ans = res / 2;
    
    cout << ans << '\n';
}
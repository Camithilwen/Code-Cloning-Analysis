#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool check(ll x, ll pos) { return (x & (1LL << pos)); }

vector <ll> v;

ll gelim(ll X)
{
    ll ind = 0;
    for(ll i = 60; i >= 0; i--)
    {
        if((X >> i & 1) == 0)
        {
            ll x = ind;
            while(x < v.size() && !check(v[x], i)) x++;
            if(x == v.size()) continue;
            swap(v[ind], v[x]);
            for(ll j = 0; j < v.size(); j++)
            {
                if(j != ind && check(v[j], i)) v[j] ^= v[ind];
            }
            ind++;
        }
    }
    ll ans = 0;
    for(ll i = 0; i < v.size(); i++) ans ^= v[i];
    return ans;
}


int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,x;
    cin >> n;
    ll all = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> x;
        all ^= x;
        v.push_back(x);
    }
    sort(v.rbegin(), v.rend());
    ll ans = gelim(all);
    cout << ans + (ans ^ all);
}

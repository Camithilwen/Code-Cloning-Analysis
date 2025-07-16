#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pll = pair<ll, ll>;


int main(){
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for(auto& i : a) cin >> i;
    auto cost = [&](ll x, ll y){
        return a[x] + a[y] + abs(x - y) * d;
    };
    vector<ll> l(n), r(n);
    l[0] = 0;
    for(ll i = 1; i < n; i++) l[i] = min(l[i - 1], i, [&](ll x, ll y){ return cost(i, x) < cost(i, y); });
    r[n - 1] = n - 1;
    for(ll i = n - 1; i--; ) r[i] = min(r[i + 1], i, [&](ll x, ll y){ return cost(i, x) < cost(i, y); });
    ll ans = 0;
    pll last;
    for(ll i = 0; i < n - 1; i++) if(last != pll{l[i], r[i + 1]}){
        last = {l[i], r[i + 1]};
        ans += cost(l[i], r[i + 1]);
    }
    for(ll i = 1; i < n - 1; i++) if(l[i] != i && r[i] != i) ans += min(cost(i, l[i - 1]), cost(i, r[i + 1]));
    cout << ans << endl;
}

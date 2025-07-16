#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    ll n, m; cin >> n >> m;
    map<ll,ll> data;
    ll sum = 0; data[0]++;
    for(int i=0; i<n; i++){
        ll a; cin >> a;
        sum += a;
        sum %= m;
        data[sum]++;
    }
    ll ans = 0;
    for(auto x : data) ans += x.second*(x.second-1)/2;
    cout << ans << endl;
}
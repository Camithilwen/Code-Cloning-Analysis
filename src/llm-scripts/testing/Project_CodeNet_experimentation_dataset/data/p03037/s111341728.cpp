#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, m; cin >> n >> m;
    vector<ll> p(n, 0);
    ll xmin = 1, xmax = n;
    for(ll i=0; i<m; ++i){
        ll l, r; cin >> l >> r; 
        xmin = max(xmin, l);
        xmax = min(xmax, r);
    }
    ll res = max((ll)0, xmax-xmin+1);
    cout << res << endl;
    return 0;
}
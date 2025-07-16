#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ll l, r; cin >> l >> r;
    if(r - l >= 2019)
    {
        cout << '0' << endl;
        return 0;
    }
    ll ans = 2020;
    for(ll i = l; i <= r; i++)for(ll j = i+1; j <= r; j++){
        if(i * j % 2019 < ans) ans = i * j % 2019;
    }
    cout << ans << endl;
    return 0;
}

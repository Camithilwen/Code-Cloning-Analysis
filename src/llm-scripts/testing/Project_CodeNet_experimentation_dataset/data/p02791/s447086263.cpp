#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

int main() {
    ll n;
    cin >> n;
    int m, p;
    ll ans = 0;
    m = 1e6;
    rep(i, n) {
        cin >> p;
        if (m >= p) {
            ans++;
        }
        m = min(m, p);
    }
    cout << ans << endl;
    return 0;
}

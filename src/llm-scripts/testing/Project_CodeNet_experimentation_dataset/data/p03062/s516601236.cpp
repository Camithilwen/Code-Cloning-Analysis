#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    int n;
    cin >> n;
    int a;
    ll ans = 0;
    int m = 2e9;
    int cnt = 0;
    rep(i, n){
        cin >> a;
        if (a < 0) {
            cnt++;
            a *= -1;
        }
        m = min(m, a);
        ans += a;
    }
    if (cnt%2 == 1) {
        ans -= 2*m;
    }
    cout << ans << endl;
    return 0;
}

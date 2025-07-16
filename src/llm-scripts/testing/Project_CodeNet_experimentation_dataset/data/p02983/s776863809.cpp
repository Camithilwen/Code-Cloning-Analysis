#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int INF = 1001001001;

int main() {
    ll l, r;
    cin >> l >> r;
    r = min(l+2019, r);
    ll ans = INF;
    for (ll i = l; i <= r; i++) {
        for (ll j = i+1; j <= r; j++) {
            //i = i%2019;
            //j = j%2019;
            ans = min(ans, (i*j)%2019);
        }
    }
    cout << ans << endl;
    return 0;
}
//----------------------------------------------------------------------
#include <algorithm>
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    rep(i, n)
        cin >> a[i];
    rep(i, n)
        cin >> b[i];
    rep(i, n)
        cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());


    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        ll key = b[i];
        ll numc = c.end() - upper_bound(c.begin(), c.end(), key);
        ll numa = lower_bound(a.begin(), a.end(), key) - a.begin();
        ans += numa * numc;
    }
    cout << ans << endl;
    return 0;
}

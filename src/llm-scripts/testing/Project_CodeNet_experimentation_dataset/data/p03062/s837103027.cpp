#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int c = 0;
    rep(i,n) {
        if (a[i] < 0) c ^= 1;
    }
    ll ans = 0;
    rep(i,n) ans += abs(a[i]);
    if (c) {
        ll mn = 1e10;
        rep(i,n) {
            mn = min(mn, abs(a[i]));
        }
        ans -= mn*2;
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
int main() {
    ll N, m = LONG_LONG_MAX;
    cin >> N;
    rep(i, 5) {
        ll x;
        cin >> x;
        m = min(m, x);
    }
    ll ans = 4 + (ll)ceil(N * 1.0 / m);
    cout << ans << endl;
}
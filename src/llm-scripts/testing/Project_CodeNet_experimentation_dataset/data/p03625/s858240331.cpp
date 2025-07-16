#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    map<ll, int, greater<ll>> m;
    rep(i, n) {
        ll a;
        cin >> a;
        m[a]++;
    }

    int cnt = 0;
    ll ans = 0;
    for (auto e : m) {
        if (e.second >= 4 && cnt == 0) {
            ans = e.first * e.first;
            cnt += 2;
            break;
        } else if (e.second >= 2) {
            if (cnt == 0)
                ans = e.first, cnt++;
            else if (cnt == 1) {
                ans *= e.first, cnt++;
                break;
            }
        }
    }

    if (cnt == 1) ans = 0;
    cout << ans << endl;
    return 0;
}

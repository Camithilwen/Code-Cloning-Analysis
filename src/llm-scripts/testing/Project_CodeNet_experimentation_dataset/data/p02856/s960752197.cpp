#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    ll ans = 0, lst = 0, d, c;
    vector<ll> nxt = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    for (int i = 0; i < m; i++) {
        cin >> d >> c;
        while (c) {
            if (c % 2 == 1) {
                lst = 10 * lst + d;
                while (lst >= 10) {
                    lst = lst / 10 + lst % 10;
                    ans++;
                }
                c--;
            }
            c /= 2;
            if (d > 4) {
                ans += c * 2;
            } else {
                ans += c;
            }
            d = nxt[d];
        }
    }
    cout << ans << '\n';
    return 0;
}

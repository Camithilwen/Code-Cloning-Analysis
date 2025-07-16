#include <algorithm>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int n, m;
int p[1003];
void solve() {
    sort(p, p + n);
    reverse(p, p+n);
    int ans = 0;

    rep(i, n) ans += p[i];
    for (int i = 0; i + m - 1 < n; i += m) {
        ans -= p[i + m - 1];
    }
    cout << ans << endl;
}
int main() {
    while (cin >> n >> m) {
        rep(i, n) cin >> p[i];
        if (n == 0 && m == 0) break;
        solve();
    }
    return 0;
}
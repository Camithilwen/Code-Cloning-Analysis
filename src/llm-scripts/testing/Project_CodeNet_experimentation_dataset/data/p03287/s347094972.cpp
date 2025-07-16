#include <bits/stdc++.h>
using namespace std;

signed main () {
	int n, m, a;
    cin >> n >> m;
    map < int, int > pref;
    int cur = 0;
    ++pref[cur];
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        (cur += a) %= m;
        ans += pref[cur];
        ++pref[cur];
    }
    cout << ans << '\n';
}

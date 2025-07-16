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
    int n;
    cin >> n;
    vector<ll> a(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = a[i] + (i ? s[i - 1] : 0);
    }
    ll ans = 1e18;
    int j = 0, k = 2;
    for (int i = 1; i < n - 2; i++) {
        while (j + 1 < i && s[j] < s[i] - s[j]) {
            j++;
        }
        while (k + 1 < n - 1 && s[k] - s[i] < s[n - 1] - s[k]) {
            k++;
        }
        for (int u = j - 1; u <= j; u++) {
            for (int v = k - 1; v <= k; v++) {
                if (0 <= u && i < v) {
                    vector<ll> x = {s[u], s[i] - s[u], s[v] - s[i], s[n - 1] - s[v]};
                    sort(x.begin(), x.end());
                    ans = min(ans, x[3] - x[0]);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

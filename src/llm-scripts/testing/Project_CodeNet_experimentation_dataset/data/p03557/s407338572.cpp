#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        auto low = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        auto up = c.end() - upper_bound(c.begin(), c.end(), b[i]);
        ans += low * up;
    }
    cout << ans;
    return 0;
}

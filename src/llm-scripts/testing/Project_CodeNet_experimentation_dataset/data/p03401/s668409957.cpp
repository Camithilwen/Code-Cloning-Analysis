#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 2), d(n + 1), sd(n);
    rep(i, n) cin >> a[i + 1];

    int sum = 0;
    rep(i, n + 1) {
        d[i] = abs(a[i + 1] - a[i]);
        sum += d[i];
    }

    rep(i, n)
        sd[i] = abs(a[i + 2] - a[i]);

    rep(i, n) {
        cout << sum - d[i] - d[i + 1] + sd[i] << "\n";
    }

    return 0;
}
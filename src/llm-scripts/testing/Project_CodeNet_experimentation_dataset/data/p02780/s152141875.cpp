#include <bits/stdc++.h>
using namespace std;
using ll = long double;

int main() {
    double n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        arr[i] = (x + 1.0) / 2.0;
    }

    ll ans = 0;
    for (int i = 0; i < k; i++) ans += arr[i];
    ll temp = ans;

    for (int i = k; i < n; i++) {
        temp = temp + arr[i] - arr[i-k];
        ans = max(ans, temp);
    }

    printf("%0.7Lf\n", ans);
    return 0;
}

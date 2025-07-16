/**
 *    author:  FromDihPout
 *    created: 2020-06-21
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        long long diff = min(a[i] + a[i - 1] - x, a[i]);
        if (diff > 0) {
            a[i] -= diff;
            ans += diff;
        }
        diff = a[i] + a[i - 1] - x;
        if (diff > 0) {
            a[i - 1] -= diff;
            ans += diff;
        }
    }
    cout << ans << endl;
}
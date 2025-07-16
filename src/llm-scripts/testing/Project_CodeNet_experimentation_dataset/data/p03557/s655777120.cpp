#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
    for (auto &x: c) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    vector<long long> l(n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && c[j] <= b[i]) j++;
        l[i] = n - j;
    }
    for (int i = n - 1; i > 0; i--) l[i-1] += l[i];
    long long ans = 0;
    j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && b[j] <= a[i]) j++;
        if (j == n) break;
        ans += l[j];
    }
    cout << ans << endl;
    return 0;
}
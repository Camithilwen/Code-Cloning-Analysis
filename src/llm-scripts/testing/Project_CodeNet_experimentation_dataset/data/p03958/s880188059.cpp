#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, t;
    cin >> k >> t;
    int a[t];
    for (int i = 0; i < t; ++i) {
        cin >> a[i];
    }

    sort(a, a + t);

    cout << max(0, a[t - 1] - k + a[t - 1] - 1) << endl;

    return 0;
}
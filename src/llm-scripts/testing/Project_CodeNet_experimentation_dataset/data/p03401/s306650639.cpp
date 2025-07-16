#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 2];
    for (int i = 1; i < n + 1; i++) cin >> a[i];
    a[0] = 0, a[n + 1] = 0;

    ll s = 0;
    rep(i, n + 1) s += abs(a[i + 1] - a[i]);

    for (int i = 1; i < n + 1; i++) {
        cout << s + abs(a[i - 1] - a[i + 1]) -
                    abs(abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]))
             << endl;
    }
    return 0;
}

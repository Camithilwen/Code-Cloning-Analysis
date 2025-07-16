#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    int l;
    cin >> l;
    vector<vector<int>> dbl(21, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        int ni = upper_bound(begin(x), end(x), x[i] + l) - begin(x) - 1;
        dbl[0][i] = ni;
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < n; j++) {
            dbl[i + 1][j] = dbl[i][dbl[i][j]];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b, a--, b--;
        if (a > b) swap(a, b);
        int cur = a;
        int ans = 0;
        for (int i = 20; i >= 0; i--) {
            if (dbl[i][cur] >= b) continue;
            cur = dbl[i][cur];
            ans += 1 << i;
        }
        cout << ans + 1 << endl;
    }
}
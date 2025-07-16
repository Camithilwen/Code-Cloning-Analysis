#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int a[3][MAXN];
int f[2][MAXN];
void add(int p, int index) {
    for (;p < MAXN; p += p&-p)
        ++f[index][p];
}
int find(int p, int index) {
    int res = 0;
    for (;p; p -= p&-p)
        res += f[index][p];
    return res;
}
int32_t main () {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    vector <int> vctr;
    bool b[2] = {0, 0};
    for (int i = 0; i < n; ++i) {
        int mx = max(a[0][i], max(a[1][i], a[2][i]));
        int mn = min(a[0][i], min(a[1][i], a[2][i]));
        if (mx - mn > 2)
            return cout << "No", 0;
        if (mx % 3)
            return cout << "No", 0;
        if (2 * a[1][i] != a[0][i] + a[2][i])
            return cout << "No", 0;
        if ((mx - i) % 2 == 0)
            return cout << "No", 0;
        vctr.push_back(mx / 3);
        if (a[0][i] == mx)
            b[i & 1] = 1 - b[i & 1];
        // cout << (a[0][i] == mx) << ' ';
    }
    // cout << b[0] << ' ' << b[1];
    for (int i = n - 1; i >= 0; --i) {
        if (find(vctr[i], i & 1) & 1)
            b[(i + 1) & 1] = 1 - b[(i + 1) & 1];
        add(vctr[i], i & 1);
        // cout << vctr[i] << ' ';
    }
    if (b[0] || b[1])
        return cout << "No", 0;
    cout << "Yes";
    return 0;
}
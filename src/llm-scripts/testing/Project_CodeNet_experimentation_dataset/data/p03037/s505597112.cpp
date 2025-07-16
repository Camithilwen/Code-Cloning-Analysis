#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (size_t i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        v[l-1]++;
        v[r]--;
    }

    int ans = 0, num = 0;
    for (size_t i = 0; i < n; i++) {
        num += v[i];
        if (num == m) ans++;
    }

    cout << ans << endl;
    return 0;
}

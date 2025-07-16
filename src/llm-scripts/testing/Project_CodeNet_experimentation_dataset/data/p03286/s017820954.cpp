#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    string ans;
    while (n) {
        if (n % (-2) == 0)
            ans += '0';
        else 
            --n, ans += '1';
        n /= -2;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

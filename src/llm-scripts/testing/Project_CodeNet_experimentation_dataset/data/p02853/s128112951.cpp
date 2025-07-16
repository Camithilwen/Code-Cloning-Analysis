#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    int f = 300000;
    int s = 200000;
    int t = 100000;

    int ans = 0;

    if (x == 1) ans += f;
    else if (x == 2) ans += s;
    else if (x == 3) ans += t;

    if (y == 1) ans += f;
    else if (y == 2) ans += s;
    else if (y == 3) ans += t;

    if (x == 1 && y == 1) ans += 400000;

    cout << ans << '\n';
    return 0;
}
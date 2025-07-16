#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll x, y; cin >> x >> y;

    ll ans = LINF;
    if (x <= y) ans = min(ans, y - x);
    if (-x <= y) ans = min(ans, y + x + 1);
    if (x <= -y) ans = min(ans, -y - x + 1);
    if (-x <= -y) ans = min(ans, -y + x + 2);

    cout << ans << endl;
}
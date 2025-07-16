#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b != c) {
        cout << "Yes\n";
    } else if (b == c && a != b) {
        cout << "Yes\n";
    } else if (a == c && a != b) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
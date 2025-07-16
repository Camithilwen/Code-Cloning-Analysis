#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int n, m, x, y, t;

int main() {
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        x = max(x, t);
    }
    for (int i = 0; i < m; ++i) {
        cin >> t;
        y = min(y, t);
    }
    if (x < y)
        cout << "No War" << endl;
    else
        cout << "War" << endl;
    return 0;
}

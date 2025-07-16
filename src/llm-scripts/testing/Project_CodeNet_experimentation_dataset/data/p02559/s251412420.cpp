#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int n;
ll t[500005];

void inc(int x, ll v) {
    for (; x <= n; x += x & -x) t[x] += v;
}

ll que(int x) {
    ll z = 0;
    for (; x; x -= x & -x) z += t[x];
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    int q, o, u, v;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> u, inc(i, u);
    while (q--) {
        cin >> o >> u >> v;
        if (o == 0) inc(u + 1, v);
        else cout << que(v) - que(u) << '\n';
    }
}

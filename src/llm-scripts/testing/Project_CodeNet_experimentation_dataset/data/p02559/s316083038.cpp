#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct BIT {
    int n; vector<LL> bit;
    void init(int _n) { n = _n; bit.assign(n + 1, 0); }
    void m(int x, LL d) {
        while (x <= n)
            bit[x] += d, x += x & (-x);
    }
    LL q(int x) {
        LL ret = 0;
        while (x > 0)
            ret += bit[x], x -= x & (-x);
        return ret;
    }
} solver;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    solver.init(n);
    for (int i = 0 ; i < n ; i++) {
        LL v; cin >> v;
        solver.m(i + 1, v);
    }
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int x; LL v; cin >> x >> v;
            solver.m(x + 1, v);
        } else {
            int l, r; cin >> l >> r;
            cout << solver.q(r) - solver.q(l) << '\n';
        }
    }
}
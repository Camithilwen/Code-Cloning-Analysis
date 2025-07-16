#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template<typename OperatorMonoid>
struct SegmentTree {
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;
    const H h;
    const OperatorMonoid OM0;
    int sz, height;
    vector<OperatorMonoid> lazy;
    SegmentTree(int n, const H h, const OperatorMonoid &OM0)
        : h(h), OM0(OM0), sz(1), height(0)
    {
        while (sz < n) sz <<= 1, height++;
        lazy.assign(sz * 2, OM0);
    }
    inline void propagate(int k) {
        if (lazy[k] == OM0) return ;
        lazy[k << 1 | 0] = h(lazy[k << 1 | 0], lazy[k]);
        lazy[k << 1 | 1] = h(lazy[k << 1 | 1], lazy[k]);
        lazy[k] = OM0;
    }
    inline void thrust(int k) {
        for (int i = height; i > 0; i--) propagate(k >> i);
    }
    void update(int a, int b, const OperatorMonoid &x) {
        thrust(a += sz);
        thrust(b += sz - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = h(lazy[l], x), ++l;
            if (r & 1) --r, lazy[r] = h(lazy[r], x);
        }
    }
    void set(int k, const OperatorMonoid &x) { thrust(k += sz); lazy[k] = x; }
    OperatorMonoid get(int k) { thrust(k += sz); return lazy[k]; }
    OperatorMonoid operator[](const int &k) { return get(k); }
};

const int INF = numeric_limits<int>::max();
int main() {
    int n, q; cin >> n >> q;
    SegmentTree<int> seg(n, [](int a, int b) { return b; }, INF);
    while (q--) {
        int com; cin >> com;
        if (com == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            seg.update(s, t, x);
        } else {
            int i; cin >> i;
            cout << seg[i] << endl;
        }
    }
    return 0;
}

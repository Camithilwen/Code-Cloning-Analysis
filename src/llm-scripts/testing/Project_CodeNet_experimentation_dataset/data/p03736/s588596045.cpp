#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template<typename Monoid>
struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;
    const F f;
    const Monoid M1;
    int sz;
    vector<Monoid> dat;
    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1), sz(1) {
        while (sz < n) sz <<= 1;
        dat.assign(sz * 2, M1);
    }
    void set(int k, const Monoid &x) { dat[k + sz] = x; }
    void build() {
        for (int k = sz - 1; k > 0; k--) {
            dat[k] = f(dat[2 * k], dat[2 * k + 1]);
        }
    }
    void update(int k, const Monoid &x) {
        dat[k += sz] = x;
        while (k >>= 1) dat[k] = f(dat[2 * k], dat[2 * k + 1]);
    }
    Monoid get(int a, int b) {  // [a, b)
        Monoid L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = f(L, dat[a++]);
            if (b & 1) R = f(dat[--b], R);
        }
        return f(L, R);
    }
    Monoid operator[](const int &k) const { return dat[k + sz]; }
    friend ostream& operator<<(ostream& os, SegmentTree<Monoid> &seg) {
        for (int i = 0; i < seg.sz; i++) os << seg[i] << " ";
        return os;
    }
};

int main() {
    int n; cin >> n;
    int Q; cin >> Q;
    int a, b; cin >> a >> b; a--, b--;
    vector<int> x(Q + 1);
    x[0] = a;
    for (int q = 1; q <= Q; q++) cin >> x[q], x[q]--;
    const long long INF = 1LL << 60;    // 1.15x10^18
    using ll = long long;
    SegmentTree<ll> dpL(n, [](ll a, ll b) { return min(a, b); }, INF);
    SegmentTree<ll> dpR(n, [](ll a, ll b) { return min(a, b); }, INF);
    dpL.set(b, 0 - b); dpL.build();
    dpR.set(b, 0 + b); dpR.build();
    ll add = 0;
    for (int q = 1; q <= Q; q++) {
        int diff = abs(x[q] - x[q - 1]);
        add += diff;
        ll val = min(dpL.get(0, x[q]) + x[q], dpR.get(x[q], n) - x[q]);
        val -= diff;
        dpL.update(x[q - 1], val - x[q - 1]);
        dpR.update(x[q - 1], val + x[q - 1]);
    }
    ll mi = INF;
    for (int i = 0; i < n; i++) mi = min(mi, dpL[i] + i);
    cout << mi + add << endl;
    return 0;
}
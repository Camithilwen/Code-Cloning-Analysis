#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n, q;

struct segtree {
    static const llong inf = 1e18;
    llong offset, seg[1 << 19];
    
    segtree() : offset(0) {
        for (int i = 1 << 19; i--; ) seg[i] = inf;
    }

    void update(int i, int s, int e, int x, llong v) {
        if (s == e) {
            seg[i] = min(seg[i], v);
            return;
        }
        int m = (s + e) / 2;
        if (x <= m) update(i << 1, s, m, x, v);
        else update(i << 1 | 1, m + 1, e, x, v);
        seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
    }

    void update(int x, llong v) {
        update(1, 1, n, x, v - offset);
    }

    llong query(int i, int s, int e, int x, int y) const {
        if (e < x || y < s) return inf;
        if (x <= s && e <= y) return seg[i];
        int m = (s + e) / 2;
        return min(query(i << 1, s, m, x, y), query(i << 1 | 1, m + 1, e, x, y));
    }

    llong query(int x, int y) const {
        return offset + query(1, 1, n, x, y);
    }

    llong getans(int i, int s, int e) const {
        if (s == e) return seg[i] + s;
        int m = (s + e) / 2;
        return min(getans(i << 1, s, m), getans(i << 1 | 1, m + 1, e));
    }

    llong getans() const {
        return getans(1, 1, n) + offset;
    }
} AP, AN, BP, BN;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int A, B, x, p;
    cin >> n >> q >> A >> B >> x;
    AP.update(B, abs(A - x) + B);
    AN.update(B, abs(A - x) - B);
    BP.update(A, abs(B - x) + A);
    BN.update(A, abs(B - x) - A);
    while (--q) {
        p = x;
        cin >> x;
        llong AxBp = min({ BP.query(x, n) - x, BN.query(1, x) + x });
        llong ApBx = min({ AP.query(x, n) - x, AN.query(1, x) + x });
        llong d = abs(x - p);
        AP.offset += d; AN.offset += d; BP.offset += d; BN.offset += d;
        AP.update(p, AxBp + p);
        AN.update(p, AxBp - p);
        BP.update(p, ApBx + p);
        BN.update(p, ApBx - p);
    }
    printf("%lld\n", min(AN.getans(), BN.getans()));
}
#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
#define ls(_o) (_o << 1)
#define rs(_o) ((_o << 1) | 1)
#define abs(_o) ((_o < 0) ? -(_o) : _o)
using namespace std;
namespace ywy {
    inline int get() {
        int n = 0;
        char c;
        while ((c = getchar()) || 23333) {
            if (c >= '0' && c <= '9')
                break;
            if (c == '-')
                goto s;
        }
        n = c - '0';
        while ((c = getchar()) || 23333) {
            if (c >= '0' && c <= '9')
                n = n * 10 + c - '0';
            else
                return (n);
        }
    s:
        while ((c = getchar()) || 23333) {
            if (c >= '0' && c <= '9')
                n = n * 10 - c + '0';
            else
                return (n);
        }
    }
    ll min1[1000001], min2[1000001], adds[1000001];
    int x[200001];
    inline void down(int tree) {
        if (!adds[tree])
            return;
        ll c = adds[tree];
        adds[tree] = 0;
        adds[ls(tree)] += c;
        adds[rs(tree)] += c;
        min1[ls(tree)] += c;
        min2[ls(tree)] += c;
        min1[rs(tree)] += c;
        min2[rs(tree)] += c;
    }
    inline void up(int tree) {
        min1[tree] = min(min1[ls(tree)], min1[rs(tree)]);
        min2[tree] = min(min2[ls(tree)], min2[rs(tree)]);
    }
    void setpt(int l, int r, int tree, int pt, ll num) {
        if (l == r) {
            min1[tree] = min(min1[tree], num - l);
            min2[tree] = min(min2[tree], num + l);
            return;
        }
        int mid = (l + r) >> 1;
        down(tree);
        if (pt <= mid)
            setpt(l, mid, ls(tree), pt, num);
        else
            setpt(mid + 1, r, rs(tree), pt, num);
        up(tree);
    }
    ll query1(int rl, int rr, int l, int r, int tree) {
        if (rl == l && rr == r)
            return (min1[tree]);
        int mid = (l + r) >> 1;
        down(tree);
        if (rl > mid)
            return (query1(rl, rr, mid + 1, r, rs(tree)));
        if (rr <= mid)
            return (query1(rl, rr, l, mid, ls(tree)));
        return (min(query1(rl, mid, l, mid, ls(tree)), query1(mid + 1, rr, mid + 1, r, rs(tree))));
    }
    ll query2(int rl, int rr, int l, int r, int tree) {
        if (rl == l && rr == r)
            return (min2[tree]);
        int mid = (l + r) >> 1;
        down(tree);
        if (rl > mid)
            return (query2(rl, rr, mid + 1, r, rs(tree)));
        if (rr <= mid)
            return (query2(rl, rr, l, mid, ls(tree)));
        return (min(query2(rl, mid, l, mid, ls(tree)), query2(mid + 1, rr, mid + 1, r, rs(tree))));
    }
    ll query(int l, int r, int tree) {
        if (l == r)
            return (min1[tree] + l);
        int mid = (l + r) >> 1;
        down(tree);
        return (min(query(l, mid, ls(tree)), query(mid + 1, r, rs(tree))));
    }
    void ywymain() {
        int n = get(), q = get(), a = get(), b = get();
        x[0] = a;
        memset(min1, 0x3f, sizeof(min1));
        memset(min2, 0x3f, sizeof(min2));
        setpt(1, n, 1, b, 0);
        for (register int i = 1; i <= q; i++) {
            x[i] = get();
            ll cjr = min(query1(1, x[i], 1, n, 1) + x[i], query2(x[i], n, 1, n, 1) - x[i]);
            adds[1] += abs(x[i] - x[i - 1]);
            min1[1] += abs(x[i] - x[i - 1]);
            min2[1] += abs(x[i] - x[i - 1]);
            setpt(1, n, 1, x[i - 1], cjr);
        }
        cout << query(1, n, 1) << endl;
    }
}
int main() {
    ywy::ywymain();
    return (0);
}
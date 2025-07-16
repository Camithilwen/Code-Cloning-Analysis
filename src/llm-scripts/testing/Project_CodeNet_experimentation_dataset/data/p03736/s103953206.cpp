// Crt. 2019-12-11  21:17:53
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 200005
using namespace std;
typedef long long ll;
const ll INF = 1e15;

struct Segt {
#define ls (p << 1)
#define rs (p << 1 | 1)
    ll sum[N << 2], tag[N << 2];
    Segt() {
        memset(sum, 0, sizeof sum);
        memset(tag, 0, sizeof tag);
    }
    inline void add(int p, ll w) { 
        sum[p] += w, tag[p] += w;
    }
    inline void pushdown(int p) {
        if (!tag[p]) return ;
        add(ls, tag[p]);
        add(rs, tag[p]);
        tag[p] = 0;
    }
    void Modify(int l, int r, int L, int R, ll w, int p) {
        if (L <= l && r <= R) return add(p, w);
        int mid = (l + r) >> 1;
        pushdown(p);
        if (L <= mid) Modify(l, mid, L, R, w, ls);
        if (mid < R) Modify(mid + 1, r, L, R, w, rs);
        sum[p] = min(sum[ls], sum[rs]);
    }
    ll Query(int l, int r, int L, int R, int p) {
        if (L <= l && r <= R) return sum[p];
        int mid = (l + r) >> 1; ll res = 0x3f3f3f3f3f3f3f3fll;
        pushdown(p);
        if (L <= mid) res = Query(l, mid, L, R, ls);
        if (mid < R) res = min(res, Query(mid + 1, r, L, R, rs));
        return res;
    }
#undef ls
#undef rs
} x, y, z; // y + z -

inline int Abs(int t) {
    return t < 0 ? -t : t;
}

int n, q, a, b, pos[N];

int main() {
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n >> q >> a >> b;

    for (int i = 1; i <= q; ++i)
        scanf("%d", pos + i);

    x.Modify(1, n, 1, n, INF, 1);
    y.Modify(1, n, 1, n, INF, 1);
    z.Modify(1, n, 1, n, INF, 1);
    
    x.Modify(1, n, a, a, -INF, 1);
    y.Modify(1, n, a, a, -INF + a, 1);
    z.Modify(1, n, a, a, -INF - a, 1);

    pos[0] = b;
    for (int i = 1; i <= q; ++i) {
        ll tmp = min(y.Query(1, n, pos[i], n, 1) - pos[i], z.Query(1, n, 1, pos[i], 1) + pos[i]);
        x.Modify(1, n, 1, n, Abs(pos[i] - pos[i - 1]), 1);
        y.Modify(1, n, 1, n, Abs(pos[i] - pos[i - 1]), 1);
        z.Modify(1, n, 1, n, Abs(pos[i] - pos[i - 1]), 1);
        ll tmp2 = x.Query(1, n, pos[i - 1], pos[i - 1], 1);
        //cout << tmp << " " << tmp2 << " #\n";
        if (tmp < tmp2) x.Modify(1, n, pos[i - 1], pos[i - 1], tmp - tmp2, 1), tmp2 = tmp;
        //cout << x.Query(1, n, pos[i - 1], pos[i - 1], 1) << endl;
        y.Modify(1, n, pos[i - 1], pos[i - 1], tmp2 + pos[i - 1] - y.Query(1, n, pos[i - 1], pos[i - 1], 1), 1);
        z.Modify(1, n, pos[i - 1], pos[i - 1], tmp2 - pos[i - 1] - z.Query(1, n, pos[i - 1], pos[i - 1], 1), 1);
    }
    
    cout << x.Query(1, n, 1, n, 1) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
const int MAX_NODE_CNT = MAXN << 6;

int n, m, lst[MAXN];

struct Persistent_Segment_Tree {
    #define mid ((l + r) >> 1)
    #define ls(_) t[_].ls
    #define rs(_) t[_].rs
    #define lq(_) t[_].ls, l, mid
    #define rq(_) t[_].rs, mid + 1, r
    int node_cnt, rt[MAXN];
    int& operator [](const int& x) { return rt[x]; }
    struct node { int ls, rs, data; } t[MAX_NODE_CNT]; 
    int build(int l, int r) {
        int cur = ++node_cnt;
        if (l == r) return cur;
        ls(cur) = build(l, mid), rs(cur) = build(mid + 1, r);
        return cur;
    }
    int modify(int pre, int l, int r, int pos, int val) {
        int cur = ++node_cnt; t[cur] = t[pre], t[cur].data += val;
        if (l == r) { return cur; }
        if (pos <= mid) ls(cur) = modify(ls(pre), l, mid, pos, val);
        else rs(cur) = modify(rs(pre), mid + 1, r, pos, val);
        return cur;
    }
    int query(int cur, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return t[cur].data;
        int ret = 0;
        if (ql <= mid) ret += query(lq(cur), ql, qr);
        if (qr > mid) ret += query(rq(cur), ql, qr);
        return ret; 
    } 
} t;

int main() {
    scanf("%d %d", &n, &m);
    t[0] = t.build(1, n);
    for (int i = 1, x; i <= n; ++i) {
        scanf("%d", &x); t[i] = t.modify(t[i - 1], 1, n, i, 1);
        if (lst[x]) t[i] = t.modify(t[i], 1, n, lst[x], -1);
        lst[x] = i;
    }
    int pre_ans = 0;
    for (int i = 1, u, v; i <= m; ++i) {
        scanf("%d %d", &u, &v);
        printf("%d\n", (t.query(t[v], 1, n, u, v)));
    }
    return 0;
}
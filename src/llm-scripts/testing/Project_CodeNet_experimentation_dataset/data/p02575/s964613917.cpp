#include <bits/stdc++.h>
#define lid id << 1
#define rid id << 1 | 1

using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 1e9;

int h, w, a[MAXN], L[MAXN], R[MAXN], ans[MAXN];

template <class T>
void read(T &x, T f = 1, char ch = getchar()) {
    x = 0;
    while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : 1), ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    x *= f;
}

// a[i] = a[i-1]  i∉[L,R]
// a[i] = a[L-1] -L + 1 + i  i∈[L,R];

struct Node {
    int l, r, mi, lval;
    bool tag;
    Node() { mi = lval = 0, tag = 0; }
    // mi denotes the minimum a in [l,r]
    // lval denotes the value of the left end point of [l,r]
} tr[MAXN * 4];

void update(int id) {
    tr[id].mi = min(tr[lid].mi, tr[rid].mi);
    tr[id].lval = tr[lid].lval;
}

void pushdown(int id) {
    if (tr[id].tag) {
        tr[lid].tag = 1;
        tr[lid].lval = tr[lid].mi = tr[id].lval;
        tr[rid].tag = 1;
        tr[rid].lval = tr[rid].mi = tr[id].lval + tr[rid].l - tr[lid].l;
        tr[id].tag = 0;
    }
}

void build(int id, int l, int r) {
    tr[id].l = l, tr[id].r = r;
    if (l == r) return;
    int mid = l + r >> 1;
    build(lid, l, mid);
    build(rid, mid + 1, r);
}

void modify(int id, int l, int r, int val) {
    if (tr[id].l == l && tr[id].r == r) {
        tr[id].mi = tr[id].lval = val;
        tr[id].tag = 1;
        return;
    }
    pushdown(id);
    int mid = tr[id].l + tr[id].r >> 1;
    if (r <= mid)
        modify(lid, l, r, val);
    else if (l > mid)
        modify(rid, l, r, val);
    else {
        modify(lid, l, mid, val);
        modify(rid, mid + 1, r, val + mid + 1 - l);
    }
    update(id);
}

int query(int id, int l, int r) {
    if (r < 1) return INF;
    if (tr[id].l == l && tr[id].r == r) {
        return tr[id].mi;
    }
    pushdown(id);
    int mid = tr[id].l + tr[id].r >> 1;
    if (r <= mid)
        return query(lid, l, r);
    else if (l > mid)
        return query(rid, l, r);
    else
        return min(query(lid, l, mid), query(rid, mid + 1, r));
}

int main() {
    read(h), read(w);
    for (int i = 1; i <= h; i++) read(L[i]), read(R[i]);
    fill(ans + 1, ans + h + 2, -1);
    build(1, 1, w);
    for (int i = 2; i <= h + 1; i++) {
        int tmp = query(1, L[i - 1] - 1, L[i - 1] - 1);
        modify(1, L[i - 1], R[i - 1], tmp + 1);
        int mi = query(1, 1, w);
        if (mi >= INF) break;
        ans[i] = mi + i - 1;
    }
    for (int i = 2; i <= h + 1; i++) printf("%d\n", ans[i]);
    return 0;
}
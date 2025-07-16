#include <cstdio>
#include <cstring>
#define maxn 200010
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
inline long long min(long long a, long long b) {return a < b ? a : b;}
inline long long abs(long long a) {return a > 0 ? a : -a;}
int n, k, x, y;
int q, last;
long long V[maxn << 2][3], cov[maxn << 2];
void pushdown(int rt) {
    int lc = rt << 1, rc = rt << 1 | 1;
    long long &tmp = cov[rt];
    V[lc][0] += tmp;
    V[lc][1] += tmp;
    V[lc][2] += tmp;
    cov[lc] += tmp;
    V[rc][0] += tmp;
    V[rc][1] += tmp;
    V[rc][2] += tmp;
    cov[rc] += tmp;
    tmp = 0;
}
void update(int rt) {
    int lc = rt << 1, rc = rt << 1 | 1;
    V[rt][0] = min(V[lc][0], V[rc][0]);
    V[rt][1] = min(V[lc][1], V[rc][1]);
    V[rt][2] = min(V[lc][2], V[rc][2]);
}
void add(int rt, int l, int r, int p, long long num) {
    if (l == r) {
        V[rt][0] = num;
        V[rt][1] = num + l;
        V[rt][2] = num - l;
        return ;
    }
    if (cov[rt]) pushdown(rt);
    int mid = l + r >> 1;
    if (p <= mid) add(rt << 1, l, mid, p, num);
    else add(rt << 1 | 1, mid + 1, r, p, num);
    update(rt);
}
void add(long long num, int rt = 1) {
    V[rt][0] += num;
    V[rt][1] += num;
    V[rt][2] += num;
    cov[rt] += num;
}
long long ask(int rt, int l, int r, int L, int R, int op) {
    if (L <= l && R >= r) return V[rt][op];
    pushdown(rt);
    int mid = l + r >> 1;
    long long ans = inf;
    if (L <= mid) ans = ask(rt << 1, l, mid, L, R, op);
    if (R > mid) ans = min(ans, ask(rt << 1 | 1, mid + 1, r, L, R, op));
    return ans;
}
int main() {
    scanf("%d%d%d%d", &n, &k, &x, &y);
    scanf("%d", &q);
    memset(V, 0x3f, sizeof V);
    add(1, 1, n, x, abs(y - q));
    add(1, 1, n, y, abs(x - q));
    while (--k) {
        last = q; scanf("%d", &q);
        long long t0 = ask(1, 1, n, last, last, 0) + abs(q - last);
        long long t1 = ask(1, 1, n, q, n, 1) - q;
        long long t2 = ask(1, 1, n, 1, q, 2) + q;
        long long ans = min(t0, min(t1, t2));
        add(abs(q - last));
        add(1, 1, n, last, ans);
    }
    printf("%lld\n", V[1][0]);
    return 0;
}
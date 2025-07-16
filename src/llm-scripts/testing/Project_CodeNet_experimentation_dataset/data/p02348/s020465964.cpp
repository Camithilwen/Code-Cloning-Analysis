#include<cstdio>
#include<algorithm>
#define N 100000
#define MAX (1<<31)-1
using namespace std;
int A[N], T[4*N], lazy[4*N];

void build(int l, int r, int k) {
    if (l == r) {
        T[k] = A[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, k * 2);
    build(mid + 1, r, k * 2 + 1);
    T[k] = min(T[2 * k], T[2 * k + 1]);
}
void pushdown(int k) {
    if (lazy[k] != -1) {
        lazy[2*k] = lazy[k];
        lazy[2*k+1] = lazy[k];
        T[2*k] =  lazy[k];
        T[2*k+1] = lazy[k];
        lazy[k] = -1;
    }
}
void updata(int L, int R, int data ,int l, int r ,int k) {
    if (L <= l && r <= R) {
        T[k] = data;
        lazy[k] = data;
        return;
    }
    pushdown(k);
    int mid = (l + r) / 2;
    if (mid >= L) updata(L, R, data, l, mid, 2*k);
    if (mid < R) updata(L, R, data, mid+1, r, 2*k+1);
    T[k] = min(T[2 * k], T[2 * k + 1]);
}
int find(int L, int R, int l, int r, int k) {
    if (L <= l && r <= R) return T[k];
    pushdown(k);
    int mid = (l + r) / 2;
    int ans = MAX;
    if (mid >= L) ans = min(ans, find(L, R, l, mid, k * 2));
    if (mid < R) ans = min(ans, find(L, R, mid + 1, r, k * 2 + 1));
    return ans;
}
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        A[i] = MAX;
    for (int i = 0; i < 4*n; i++)
        lazy[i] = -1;
    build(0, n - 1, 1);
    int com, s, t, x, y;
    while (q--) {
        scanf("%d", &com);
        if (com == 0) {
            scanf("%d%d%d", &s, &t, &x);
            updata(s, t, x, 0, n - 1, 1);
        }
        else {
            scanf("%d", &x);
            printf("%d\n", find(x, x, 0, n - 1, 1));
        }
    }
    return 0;
}

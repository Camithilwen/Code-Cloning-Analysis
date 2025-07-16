#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 200005
#define eps 1e-10
//#define ivorysi
using namespace std;
typedef long long int64;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        res = res * 10 + c - '0';
        c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
        out(x / 10);
    }
    putchar('0' + x % 10);
}
int N;int64 D;
int64 A[MAXN];
struct seg_tr {
    struct node {
        int L,R;
        int64 cov;
        pair<int64,int> val[2];
    }tr[MAXN * 4];
    void update(int u) {
        tr[u].val[1] = mp(1e16,0);
        if(tr[u].L != tr[u].R) {
            tr[u].val[0] = min(tr[u << 1].val[0],tr[u << 1 | 1].val[0]);
            tr[u].val[1] = min(tr[u << 1].val[1],tr[u << 1 | 1].val[1]);
        }
        tr[u].val[1] = min(tr[u].val[1],mp(tr[u].cov + tr[u].val[0].fi,tr[u].val[0].se));
    }
    void build(int u,int l,int r,int on) {
        tr[u].L = l;tr[u].R = r;tr[u].cov = 1e16;
        if(l == r) {
            tr[u].val[0] = mp(A[l] + on * l * D,l);
            update(u);
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1,l,mid,on);build(u << 1 | 1,mid + 1,r,on);
        update(u);
    }
    void Change(int u,int l,int r,int64 v) {
        if(l > r) return;
        if(tr[u].L == l && tr[u].R == r) {
            tr[u].cov = min(tr[u].cov,v);
            update(u);
            return;
        }
        int mid = (tr[u].L + tr[u].R) >> 1;
        if(r <= mid) Change(u << 1,l,r,v);
        else if(l > mid) Change(u << 1 | 1,l,r,v);
        else {Change(u << 1,l,mid,v);Change(u << 1 | 1,mid + 1,r,v);}
        update(u);
    }
    void Change_pos(int u,int p) {
        if(tr[u].L == tr[u].R) {
            tr[u].val[0] = mp(1e16,tr[u].L);
            update(u);return;
        }
        int mid = (tr[u].L + tr[u].R) >> 1;
        if(p <= mid) Change_pos(u << 1,p);
        else Change_pos(u << 1 | 1,p);
        update(u);
    }
}s[2];


void Solve() {
    read(N);read(D);
    for(int i = 1 ; i <= N ; ++i) read(A[i]);
    s[0].build(1,1,N,1);
    s[1].build(1,1,N,-1);
    s[0].Change_pos(1,1);s[1].Change_pos(1,1);
    s[0].Change(1,2,N,A[1] - D);
    int cnt = N - 1;
    int64 ans = 0;
    while(cnt--) {
        pair<int64,int> t[2];
        t[0] = s[0].tr[1].val[1],t[1] = s[1].tr[1].val[1];
        if(t[0] > t[1]) swap(t[0],t[1]);
        ans += t[0].fi;
        int u = t[0].se;
        s[0].Change_pos(1,u);s[1].Change_pos(1,u);
        s[1].Change(1,1,u - 1,1LL * u * D + A[u]);
        s[0].Change(1,u + 1,N,-1LL * u * D + A[u]);
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}
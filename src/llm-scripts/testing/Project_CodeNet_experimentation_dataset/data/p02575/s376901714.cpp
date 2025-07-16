#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void readin(T &x) {
    x = 0;
    T fh = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    x *= fh;
}
inline void d_read(double &x) {
    x = 0.0;
    int fh = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
    for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
    if (ch == '.') {
        double num = 1.0;
        ch = getchar();
        for (; isdigit(ch); ch = getchar()) x = x + (num /= 10) * (ch ^ 48);
    }
    x *= fh;
}
template <typename T>
inline void wt(T x) {
    if (x > 9) wt(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void writeln(T x, char c) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    wt(x);
    putchar(c);
}
const int N = 2e5 + 5;
int a[N << 2], t[N << 2], tg[N << 2];
inline void up(int p) {
    a[p] = min(a[p << 1], a[p << 1 | 1]);
    t[p] = min(t[p << 1], t[p << 1 | 1]);
}
inline void work(int p, int l, int r, int k) {
    a[p] = k;
    t[p] = k + l;
    tg[p] = k;
}
inline void build(int p, int l, int r) {
    tg[p] = -1e9;
    if (l == r) {
        a[p] = -l;
        t[p] = a[p] + l;
    }
    else {
        int mid = l + r >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        up(p);
    }
}
inline void down(int p, int l, int r) {
    if (tg[p] != -1e9) {
        int mid = l + r >> 1;
        a[p << 1] = a[p << 1 | 1] = tg[p];
        tg[p << 1] = tg[p << 1 | 1] = tg[p];
        t[p << 1] = tg[p] + l;
        t[p << 1 | 1] = tg[p] + mid + 1;
        tg[p] = -1e9;
    }
}
int sum;
inline void ask(int p, int l, int r, int pos) {
    if (l == pos && pos == r) {
        sum = a[p];
    }
    else {
        down(p, l, r);
        int mid = l + r >> 1;
        if (pos <= mid) ask(p << 1, l, mid, pos);
        else ask(p << 1 | 1, mid + 1, r, pos);
    }
}
inline void modify(int p, int l, int r, int ql, int qr, int k) {
    if (l >= ql && r <= qr) {
        a[p] = k;
        t[p] = a[p] + l;
        tg[p] = k;
    }
    else {
        down(p, l, r);
        int mid = l + r >> 1;
        if (ql <= mid) modify(p << 1, l, mid, ql, qr, k);
        if (mid < qr) modify(p << 1 | 1, mid + 1, r, ql, qr, k);
        up(p);
    }
}
int n, m;
int main() {
    readin(n); readin(m);
    int x, y;
    build(1, 1, m);
    for (int i = 1; i <= n; i ++) {
        readin(x); readin(y);
        sum = 1e8;
        if (x > 1) ask(1, 1, m, x - 1);
        modify(1, 1, m, x, y, sum);
        if (t[1] + i >= 1e8) puts("-1");
        else writeln(t[1] + i, '\n');     
    }
    return 0;
}
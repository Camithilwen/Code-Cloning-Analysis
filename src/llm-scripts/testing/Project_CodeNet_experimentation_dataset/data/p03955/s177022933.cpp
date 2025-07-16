#include <bits/stdc++.h>

#define MAXN 100005
#define lowbit(x) x & -x

using namespace std;

int n, N;
int a[MAXN][4], b[MAXN], c[MAXN], t[2][MAXN * 3], sum[2];

int read() {
    char c = getchar();
    int x = 0;
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c)) {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x;
}

void add(int c, int x, int v) {
    while (x <= N) {
        t[c][x] += v;
        x += lowbit(x);
    }
}

int query(int c,int x) {
    int res = 0;
    while (x) {
        res += t[c][x];
        x -= lowbit(x);
    }
    return res;
}

int main() {
    n = read();
    N = n * 3;
    for (int j = 1; j <= 3; ++j)
        for (int i = 1; i <= n; ++i)
            a[i][j] = read();
    for (int i = 1; i <= n; ++i) {
        if (a[i][1] > a[i][2]) {
            sum[i & 1] ^= 1;
            swap(a[i][1], a[i][3]);
        }
        b[i] = a[i][3];
        if (a[i][1] != a[i][2] - 1 || a[i][2] != a[i][3] - 1 || b[i] % 3 != 0 || ((b[i] / 3) & 1) != (i & 1)) {
            puts("No");
            return 0;
        }
    }
    for (int i = n; i >= 1; --i) {
        sum[(i & 1) ^ 1] ^= query(i & 1, b[i] / 3) & 1;
        add(i & 1, b[i] / 3, 1);
    }
    if ((sum[0] & 1) || (sum[1] & 1))
        puts("No");
    else
        puts("Yes");
}

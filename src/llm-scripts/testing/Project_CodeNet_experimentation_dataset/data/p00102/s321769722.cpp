#include <cstdio>
#include <cstring>
#define rep(i, n) for(i=0;i<(n);++i)
int a[11][11], n, i, j, t;
int main()
{
    while (scanf("%d", &n), n) {
        memset(a, 0, sizeof(a));
        rep(i, n) rep(j, n) {
            scanf("%d", &t); a[i][j] = t; a[n][j] += t; a[i][n] += t;
        }
        rep(i, n) a[n][n] += a[i][n];
        rep(i, n+1) {
            rep(j, n+1) printf("%5d", a[i][j]);
            puts("");
        }
    }
    return 0;
}
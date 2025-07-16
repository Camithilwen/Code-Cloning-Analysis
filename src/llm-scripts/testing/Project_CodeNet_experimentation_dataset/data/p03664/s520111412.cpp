#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 16;
int n, m, tot, sz, dp[N][1 << N], e[N][N], val[1 << N];  // val: 预处理每个联通块所有边的总值

void pre() {
    rep(s, 0, sz)
        rep(i, 1, n) if ((s >> (i - 1)) & 1)
            rep(j, i + 1, n) if ((s >> (j - 1)) & 1)
                val[s] += e[i][j];
}

void chkmax(int &x, int y) { x = max(x, y); }

int main() {
    cin >> n >> m;
    sz = (1 << n) - 1;
    rep(i, 1, m) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x][y] = e[y][x] = z; tot += z;
    }
    pre();
    
    memset(dp, -1, sizeof(dp));
    dp[1][1] = 0;
    rep(s, 1, sz)
        rep(i, 1, n)
            if (((s >> (i - 1)) & 1) && dp[i][s] != -1) {
                rep(j, 1, n)
                    if (!((s >> (j - 1)) & 1) && e[i][j])
                        chkmax(dp[j][s | (1 << (j - 1))], dp[i][s] + e[i][j]);  // e[i][j] 作为桥边
                int S = (sz ^ s) | (1 << (i - 1));
                for (int j = S; j; j = (j - 1) & S)
                    if (j & (1 << (i - 1)))
                        chkmax(dp[i][s | j], dp[i][s] + val[j]);
            }
    printf("%d\n", tot - dp[n][sz]);
    return 0;
}

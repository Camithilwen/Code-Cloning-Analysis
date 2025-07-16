#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 105;
const int mod = 1e9 + 7;
short dp[maxn][maxn][maxn][maxn];
short row[maxn][maxn], col[maxn][maxn];
char mp[maxn][maxn];
short max(short a, short b) {
    return a>b? a : b;
}
int main()
{
    int n, m, ex, ey;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%s", mp[i]+1);
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
            if (mp[i][j] == 'E'){
                ex = i, ey = j;
                break;
            }
    }
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
            row[i][j] = row[i][j-1] + (mp[i][j] == 'o');
            col[i][j] = col[i-1][j] + (mp[i][j] == 'o');
    }
    int L = ey - 1, R = m - ey, U = ex - 1, D = n - ex;
    memset(dp, -1, sizeof dp);
    dp[0][0][0][0] = 0;
    short ans = 0;
    for (int l=0; l<=L; l++){
        for (int u=0; u<=U; u++){
            for (int r=0; r<=R; r++){
                for (int d=0; d<=D; d++) if(dp[l][u][r][d] != -1){
                    int up = max(ex - u, d + 1), down = min(ex + d, n - u);
                    int left = max(ey - l, r + 1), right = min(ey + r, m - l);
                    if (up > down || left > right) continue;
                    ans = max(ans, dp[l][u][r][d]);
                    short add;
                    //printf("\n=========%d %d %d %d -> %d %d %d %d=========\n",l,u,r,d,left,up,right,down);
                    if (l+r < L){
                        add = col[down][ey-l-1] - col[up-1][ey-l-1];
                        //printf("l: %d ",add);
                        dp[l+1][u][r][d] = max(dp[l+1][u][r][d], dp[l][u][r][d] + add);
                    }
                    if(u+d < U){
                        add = row[ex-u-1][right] - row[ex-u-1][left-1];
                        //printf("u: %d ",add);
                        dp[l][u+1][r][d] = max(dp[l][u+1][r][d], dp[l][u][r][d] + add);
                    }
                    if(l+r < R){
                        add = col[down][ey+r+1] - col[up-1][ey+r+1];
                        //printf("r: %d ",add);
                        dp[l][u][r+1][d] = max(dp[l][u][r+1][d], dp[l][u][r][d] + add);
                    }
                    if(u+d < D){
                        add = row[ex+d+1][right] - row[ex+d+1][left-1];
                        //printf("d: %d ",add);
                        dp[l][u][r][d+1] = max(dp[l][u][r][d + 1], dp[l][u][r][d] + add);
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
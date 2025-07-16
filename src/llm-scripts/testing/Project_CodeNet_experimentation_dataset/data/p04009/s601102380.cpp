#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxc = 105, inf = 1e9;

int Y, X, s[maxc][maxc], ey, ex, dp[maxc][maxc][maxc][maxc], ans;
char g[maxc][maxc];
int bly, blx, bsy, bsx;

int sum(int ly, int lx, int sy, int sx) {
    if (bly < ly) ly = bly;
    if (blx < lx) lx = blx;
    if (bsy > sy) sy = bsy;
    if (bsx > sx) sx = bsx;
    return std::max(0, s[ly+1][lx+1] - s[ly+1][sx] - s[sy][lx+1] + s[sy][sx]);
}

int main() {
    scanf("%d%d", &Y, &X);
    for (int y = 0; y < Y; y++) scanf(" %s", g[y]);
    for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) {
        if (g[y][x] == 'E') { ey = y; ex = x; }
        s[y+1][x+1] = s[y+1][x] + s[y][x+1] - s[y][x];
        if (g[y][x] == 'o') s[y+1][x+1]++;
    }
    int W = ex+1, E = X-ex;
    int N = ey+1, S = Y-ey;
    for (int w = 0; w < W; w++) for (int e = 0; e < E; e++) for (int n = 0; n < N; n++) for (int s = 0; s < S; s++) {
        dp[w][e][n][s] = -inf;
    }
    dp[0][0][0][0] = 0;
    for (int w = 0; w < W; w++) for (int e = 0; e < E; e++) for (int n = 0; n < N; n++) for (int s = 0; s < S; s++) {
        domax(ans, dp[w][e][n][s]);
        //if (ans == 5) {
        //    printf("%d %d %d %d\n", w, e, n, s);
        //    return 0;
        //}
        domax(dp[w+1][e][n][s], dp[w][e][n][s]);
        domax(dp[w][e+1][n][s], dp[w][e][n][s]);
        domax(dp[w][e][n+1][s], dp[w][e][n][s]);
        domax(dp[w][e][n][s+1], dp[w][e][n][s]);
        bsx = e; blx = X-1-w;
        bsy = s; bly = Y-1-n;
        if (e <= ex-(w+1))         domax(dp[w+1][e][n][s], dp[w][e][n][s] + sum(ey+s, ex-(w+1), ey-n, ex-(w+1)));
        if (w <= X-1 - (ex+(e+1))) domax(dp[w][e+1][n][s], dp[w][e][n][s] + sum(ey+s, ex+(e+1), ey-n, ex+(e+1)));
        if (s <= ey-(n+1))         domax(dp[w][e][n+1][s], dp[w][e][n][s] + sum(ey-(n+1), ex+e, ey-(n+1), ex-w));
        if (n <= Y-1 - (ey+(s+1))) domax(dp[w][e][n][s+1], dp[w][e][n][s] + sum(ey+(s+1), ex+e, ey+(s+1), ex-w));
        //if (dp[0][0][0][1] == 3) {
        //    printf("wtf %d %d %d %d\n", w, e, n, s);
        //    return 0;
        //}
        //if (dp[0][1][0][1] == 5) {
        //    printf("hi %d %d %d %d\n", w, e, n, s);
        //    return 0;
        //}
    }
    printf("%d\n", ans);
}

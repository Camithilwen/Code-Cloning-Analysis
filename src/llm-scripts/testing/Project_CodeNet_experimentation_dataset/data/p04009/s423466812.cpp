#include<bits/stdc++.h>
using namespace std;

int H, W, rlen, clen, psum[102][102];
char G[102][102];

int calc(int r1, int c1, int r2, int c2) {
    int ret = psum[r2][c2];
    if(r1) ret -= psum[r1 - 1][c2];
    if(c1) ret -= psum[r2][c1 - 1];
    if(r1 && c1) ret += psum[r1 - 1][c1 - 1];
    return ret;
}

int re, ce;
int cc[102][102];
int dp(int r, int c) {
    int &ret = cc[r][c];
    if(ret != -1) return ret;

    ret = 0;
    if(r + rlen - 1 != re) {
        ret = max(ret, calc(r + rlen, c, r + rlen, c + clen - 1) + dp(r + 1, c));
    }
    if(c + clen - 1 != ce) {
        ret = max(ret, calc(r, c + clen, r + rlen - 1, c + clen) + dp(r, c + 1));
    }
    return ret;
}

int main() {
    scanf("%d %d", &H, &W);

    int r, c;
    for(int i = 0; i < H; i++) {
        scanf("\n");
        for(int j = 0; j < W; j++) {
            scanf("%c", &G[i][j]);

            if(G[i][j] == 'E') r = i, c = j;
        }
    }

    if(r + 1 > H - r) {
        for(int i = 0; i < H - 1 - i; i++) for(int j = 0; j < W; j++) swap(G[i][j], G[H - 1 - i][j]);
        r = H - 1 - r;
    }
    if(c + 1 > W - c) {
        for(int i = 0; i < H; i++) for(int j = 0; j < W - 1 - j; j++) swap(G[i][j], G[i][W - 1 - j]);
        c = W - 1 - c;
    }
    rlen = r + 1;
    clen = c + 1;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            psum[i][j] = G[i][j] == 'o'? 1 : 0;
            if(i) psum[i][j] += psum[i - 1][j];
            if(j) psum[i][j] += psum[i][j - 1];
            if(i && j) psum[i][j] -= psum[i - 1][j - 1];
        }
    }

    int ans = 0;
    for(int i = 0; i <= r; i++) {
        for(int j = 0; j <= c; j++) {
            re = H - 1 - r + i;
            ce = W - 1 - c + j;

            memset(cc, -1, sizeof(cc));
            ans = max(ans, calc(i, j, i + rlen - 1, j + clen - 1) + dp(i, j));
        }
    }

    cout << ans;
}

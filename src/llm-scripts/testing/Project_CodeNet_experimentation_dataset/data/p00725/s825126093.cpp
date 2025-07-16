#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int w, h;
int board[21][21];
int ans = INF;
bool valid(int y, int x) { return 0 <= y && y < h && 0 <= x && x < w; }
void print() {
    rep(y, h) {
        rep(x, w) printf("%d ", board[y][x]);
        printf("\n");
    }
}
void dfs(int y, int x, int cnt) {
    // printf("debug: %d %d %d\n", y, x, cnt);
    // print();
    if (cnt == 10) return;
    rep(k, 4) {
        int ny = y;
        int nx = x;
        if (!valid(ny + dy[k], nx + dx[k])) continue;
        if (board[ny + dy[k]][nx + dx[k]] == 1) continue;
        while (1) {
            if (!valid(ny + dy[k], nx + dx[k])) break;
            ny += dy[k];
            nx += dx[k];
            if (board[ny][nx] == 3) {
                ans = min(cnt + 1, ans);
                return;
            }
            if (board[ny][nx] == 1) {
                board[ny][nx] = 0;
                dfs(ny - dy[k], nx - dx[k], cnt + 1);
                board[ny][nx] = 1;
                break;
            }
        }
    }
}
int main() {
    while (cin >> w >> h, w) {
        ans = INF;
        rep(i, h) rep(j, w) cin >> board[i][j];
        rep(y, h) rep(x, w) if (board[y][x] == 2) dfs(y, x, 0);
        if (ans == INF) ans = -1;
        cout << ans << endl;
    }
    return 0;
}
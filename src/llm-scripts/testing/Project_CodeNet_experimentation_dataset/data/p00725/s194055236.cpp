#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> P;
const int inf = 1 << 28;

int w, h;
int a[21][21];
int sx, sy, gx, gy;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

bool check(int x, int w) { return 0 <= x && x < w; }

int dfs(int x, int y, int cnt) {
    if (cnt >= 10) {
        return inf;
    }

    int ret = inf;

    for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k];

        while (check(nx, w) && check(ny, h) && a[ny][nx] != 1 &&
               a[ny][nx] != 3) {
            nx += dx[k];
            ny += dy[k];
        }

        if (!check(nx, w) || !check(ny, h)) {
            continue;
        }

        if (a[ny][nx] == 3) {
            return 1;
        }

        if (nx - dx[k] == x && ny - dy[k] == y) {
            continue;
        }

        a[ny][nx] = 0;

        ret = min(ret, dfs(nx - dx[k], ny - dy[k], cnt + 1) + 1);

        a[ny][nx] = 1;
    }

    return ret;
}

int main() {
    while (cin >> w >> h, !(w == 0 && h == 0)) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> a[i][j];

                if (a[i][j] == 2) {
                    sy = i;
                    sx = j;
                }

                if (a[i][j] == 3) {
                    gy = i;
                    gx = j;
                }
            }
        }

        int ans = dfs(sx, sy, 0);

        if (ans <= 10) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
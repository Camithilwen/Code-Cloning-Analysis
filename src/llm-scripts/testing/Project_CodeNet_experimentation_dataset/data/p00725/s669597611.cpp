#include <cstdio>
#include <vector>

using namespace std;

#define MAX_H 20
#define MAX_W 20

#define INF (1<<28)

int w, h;
int F[MAX_H][MAX_W];
int G[MAX_H][MAX_W];
int gy, gx;
int y, x;
int py, px;

void debug();

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
void move(int d) {
    //printf("    %d\n", d);
    while (F[y][x] == 0) {
        x += dx[d];
        y += dy[d];
    }
    if (F[y][x] == 3) return;
    F[y][x] = 0;
    y -= dy[d];
    x -= dx[d];
}

bool can_move(int d) {
    if (F[y+dy[d]][x+dx[d]] == 1) return false;
    int _y = y;
    int _x = x;
    while (F[_y][_x] == 0) {
        _y += dy[d];
        _x += dx[d];
        if (_y < 0 || h <= _y || _x < 0 || w <= _x) return false;
    }
    return true;
}

void debug() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d ", F[i][j]);
        }
        printf("\n");
    }
}

int solve(int cur) {
    if (y == gy && x == gx) return 0;
    if (cur >= 10) return INF;
    int min_cost = INF;
    for (int i = 0; i < 4; i++) {
        if (can_move(i)) {
            int backup[h][w];
            int py = y, px = x;
            for (int j = 0; j < h; j++)
                for (int k = 0; k < w; k++)
                    backup[j][k] = F[j][k];
            move(i);
            min_cost = min(min_cost, solve(cur+1)+1);
            y = py, x = px;
            for (int j = 0; j < h; j++)
                for (int k = 0; k < w; k++)
                    F[j][k] = backup[j][k];
        }
    }
    return min_cost;
}

int main() {
    while (scanf("%d %d", &w, &h), w || h) {
        int sy, sx;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) {
                scanf("%d", &F[i][j]);
                if (F[i][j] == 2) {
                    y = i, x = j;
                    F[i][j] = 0;
                }
                if (F[i][j] == 3) 
                    gy = i, gx = j;
            }
        int ans = solve(0);
        printf("%d\n", (ans > 10 ? -1 : ans));
    }
    return 0;
}
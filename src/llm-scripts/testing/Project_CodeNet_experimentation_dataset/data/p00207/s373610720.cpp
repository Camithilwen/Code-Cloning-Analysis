#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> P;

const int INF = (int)1e9;

int board[128][128];

int main()
{
    int w, h;

    while (scanf("%d %d", &w, &h), w){
        int xs, ys;
        int xg, yg;
        scanf("%d %d", &xs, &ys);
        scanf("%d %d", &xg, &yg);

        int n;
        scanf("%d", &n);
        memset(board, 0, 128 * 128);
        while (n-- > 0){
            int c, d, x, y;
            scanf("%d %d %d %d", &c, &d, &x, &y);

            board[y][x] = board[y][x + 1] = c;
            board[y + 1][x] = board[y + 1][x + 1] = c;
            if (d == 0){
                board[y][x + 2] = board[y][x + 3] = c;
                board[y + 1][x + 2] = board[y + 1][x + 3] = c;
            }
            else {
                board[y + 2][x] = board[y + 3][x] = c;
                board[y + 2][x + 1] = board[y + 3][x + 1] = c;
            }
        }

        queue<P> que;
        bool flag = false;
        int color = board[ys][xs];

        if (!color){
            puts("NG");
            continue;
        }

        for (que.push(P(xs, ys)); que.size(); que.pop()){
            P p = que.front();
            int x = p.first;
            int y = p.second;

            if (board[y][x] != color) continue;

            if (x == xg && y == yg){
                flag = true;
                break;
            }
            board[y][x] = !color;
            que.push(P(x + 1, y));
            que.push(P(x - 1, y));
            que.push(P(x, y + 1));
            que.push(P(x, y - 1));
        }

        puts(flag ? "OK" : "NG");
    }

    return 0;
}
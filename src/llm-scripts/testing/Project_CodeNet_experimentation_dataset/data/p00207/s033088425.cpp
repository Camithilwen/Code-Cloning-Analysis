#include<iostream>
#include<string>
#include<queue>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int board[100][100];

void init_board() {
    int i, j;
    for (i=0; i<100; i++) {
        for (j=0; j<100; j++) {
            board[i][j] = 0;
        }
    }
}
void put_block(int c, int d, int x, int y) {
    int i, j;
    int i_stop = d? 2+x: 4+x;
    int j_stop = d? 4+y: 2+y;
    for (i=x; i<i_stop; i++) {
        for (j=y; j<j_stop; j++) {
            board[i][j] = c;
        }
    }
}

string trace(int xs, int ys, int xg, int yg) {
    int x, y, nx, ny, i, c;
    queue<pair<int, int> > q;
    q.push(make_pair(xs, ys));
    c = board[xs][ys];
    if (c == 0) {
        return "NG";
    }
    board[xs][ys] = 0;
    while (q.size() > 0) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (x==xg && y==yg) {
            return "OK";
        }
        for (i=0; i<4; i++) {
            nx = x+dx[i];
            ny = y+dy[i];
            if (nx<0 || ny<0 || nx>=100 || ny>=100) {
                continue;
            }
            if (board[nx][ny] == c) {
                q.push(make_pair(nx, ny));
                board[nx][ny] = 0;
            }
        }
    }
    return "NG";
}

int main() {
    int w, h, xs, ys, xg, yg, n, c, d, x, y, i;
    while (true) {
        cin >> w >> h;
        if (w==0 && h==0) {
            break;
        }
        cin >> xs >> ys;
        cin >> xg >> yg;
        cin >> n;
        init_board();
        for (i=0; i<n; i++) {
            cin >> c >> d >> x >> y;
            put_block(c, d, x, y);
        }
        cout << trace(xs, ys, xg, yg) << endl;
    }

    return 0;
}
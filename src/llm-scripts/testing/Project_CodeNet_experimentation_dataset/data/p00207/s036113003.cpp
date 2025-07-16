#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define repeat(n, i) for(int i=0; i<(n); i++)
int w, h;
int xs, ys;
int xg, yg;
int n;

int st_color;

int board[300][300];

#define VISITED 6

bool get_input() {
    memset(board, 0, sizeof(board));
    cin >> w >> h;
    if (w == 0 && h == 0) return false;
//    board.resize(h);
//    repeat(h, i) board[i].resize(w);
    cin >> xs >> ys;
    cin >> xg >> yg;
    cin >> n;
    repeat(n, i) {
        int c, d, x, y;
        cin >> c >> d >> x >> y;
        if (d == 1) {
            for (int j = y-1; j < y-1+4; j++) {
                for (int k = x-1; k < x-1+2; k++) {
                    board[j][k] = c;
                }
            }
        } else {
            for (int j = y-1; j < y-1+2; j++) {
                for (int k = x-1; k < x-1+4; k++) {
                    board[j][k] = c;
                }
            }
        }
    }
    st_color = board[ys-1][xs-1];
    return true;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool possible;
void dfs(int x, int y) {
    board[y-1][x-1] = VISITED;
    if (x == xg && y == yg) {
        possible = true;
        return;
    }
    repeat(4, i) {
        int nx = x+dx[i], ny = y+dy[i];
        if (1 <= nx && nx <= w && 1 <= ny && ny <= h) {
            if (board[ny-1][nx-1] == st_color) {
                dfs(nx, ny);
            }
        }
    }
}

// debug 
//void solve() {
//    repeat(h, i) {
//        repeat(w, j) {
//            cout << board[i][j] << ' ';
//        }
//        cout << endl;
//    }
//}

void solve() {
    possible = false; dfs(xs, ys);
    if (possible) cout << "OK" << endl;
    else cout << "NG" << endl;
}

int main() {
    while (get_input()) {
        solve();
    }
    return 0;
}
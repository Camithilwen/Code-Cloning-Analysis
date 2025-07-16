#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const char Q = 'Q';
const char _ = '.';

char board[8][9] = {
    "........",
    "........",
    "........",
    "........",
    "........",
    "........",
    "........",
    "........",
};

int n;
bool pre_x[8], pre_y[8];

inline bool check(int x, int y) {
    int p = x, q = y;
    while (--p >= 0 && --q >= 0) {  // upper left 
        if (board[q][p] == Q) return false;
    }

    p = x; q = y;
    while (++p < 8 && --q >= 0) {   // upper right 
        if (board[q][p] == Q) return false;
    }

    p = x; q = y;
    while (++p < 8 && ++q < 8) {    // lower right 
        if (board[q][p] == Q) return false;
    }

    p = x; q = y;
    while (--p >= 0 && ++q < 8) {   // lower left 
        if (board[q][p] == Q) return false;
    }

    return true;
}

bool solve(int row) {
    if (row == 8)
        return true;
    if (pre_y[row] && solve(row + 1)) {
        return true;
    }
    else {
        for (int i = 0; i < 8; ++i) {
            if (!pre_x[i] && check(i, row)) {
                board[row][i] = Q;
                pre_x[i] = true;
                if (solve(row + 1)) {
                    return true;
                }
                else {
                    board[row][i] = _;
                    pre_x[i] = false;
                }
            }
        }
    }
    return false;
}

int main(void) {

    scanf("%d", &n);

    for (int i = 0, x, y; i < n; ++i) {
        scanf("%d %d", &y, &x);
        board[y][x] = Q;
        pre_y[y] = pre_x[x] = true;
    }

    solve(0);

    for (int i = 0; i < 8; ++i) {
        printf("%s\n", board[i]);
    }

    return 0;
}
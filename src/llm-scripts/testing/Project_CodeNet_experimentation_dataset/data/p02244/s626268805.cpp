#include <bits/stdc++.h>

#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)

using namespace std;

// info
int board[8][8];
int res[8];

void fillBoard(int row, int col, int cnt);
void printBoard();
void recur(int row);
int main()
{
    fill(res, res+8, -1);
    // rep(i, 8){
    //     fill(board[i], board[i]+8, 0);
    // }

    int n; cin >> n;
    rep(i, n){
        int row, col;
        cin >> row >> col;
        fillBoard(row, col, 1);
        res[row] = col;
    }

    // printBoard();
    // rep(i, 8)
    // {
    //     rep(j, 8)
    //     {
    //         cout << board[i][j]
    //              << (j < 7 ? " " : "\n");
    //     }
    // }
    recur(0);
    return 0;
}

void fillBoard(int row, int col, int cnt)
{
    board[row][col] += cnt;

    rep(i, 8)
    {
        if (i != col)
        {
            board[row][i] += cnt;

            int j1 = row - col + i;
            if (j1 >= 0 && j1 < 8)
                board[j1][i] += cnt;

            int j2 = col + row - i;
            if (j2 >= 0 && j2 < 8) // here!!
                board[j2][i] += cnt;
        }

        if (i != row)
            board[i][col] += cnt;
    }
}
void printBoard()
{
    rep(i, 8)
    {
        rep(j, 8)
        {
            cout << (res[i] == j?"Q":".") 
             << (j < 7 ? "" : "\n");
        }
    }
}
void recur(int row)
{
    if (row == 8)
    {
        printBoard();
        return;
    }

    if (res[row] < 0)
    {
        // int flag = -1;
        rep(col, 8)
        {
            if (board[row][col] == 0)
            {
                // flag++;

                fillBoard(row, col, 1);
                res[row] = col;
                recur(row + 1);
                res[row] = -1;
                fillBoard(row, col, -1);
            }
        }
        // if(flag < 0) return;
    }
    else
        recur(row + 1);
}

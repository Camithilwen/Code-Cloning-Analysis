#include <iostream>

#define Free (-1)
#define NonFree (-2)
#define NoQ (-3)
using namespace std;
const int N = 8;
int row[N];
int col[N];
int dpos[15];
int dneg[15];

int inits[N];

void printBoard() {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (row[r] != c) {
                cout << ".";
            } else {
                cout << "Q";
            }
        }
        cout << endl;
    }
};

void putQueen(int i) { 
    int j;
    if (i == N) {
        printBoard();
        return;
    }
    if (inits[i] == Free) {
        for (j = 0; j < N; ++j) {
            if (col[j] == NonFree ||
                dpos[i + j] == NonFree ||
                dneg[i - j + N - 1] == NonFree) {
                continue;
            }
            row[i] = j;
            col[j] = dpos[i + j] = dneg[i - j + N - 1] = NonFree;
            putQueen(i + 1);
            row[i] = NoQ;
            col[j] = dpos[i + j] = dneg[i - j + N - 1] = Free;
        }
    }else{
        putQueen(i + 1);
    }
};
void DeskSetup(int r, int c) {  // Basic
    row[r] = c;
    col[c] = dpos[r + c] = dneg[r - c + N - 1] = NonFree;
}

void InitDesk() { // Basic
    for (int j = 0; j < N; ++j) {
        row[j] = NoQ;
        col[j] = inits[j] = Free;
    }
    for (int j = 0; j < 15; ++j) {
        dpos[j] = dneg[j] = Free;
    }

};

int main() {
    int r, c, i;
    InitDesk();
    cin >> i;
    for (int k = 0; k < i; ++k) {
        cin >> r >> c;
        DeskSetup(r, c);
        inits[r] = NonFree;
    }
    putQueen(0);
    return 0;
}

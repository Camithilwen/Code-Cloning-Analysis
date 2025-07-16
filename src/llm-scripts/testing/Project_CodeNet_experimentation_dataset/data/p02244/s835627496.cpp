#include <iostream>

using namespace std;

#define N 8
#define FREE 0
#define NOT_FREE -1

bool BOARD[N][N] = { false };
int C_COL[N], C_ROW[N], C_DIAGONAL_L[2*N], C_DIAGONAL_R[2*N];

void printBoard() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (BOARD[i][j])
        if (C_ROW[i] != j) return;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << (C_ROW[i] == j ? 'Q' : '.');
    }
    cout << endl;
  }
}

void solve(int i) {
  if (i == N) {
    printBoard();
    return;
  }

  for (int j = 0; j < N; j++) {
    if (C_COL[j] == NOT_FREE ||
        C_DIAGONAL_L[i+j] == NOT_FREE ||
        C_DIAGONAL_R[i-j+N-1] == NOT_FREE
        ) continue;

    C_ROW[i] = j;
    C_COL[j] = C_DIAGONAL_L[i+j] = C_DIAGONAL_R[i-j+N-1] = NOT_FREE;

    solve(i+1);

    C_ROW[i] = C_COL[j] = C_DIAGONAL_L[i+j] = C_DIAGONAL_R[i-j+N-1] = FREE;
  }

  //cout << "no solution for input" << endl;
  
}

int main() {
  for (int i = 0; i < N; i++) {
    C_COL[i] = C_ROW[i] = FREE;
    C_DIAGONAL_L[i] = C_DIAGONAL_R[i] = FREE;
    C_DIAGONAL_L[2*i] = C_DIAGONAL_R[2*i] = FREE;
  }
  
  int k; cin >> k;
  while (k--) {
    int r, c; cin >> r >> c;
    BOARD[r][c] = true;
  }

  solve(0);
}
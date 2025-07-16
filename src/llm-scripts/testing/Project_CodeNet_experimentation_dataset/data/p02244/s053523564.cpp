#include <iostream>
using namespace std;

#define N 8

int row[N], col[N], dpos[N * 2 - 1], dneg[N * 2 - 1];

int putQueen(int i) {
  int res = 0;
  if (i == N) return 1;
  if (row[i] != -1) return putQueen(i + 1);

  for (int j = 0; j < N; j++) {
    if (col[j] || dpos[i + j] || dneg[i - j + (N - 1)]) continue;
    row[i] = j;
    col[j] = dpos[i + j] = dneg[i - j + (N - 1)] = 1;
    res = putQueen(i + 1);
    if (res) return 1;
    col[j] = dpos[i + j] = dneg[i - j + (N - 1)] = 0;
    row[i] = -1;
  }
  return 0;
}

int main() {
  int k, r, c;

  for (int i = 0; i < N; i++) {
    row[i] = -1;
    col[i] = 0;
  }
  for (int i = 0; i < N * 2 - 1; i++) dpos[i] = dneg[i] = 0;

  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> r >> c;
    row[r] = c;
    col[c] = 1;
    dpos[r + c] = 1;
    dneg[r - c + (N - 1)] = 1;
  }

  putQueen(0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      if (row[i] == j)
        cout << "Q";
      else
        cout << ".";
    cout << endl;
  }

  return 0;
}


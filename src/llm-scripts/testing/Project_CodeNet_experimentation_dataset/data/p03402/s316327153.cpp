#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int N = 100;
  vector<vector<bool>> G(N, vector<bool>(N));
  for (int i = 0; i < N / 2; i++) {
    for (int j = 0; j < N; j++) {
      G[i][j] = 1;
    }
  }
  int i = 0, j = 0;
  for (int c = 0; c < A - 1; c++) {
    G[i][j] = 0;
    j += 2;
    if (j >= N) {
      i += 2;
      j = 0;
    }
  }
  i = N / 2 + 1, j = 0;
  for (int c = 0; c < B - 1; c++) {
    G[i][j] = 1;
    j += 2;
    if (j >= N) {
      i += 2;
      j = 0;
    }
  }
  cout << "100 100" << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (G[i][j]) {
        cout << '#';
      } else {
        cout << '.';
      }
    }
    cout << endl;
  }

  return 0;
}
/* vim:set fdm=marker: */

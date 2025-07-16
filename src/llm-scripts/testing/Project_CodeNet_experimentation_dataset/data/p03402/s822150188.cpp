#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B; cin >> A >> B;
  A--; B--;
  vector<vector<int>> G(100, vector<int>(100));
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 100; j++) G.at(i).at(j) = 1;
  }
  int wy = 1, wx = 1;
  while (A > 0) {
    G.at(wy).at(wx) = 0;
    A--;
    if (wx == 99) {
      wy += 2;
      wx = 1;
    }
    else wx += 2;
  }
  int by = 51, bx = 1;
  while (B > 0) {
    G.at(by).at(bx) = 1;
    B--;
    if (bx == 99) {
      by += 2;
      bx = 1;
    }
    else bx += 2;
  }
  cout << 100 << " " << 100 << endl;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (G.at(i).at(j) == 0) cout << '.';
      else cout << '#';
    }
    cout << endl;
  }
}
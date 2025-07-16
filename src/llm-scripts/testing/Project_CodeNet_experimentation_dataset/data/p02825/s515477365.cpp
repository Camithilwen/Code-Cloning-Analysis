#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

int n;
char g3[3][3] = {
  {0, 1, 1},
  {1, 0, 0},
  {1, 0, 0}
}, g4[4][4] = {
  {1, 2, 3, 3},
  {1, 2, 1, 1},
  {3, 3, 2, 3},
  {1, 1, 2, 3}
}, g5[5][5] = {
  {2, 3, 3, 2, 2},
  {2, 0, 1, 1, 3},
  {3, 1, 0, 0, 3},
  {3, 1, 0, 0, 2},
  {2, 2, 3, 3, 2}
}, g7[7][7] = {
  {1, 2, 2, 0, 0, 2, 2},
  {1, 0, 0, 2, 2, 0, 1},
  {0, 1, 0, 3, 3, 0, 1},
  {0, 1, 3, 0, 0, 1, 0},
  {1, 0, 3, 0, 0, 1, 0},
  {1, 0, 2, 2, 0, 0, 1},
  {2, 2, 0, 0, 2, 2, 1}
}, r[1100][1100];

char itc(int v) {
  return v == 0 ? '.' : ('a' + v);
}

void place3(int i, int j) {
  for (int k = 0; k < 3; k++)
    for (int l = 0; l < 3; l++)
      r[i + k][j + l] = itc(g3[k][l]);
}

void place4(int i, int j) {
  for (int k = 0; k < 4; k++)
    for (int l = 0; l < 4; l++)
      r[i + k][j + l] = itc(g4[k][l]);
}

void place5(int i, int j) {
  for (int k = 0; k < 5; k++)
    for (int l = 0; l < 5; l++)
      r[i + k][j + l] = itc(g5[k][l]);
}

void place7(int i, int j) {
  for (int k = 0; k < 7; k++)
    for (int l = 0; l < 7; l++)
      r[i + k][j + l] = itc(g7[k][l]);
}

void place9(int i, int j) {
  for (int k = 0; k < 9; k += 3)
    for (int l = 0; l < 9; l += 3)
      place3(i + k, j + l);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n;
  if (n == 2) {
    cout << -1 << "\n";
    return 0;
  }
  if (n % 3 == 0) {
    for (int i = 0; i < n; i += 3)
        place3(i, i);
  } else {
    for (int i = n - 9; i >= 4; i -= 9)
        place9(i, i);
    if (n % 9 == 1)
      place5(0, 0), place5(5, 5);
    else if (n % 9 == 2)
      place4(0, 0), place7(4, 4);
    else if (n % 9 == 4)
      place4(0, 0);
    else if (n % 9 == 5)
      place5(0, 0);
    else if (n % 9 == 7)
      place7(0, 0);
    else if (n % 9 == 8)
      place4(0, 0), place4(4, 4);
  }
  for (int i = 0; i < n; i++, cout << "\n")
    for (int j = 0; j < n; j++)
      cout << (r[i][j] == 0 ? '.' : r[i][j]);
}

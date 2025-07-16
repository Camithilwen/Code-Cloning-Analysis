#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300;
int mat[2][1 + 2 * nmax][1 + 2 * nmax];

std::vector<std::pair<int,int>> mv[2];
int lim;

bool valid(int x, int y) {
  return 0 <= x && x < lim && 0 <= y && y < lim;
}

void dfs(int x, int y, int color, int p) {
  if(mat[p][x][y] == 0) {
    mat[p][x][y] = color;
    for(int h = 0; h < mv[p].size(); h++) {
      int newx = x + mv[p][h].first;
      int newy = y + mv[p][h].second;
      if(valid(newx, newy))
        dfs(newx, newy, 3 - color, p);
    }
  }
}
int frec[3][3];

int main() {
  int n, d1, d2;
  std::cin >> n;
  std::cin >> d1 >> d2;
  lim = 2 * n;
  for(int i = -lim; i <= lim; i++)
    for(int j = -lim; j <= lim; j++) {
      if(i * i + j * j == d1)
        mv[0].push_back({i, j});
      if(i * i + j  * j == d2)
        mv[1].push_back({i, j});
    }
  for(int i = 0; i < lim; i++)
    for(int j = 0; j < lim; j++) {
      dfs(i, j, 1, 0);
      dfs(i, j, 1, 1);
      frec[mat[0][i][j]][mat[1][i][j]]++;
    }
  for(int h = 1; h <= 2; h++)
    for(int h2 = 1; h2 <= 2; h2++)
      if(n * n <= frec[h][h2]) {
        int lft = n * n;
        for(int i = 0; i < lim; i++)
          for(int j = 0; j < lim; j++)
            if(0 < lft && mat[0][i][j] == h && mat[1][i][j] == h2) {
              std::cout << i << " " << j << '\n';
              lft--;
            }
        return 0;
      }
  return 0;
}

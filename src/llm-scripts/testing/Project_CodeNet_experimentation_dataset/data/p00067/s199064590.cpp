#include <iostream>
#include <string>
#define MAP 12
using namespace std;

int map[MAP][MAP];

bool valid(int y, int x) {
  if ((0 <= y && y < MAP) && (0 <= x && x < MAP)) {
    if (map[y][x] == 1)
      return true;
  }
  return false;
}

void remove_island(int y, int x) {
  int nx, ny;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  map[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    ny = y + dy[i];
    nx = x + dx[i];
    if ((valid(ny, nx)))
      remove_island(ny, nx);
  }
}

int main() {
  char c[13];
  int ans;
  while (1) {
    for (int i = 0; i < MAP; i++) {
      if (!(cin >> c))
        return 0;
      for (int j = 0; j < MAP; j++) {
        map[i][j] = (int)(c[j] - '0');
      }
    }
    ans = 0;
    for (int i = 0; i < MAP; i++) {
      for (int j = 0; j < MAP; j++) {
        if (valid(i, j)) {
          remove_island(i, j);
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
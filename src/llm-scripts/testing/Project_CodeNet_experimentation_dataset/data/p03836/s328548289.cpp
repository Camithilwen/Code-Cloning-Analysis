#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("../data.txt");

int x1, y1, x2, y2, aux, sx, sy, tx, ty, roads, minix, miniy, nx, ny, ax, ay;
char dir;
int a[2005][2005];
string ans, sdir;
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int absVal(int x) {
  if (x < 0) return -x;
  return x;
}

bool isValid(int x, int y) {
  if (x > 2004 || x < 0 || y > 2004 || y < 0 || a[x][y] == 1) return 0;
  return 1;
}

int main() {
   ans = "", sdir = "URDL";
   cin >> x1 >> y1 >> x2 >> y2;
   aux = x1;
   x1 -= aux - 1;
   x2 -= aux - 1;
   aux = y1;
   y1 -= aux - 1;
   y2 -= aux - 1;
   sx = x1;
   sy = y1;
   tx = x2;
   ty = y2;
   //cout << sx << " " << sy << " " << tx << " " << ty << "\n";
   //cout << x1 << " " << y1 << " " << x2 << " " << y2;
   a[sx][sy] = 1;
   while (roads < 4) {
    //  cout << sx << " " << sy << " " << tx << " " << ty << "\n\n";
    //  for (int i = 0; i < 5; i++) {
    //   for (int j = 0; j < 5; j++) {
    //     cout << a[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
    //if (sx == 0 && sy == 2) return 0;
    //cout << "\n";
     minix = miniy = 20000;
     for (int i = 0; i < 4; i++) {
      if (isValid(sx + d[i].first, sy + d[i].second)) {
        ax = absVal(tx - sx - d[i].first);
        ay = absVal(ty - sy - d[i].second);
        if (minix > ax || miniy > ay) {
          //cout << ax << " " << ay << "\n";
          minix = ax;
          miniy = ay;
          nx = sx + d[i].first;
          ny = sy + d[i].second;
          dir = sdir[i];
        }
     }
     }

     ans += string(1, dir);
     a[nx][ny] = 1;
     sx = nx;
     sy = ny;
     if (sx == tx && sy == ty) {
       roads++;
       if (roads % 2) {
         sx = x2;
         sy = y2;
         tx = x1;
         ty = y1;
       } else {
         sx = x1;
         sy = y1;
         tx = x2;
         ty = y2;
       }
       a[sx][sy] = 1;
       a[tx][ty] = 0;
     }
    }
  cout << ans;
  return 0;
}

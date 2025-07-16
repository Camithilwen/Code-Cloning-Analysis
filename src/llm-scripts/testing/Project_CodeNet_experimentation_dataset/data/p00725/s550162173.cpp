#include <iostream>
#include <utility>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

const int INF = 1 << 28;

int w, h;
int field[32][32];
int sx, sy;
int gx, gy;

int ofs[4][2] = {
  {0,1},
  {1,0},
  {-1,0},
  {0,-1}
};

bool ok(int p, int n)
{
  return 0 <= p && p < n;
}

bool dfs(int x, int y, int d, int n)
{
  if( d >= n ) {
    return false;
  }

  bool res = false;
  rep(i, 4) {
    int dx = ofs[i][0];
    int dy = ofs[i][1];
    int nx = x;
    int ny = y;
    int idx = 0;
    while(ok(nx, w) && ok(ny, h) && !field[ny][nx]) {
      nx += dx;
      ny += dy;
      if(nx == gx && ny == gy) {
        return true;
      }
      ++idx;
    }
    if( idx > 1 && ok(nx, w) && ok(ny, h) ) {
      field[ny][nx] = 0;
      res |= dfs(nx - dx, ny - dy, d + 1, n);
      field[ny][nx] = 1;
    }
  }
  return res;
}

int idfs(int sx, int sy)
{
  int idx = 1;
  while( idx <= 10 && !dfs(sx, sy, 0, idx) ) {
    ++idx;
  }
  if( idx > 10 ) {
    return -1;
  } else {
    return idx;
  }
}

int main()
{
  while( cin >> w >> h, (h|w) ) {
    rep(i, h) rep(j, w) {
      int v;
      cin >> v;
      field[i][j] = v & 1;
      if( v & 2 ) {
        if( v & 1 ) {
          gx = j;
          gy = i;
        } else {
          sx = j;
          sy = i;
        }
      }
    }

    cout << idfs(sx, sy) << endl;
  }
  return 0;
}
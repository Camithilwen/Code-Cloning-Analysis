#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)

#define DEBUG(x) cerr << #x << " = " << x << endl
int F[20][20];

const int INF = (int)1e9;
const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { 1, 0, -1, 0 };

int W, H;
int ans;

void solve(const int y, const int x, const int depth) {
  if(F[y][x] == 3) {
    ans = min(ans, depth);
    return;
  }
  if(depth >= 10) return;
  for(int k = 0; k < 4; ++k) {
    int ny = y, nx = x;
    if(0 <= ny + dy[k] && ny + dy[k] < H && 0 <= nx + dx[k] && nx + dx[k] < W && F[ny + dy[k]][nx + dx[k]] == 1) continue;
    bool ok = true;
    int sy = -1, sx = -1;
    while(true) {
      if(F[ny][nx] == 3) break;
      ny += dy[k];
      nx += dx[k];
      if(ny < 0 || ny >= H || nx < 0 || nx >= W) {
        ok = false;
        break;
      }
      if(F[ny][nx] == 1) {
        sy = ny;
        sx = nx;
        F[sy][sx] = 0;
        ny -= dy[k];
        nx -= dx[k];
        break;
      }
    }
    if(ok)
      solve(ny,nx,depth+1);
    if(sy != -1 && sx != -1) {
      F[sy][sx] = 1;
    }
  }
}

int main() {
  while(true) {
    cin >> W >> H;
    if(W == 0 && H == 0) break;
    REP(i,H) REP(j,W) cin >> F[i][j];
    ans = INF;
    REP(i,H) REP(j,W) {
      if(F[i][j] == 2) solve(i,j,0);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
  }
}
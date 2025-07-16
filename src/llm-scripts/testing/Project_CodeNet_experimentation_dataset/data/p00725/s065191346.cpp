#include <iostream>
using namespace std;

const int INF = 1 << 30;
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

int W, H;
int B[32][32];

int dfs(int x, int y, int times) {
  if(times == 10) return INF;

  int best = INF;

  for(int i = 0; i < 4; i++) {
    int j = 1;

    for(; ; j++) {
      int ny = y + dy[i] * j, nx = x + dx[i] * j;

      if(nx < 0 || W <= nx || ny < 0 || H <= ny) {
        break;
      }

      if(B[ny][nx] == 1) {
        if(j == 1) {
          break;
        }
        
        B[ny][nx] = 0;
        best = min(best, dfs(nx - dx[i], ny - dy[i], times + 1));
        B[ny][nx] = 1;
        break;
      }

      if(B[ny][nx] == 3) {
        return times + 1;
      }
    }
  }

  return best;
}

int main() {
  for(; cin >> W >> H && W; ) {
    int sx = -1, sy = -1;

    for(int y = 0; y < H; y++) {
      for(int x = 0; x < W; x++) {
        cin >> B[y][x];

        if(B[y][x] == 2) {
          sx = x;
          sy = y;
        }
      }
    }

    int res = dfs(sx, sy, 0);
    cout << (res == INF ? -1 : res) << endl;
  }
}
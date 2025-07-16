#include <iostream>
#include <cstring>
using namespace std;

int w, h, n;
int sx, sy, gx, gy;
int t[102][102];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool check(int x, int y, int c){
  if(x == gx && y == gy) return true;

  t[y][x] = -1;

  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx < 0 || w <= nx || ny < 0 || h <= ny || t[ny][nx] != c) continue;
    if(check(nx, ny, c)) return true;
  }

  return false;
}

void putBlock(int c, int d, int x, int y){
  int addX = (d == 0 ? 4 : 2);
  int addY = (d == 0 ? 2 : 4);

  for(int i = y; i < y + addY; i++){
    for(int j = x; j < x + addX; j++){
      t[i][j] = c;
    }
  }
}

int main(){
  while(cin >> w >> h, w || h){
    cin >> sx >> sy; sx--; sy--;
    cin >> gx >> gy; gx--; gy--;
    cin >> n;

    memset(t, -1, sizeof(t));

    for(int i = 0; i < n; i++){
      int c, d, x, y;
      cin >> c >> d >> x >> y;

      x--;
      y--;
      putBlock(c, d, x, y);
    }

    /*
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        printf("%2d", t[i][j]);
      }
      cout<<endl;
    }
    */

    if(t[sy][sx] != -1 && check(sx, sy, t[sy][sx])){
      cout << "OK\n";
    }
    else{
      cout << "NG\n";
    }
  }
}
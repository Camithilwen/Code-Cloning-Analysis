#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int w,h;
int sx,sy;
int gx,gy;
int n;

vector<vector<int>> field;
int de[] = {1, 0, -1, 0};

void dfs(int x ,int y, int c) {
  if(x < 1 || x > w || y < 1 || y > h || field[x][y] != c) return;
  field[x][y] = -1;
  dfs(x + 1, y, c);
  dfs(x - 1, y, c);
  dfs(x, y + 1, c);
  dfs(x, y - 1, c);
}

int main() {
  while(cin >> w >> h, w && h) {
    field.assign(101, vector<int>(101, 0));
    cin >> sx >> sy;
    cin >> gx >> gy;
    cin >> n;
    int dd[] = {4, 2};
    for(int i = 0;i < n;i++) {
      int c, d, x, y;
      cin >> c >> d >> x >> y;
      for(int xx = x; xx < x + dd[d];xx++) {
        for(int yy = y;yy < y + dd[d ^ 1];yy++) {
          field[xx][yy] = c;
        }
      }
    }
    if(field[sx][sy] == 0) {
      cout << "NG" << endl;
      continue;
    }
    dfs(sx, sy, field[sx][sy]);
    if(field[gx][gy] == -1) {
      cout << "OK" << endl;
    }
    else {
      cout << "NG" << endl;
    }
  }
}



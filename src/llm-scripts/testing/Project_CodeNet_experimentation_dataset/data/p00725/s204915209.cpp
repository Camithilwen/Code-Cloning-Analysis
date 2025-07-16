#include<bits/stdc++.h>
using namespace std;
typedef pair< int, int > Pi;
const static int dy[] = {0, 1, 0, -1};
const static int dx[] = {1, 0, -1, 0};
const static int INF = 1 << 30;

int w, h, mas[20][20];
Pi S, G;

bool In(int x, int y)
{
  return(0 <= x && x < w && 0 <= y && y < h);
}

int rec(int x, int y, int d, int cost)
{
  if(cost > 10) return(INF);
  if(make_pair(x, y) == G) return(cost);
  int ret = INF;
  if(d == -1) {
    for(int i = 0; i < 4; i++) {
      if(!In(x + dx[i], y + dy[i])) continue;
      if(In(x + dx[i], y + dy[i]) && mas[y + dy[i]][x + dx[i]] == 1) continue;
      ret = min(ret, rec(x + dx[i], y + dy[i], i, cost + 1));
    }
  } else {
    x += dx[d], y += dy[d];
    if(In(x, y)) {
      if(mas[y][x] == 1) {
        mas[y][x] = 0;
        ret = rec(x - dx[d], y - dy[d], -1, cost);
        mas[y][x] = 1;
      } else {
        ret = rec(x, y, d, cost);
      }
    }
  }
  return(ret);
}

int main()
{
  while(cin >> w >> h, w) {
    S = make_pair(-1, -1);
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        cin >> mas[i][j];
        if(mas[i][j] == 2) {
          S = make_pair(j, i);
        } else if(mas[i][j] == 3) {
          G = make_pair(j, i);
        }
      }
    }
    int ret = rec(S.first, S.second, -1, 0);
    if(S == make_pair(-1, -1) || ret == INF) cout << -1 << endl;
    else cout << ret << endl;
  }
}
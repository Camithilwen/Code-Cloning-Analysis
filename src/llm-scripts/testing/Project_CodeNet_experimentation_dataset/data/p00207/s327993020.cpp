#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<30;

typedef pair<int,int> pii;

int w,h;
int xs, ys, xg, yg;
int ba[100][100];

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

bool solve() {
  queue<pii> Q;
  bool visited[w][h];
  memset(visited, 0, sizeof(visited));
  Q.push(pii(xs,ys));
  int col = ba[xs][ys];
  while(Q.size()){
    pii a = Q.front();
    int x = a.first, y = a.second;
    Q.pop();
//    printf("%d %d   %d\n", x,y, visited[x][y]);
    visited[x][y] = 1;
    REP(k,4) {
      int xx = x + dx[k];
      int yy = y + dy[k];
      //    cout << " " <<x << endl;
      if (xx<0 || w<=xx || yy<0 || h<=yy) continue;
      if (visited[xx][yy]) continue;
      if (col != ba[xx][yy]) continue;
      
      if (xx == xg && yy == yg)
        return true;
      //cout << xx << ". " << yy << endl;
      Q.push(pii(xx,yy));
    }
  }
  return false;
}

int main() {
  while(cin>>w>>h,w+h) {
    cin >>xs>>ys>>xg>>yg;
    xs--;ys--;xg--;yg--;
    int n;
    cin >> n;
    REP(i,n) {
      int c,d,x,y;
      cin >> c>>d>>x>>y;
      x--;y--;
      REP(i,8) {
        if (d==0)
          ba[x+i%4][y+i/4] = c;
        else
          ba[x+i/4][y+i%4] = c;
      }
    }
    // REP(y,h) {
    //   REP(x,w)
    //     cout << ba[x][y] << " ";
    //   cout << endl;
    // }
    if (solve())
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
}
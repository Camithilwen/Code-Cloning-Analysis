#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <stack>
#include <list>

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,b,n) for(int i=b;i<n;i++)
#define SORT(c) sort((c).begin(),(c).end())
#define DESCSORT(c) sort(c.begin(), c.end(), greater<int>())

const float PI = 3.1415926;
static const int INFTY = (1<<30);

using namespace std;

int B[102][102];
int M[102][102];
int w, h, xs, ys, xg, yg, n, res;
 
void bfs(int x, int y, int c) {
  if(x <= 0 || y <= 0 || x > w+1 || y > h+1)
    return;
  if(B[x][y] != c)
    return;
  if(M[x][y] == 1) {
    return;
  } else {
    M[x][y] = 1;
  }
  if(x == xg && y == yg) {
    res = 1;
    return; 
  }
  bfs(x+1, y, c);
  bfs(x, y+1, c);
  bfs(x-1, y, c);
  bfs(x, y-1, c);
}

int main() {
  while(cin >> w >> h, w) {
    // ?????????
    rep(i, w+1) {
      rep(j, h+1) {
        B[i][j] = 0;
        M[i][j] = 0;
      }
    }
    res = 0;
    cin >> xs >> ys;
    cin >> xg >> yg;
    cin >> n;
    // ??????????????????
    rep(i, n) {
      int c, d, x, y;
      cin >> c >> d >> x >> y;
      
      B[x][y] = c;
      B[x+1][y] = c;
      B[x][y+1] = c;
      B[x+1][y+1] = c;
      if ( d == 0 ) {
        B[x+2][y] = c;
        B[x+3][y] = c;
        B[x+2][y+1] = c;
        B[x+3][y+1] = c;
      } else {
        B[x][y+2] = c;
        B[x][y+3] = c;
        B[x+1][y+2] = c;
        B[x+1][y+3] = c;
      }        
    }
    if(B[xs][ys] != 0)
      bfs(xs, ys, B[xs][ys]);
    if(res)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  
  return 0;
}
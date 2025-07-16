#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

int ba[12][12];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
void dfs(int x,int y) {
  REP(i,4) {
    int xx = x+dx[i];
    int yy = y+dy[i];
    if (xx<0||xx>=12||yy<0||yy>=12) continue;
    if (ba[xx][yy]) {
      ba[xx][yy] = 0;
      dfs(xx,yy);
    }
  }
}

int main() {
  char b;
  while(cin >> b) {
    ba[0][0] = b-'0';
    REP(i,12) {
      REP(j,12) {
        if (i==0&&j==0)continue;
        char a;
        cin >> a;
        ba[j][i] = a-'0';
      }
    }
    int ans = 0;
    REP(i,12) {
      REP(j,12) {
        if (ba[i][j]) {
          ans++;
          dfs(i,j);
        }
      }
    }
    cout << ans << endl;
  }
}
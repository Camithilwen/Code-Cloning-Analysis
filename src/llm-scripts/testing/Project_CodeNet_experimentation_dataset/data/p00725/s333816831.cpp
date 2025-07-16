#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef pair<int,int> P;
int w,h;
int grid[21][21];
P start,goal;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool isvalid(int x,int y){
  return (x>=0&&x<w&&y>=0&&y<h);
}
int dfs(P p, int t){
  if(p == goal) return t;
  if(t > 10) return t;
  int ret = 100;
  int x = p.first;
  int y = p.second;
  REP(r,4){
    int nx = x + dx[r];
    int ny = y + dy[r];
    if(isvalid(nx,ny) && grid[ny][nx] != 1){
      while(isvalid(nx,ny)){
        if(grid[ny][nx] == 3 ||
            (isvalid(nx+dx[r],ny+dy[r]) && grid[ny+dy[r]][nx+dx[r]] == 1)){
          if(grid[ny][nx] != 3) grid[ny+dy[r]][nx+dx[r]] = 0;
          ret = min(ret,dfs(P(nx,ny),t+1));
          if(grid[ny][nx] != 3) grid[ny+dy[r]][nx+dx[r]] = 1;
          break;
        }
        nx += dx[r];
        ny += dy[r];
      }
    }
  }
  return ret;
}
int main(){
  while(cin>>w>>h,w){
    REP(y,h)REP(x,w){
      cin>>grid[y][x];
      if(grid[y][x]==2){
        start = P(x,y);
      }
      if(grid[y][x]==3){
        goal = P(x,y);
      }
    }
    int ans = dfs(start,0);
    if(ans > 10) ans = -1;
    cout<<ans<<endl;
  }
  return 0;
}
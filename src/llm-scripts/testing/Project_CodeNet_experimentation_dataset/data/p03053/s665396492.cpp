#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> hw(h);
  for(int i=0; i<h; ++i) cin >> hw[i];
  queue<P> que;
  vector<vector<int>> dis(h, vector<int>(w, -1));
  for(int i=0; i<h; ++i) for(int j=0; j<w; ++j){
    if(hw[i][j] == '#'){
      que.push(make_pair(i,j));
      dis[i][j] = 0;
    }
  }
  int ans = 0;
  while(!que.empty()){
    int x, y;
    tie(x,y) = que.front();
    que.pop();
    if(x>0 && dis[x-1][y] == -1){
      dis[x-1][y] = dis[x][y] + 1;
      ans = max(ans, dis[x-1][y]);
      que.push(make_pair(x-1,y));
    }
    if(x<h-1 && dis[x+1][y] == -1){
      dis[x+1][y] = dis[x][y] + 1;
      ans = max(ans, dis[x+1][y]);
      que.push(make_pair(x+1,y));
    }
    if(y>0 && dis[x][y-1] == -1){
      dis[x][y-1] = dis[x][y] + 1;
      ans = max(ans, dis[x][y-1]);
      que.push(make_pair(x,y-1));
    }
    if(y<w-1 && dis[x][y+1] == -1){
      dis[x][y+1] = dis[x][y] + 1;
      ans = max(ans, dis[x][y+1]);
      que.push(make_pair(x,y+1));
    }
  }
  cout << ans << endl;
}
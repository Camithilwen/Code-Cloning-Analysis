#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for(int i = 0; i < h; i++) cin >> a.at(i);
  
  vector<vector<int>> check(h, vector<int>(w));
  int ans = -1;
  queue<pair<int, int>> bfs;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(a.at(i).at(j) == '.') continue;
      bfs.push({i, j});
      check.at(i).at(j) = 1;
    }
  }
  vector<int> dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};
  while(bfs.size() > 0){
    ans++;
    queue<pair<int, int>> next;
    while(bfs.size() > 0){
      next.push(bfs.front());
      bfs.pop();
    }
    while(next.size() > 0){
      int y = next.front().first, x = next.front().second;
      next.pop();
      for(int i = 0; i < 4; i++){
        int nx = x + dx.at(i), ny = y + dy.at(i);
        if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
        if(check.at(ny).at(nx)) continue;
        check.at(ny).at(nx) = 1;
        bfs.push({ny, nx});
      }
    }
  }
  
  cout << ans << endl;
}
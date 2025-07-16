#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> g(h);
  vector<vector<bool>> seen(h, vector<bool>(w));
  for(int i=0;i<h;i++) cin >> g[i];
  long long ans = 0;
  long long black = 0, white = 0;
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      if(seen[i][j]) continue;
      queue<P> que;
      que.emplace(make_pair(i, j));
      while(!que.empty()) {
        P p = que.front();que.pop();
        if(seen[p.first][p.second]) continue;
        seen[p.first][p.second] = true;
        char c = g[p.first][p.second];
        if(c == '.') white++;
        else black++;
        if(p.first != 0 && !seen[p.first-1][p.second] && g[p.first-1][p.second] != c) que.emplace(make_pair(p.first-1, p.second));
        if(p.first != h-1 && !seen[p.first+1][p.second] && g[p.first+1][p.second] != c) que.emplace(make_pair(p.first+1, p.second));
        if(p.second != 0 && !seen[p.first][p.second-1] && g[p.first][p.second-1] != c) que.emplace(make_pair(p.first, p.second-1));
        if(p.second != w-1 && !seen[p.first][p.second+1] && g[p.first][p.second+1] != c) que.emplace(make_pair(p.first, p.second+1));
      }
      ans += black * white;
      black = white = 0;
    }
  }
  cout << ans << endl;
}


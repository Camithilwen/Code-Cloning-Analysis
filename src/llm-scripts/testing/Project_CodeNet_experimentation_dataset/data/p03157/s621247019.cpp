#include <bits/stdc++.h>
using namespace std;

int h, w;
string s[400];
int a[400][400];
int b = 0;
pair<int, int> dyx[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int y, int x) {
  queue<pair<int,int>> q;
  q.push(make_pair(y, x));
  a[y][x] = b;
  while (!q.empty()) {
    int x, y;
    tie(y, x) = q.front();
    q.pop();
    for (auto d: dyx) {
      int ny = y + d.first;
      int nx = x + d.second;
      if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
        continue;
      }
      if (a[ny][nx] > -1) {
        continue;
      }
      if (s[y][x] != s[ny][nx]) {
        a[ny][nx] = b;
        q.push(make_pair(ny, nx));
      }
    }
  }
}
int main() {
  cin>>h>>w;
  for (int i=0; i<h; i++) cin>>s[i];
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      a[i][j] = -1;
    }
  }
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (a[i][j] == -1) {
        bfs(i, j);
        ++b;
      }
    }
  }
  map<int, pair<int,int>> cnt;
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (s[i][j] == '#') {
        ++cnt[a[i][j]].first;
      } else {
        ++cnt[a[i][j]].second;
      }
    }
  }
  long long ans = 0;
  for (auto e: cnt) {
    ans += 1LL * e.second.first * e.second.second;
  }
  cout<<ans<<endl;
}
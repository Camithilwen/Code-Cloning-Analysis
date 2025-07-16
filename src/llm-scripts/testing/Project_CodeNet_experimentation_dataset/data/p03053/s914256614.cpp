#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  vector<vector<int>> d(h, vector<int>(w, -1));
  queue<P> que;
  rep(i, h) rep(j, w) {
    if (a[i][j] == '.') continue;
    d[i][j] = 0;
    que.push(make_pair(i, j));
  }

  while (que.size()) {
    P p = que.front();
    que.pop();
    rep(i, 4) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if (d[nx][ny] != -1) continue;
      d[nx][ny] = d[p.first][p.second] + 1;
      que.push(make_pair(nx, ny));
    }
  }

  int ans = 0;
  rep(i, h) rep(j, w) ans = max(ans, d[i][j]);
  cout << ans << endl;
  return 0;
}
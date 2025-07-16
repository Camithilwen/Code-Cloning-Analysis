#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> a(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    string foo;
    cin >> foo;
    for (int j = 0; j < m; j++) {
      a[i][j] = foo[j] == '#';
    }
  }
  queue<pair<int, int>> que;
  vector<vector<int>> dist(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j]) {
        que.push({i, j});
        dist[i][j] = 0;
      }
    }
  }
  while (!que.empty()) {
    auto u = que.front();
    que.pop();
    int x = u.first, y = u.second;
    for (int i = 0; i < 4; i++) {
      int tx = x + dx[i], ty = y + dy[i];
      if (0 <= tx && tx < n && 0 <= ty && ty < m && dist[tx][ty] == -1) {
        dist[tx][ty] = dist[x][y] + 1;
        que.push({tx, ty});
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans = max(ans, dist[i][j]);
    }
  }
  cout << ans << '\n';
  return 0; // :)
}

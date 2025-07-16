#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<char>> G;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

long long bfs(int sx, int sy, vector<vector<bool>> &vis, G &g) {
  int h = g.size();
  int w = g[0].size();

  queue<pair<int, int>> que;
  que.push(make_pair(sx, sy));
  vis[sy][sx] = true;

  long long cnt_w = 0, cnt_b = 0;

  while (!que.empty()) {
    auto cur = que.front();
    que.pop();

    int cur_x = cur.first;
    int cur_y = cur.second;

    if (g[cur_y][cur_x] == '#') {
      cnt_b++;
    } else {
      cnt_w++;
    }

    for (int i = 0; i < 4; i++) {
      int nx = cur_x + dx[i];
      int ny = cur_y + dy[i];

      if (nx < 0 || ny < 0 || nx >= w || ny >= h) {
        continue;
      }
      if (vis[ny][nx]) {
        continue;
      }
      if (g[cur_y][cur_x] == g[ny][nx]) {
        continue;
      }
      vis[ny][nx] = true;
      que.push(make_pair(nx, ny));
    }
  }
  return cnt_b * cnt_w;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));

  for (int y = 0; y < h; y++) {
    string tmp_s;
    cin >> tmp_s;
    for (int x = 0; x < w; x++) {
      grid[y][x] = tmp_s[x];
    }
  }

  long long ans = 0;
  vector<vector<bool>> is_visited(h, vector<bool>(w, false));
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      if (!is_visited[y][x]) {
        ans += bfs(x, y, is_visited, grid);
      }
    }
  }
  cout << ans << "\n";

  return 0;
}
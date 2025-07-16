#include <algorithm>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define debug(s, param) std::cerr << s << param << std::endl;

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int bfs(const vector<string>& grids, int h, int w) {
  vector<vector<int>> deltas{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<vector<bool>> visit(h, vector<bool>(w, false));
  queue<pair<int, int>> q;
  auto isAvailable = [h, w](int row, int col) { return (row >= 0 && row < h && col >= 0 && col < w); };
  q.emplace(0, 0);
  visit[0][0] = true;
  int steps = 0;
  while (!q.empty()) {
    int size = (int)q.size();
    rep (i, size) {
      int row = q.front().first, col = q.front().second;
      if (row == h - 1 && col == w - 1) return steps;
      q.pop();
      for (const auto& delta : deltas) {
        int nextRow = row + delta[0], nextCol = col + delta[1];
        if (isAvailable(nextRow, nextCol) && grids[nextRow][nextCol] == '.' && !visit[nextRow][nextCol]) {
          visit[nextRow][nextCol] = true;
          q.emplace(nextRow, nextCol);
        }
      }
    }
    ++steps;
  }
  return -1;
}

int main() {
  int h, w;
  cin >> h >> w;
  int blackNums = 0;
  vector<string> grids(h, "");
  rep (i, h) {
    cin >> grids[i];
    rep (j, w) if (grids[i][j] == '#') ++blackNums;
  }
  int res = bfs(grids, h, w);
  if (res == -1) cout << -1 << endl;
  else  cout << h * w - (blackNums + res + 1) << endl;
  return 0;
}
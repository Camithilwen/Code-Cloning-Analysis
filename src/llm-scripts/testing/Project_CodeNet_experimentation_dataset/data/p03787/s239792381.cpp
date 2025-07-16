#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <array>

using namespace std;

vector<vector<int>> graph;
vector<int> colors;
vector<bool> used;

bool Dfs(int v, int col, int* sz) {
  used[v] = true;
  colors[v] = col;
  (*sz)++;
  bool ans = false;
  for (const auto& to : graph[v]) {
    if (!used[to]) {
      if (Dfs(to, 1 - col, sz)) {
        ans = true;
      }
    } else {
      if (colors[to] == col) {
        ans = true;
      }
    }
  }
  return ans;
}

int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  graph.resize(n);
  colors.resize(n);
  used.resize(n);

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  std::array<int64_t, 2> arr{};
  int64_t one = 0;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      int sz = 0;
      if (Dfs(i, 0, &sz)) {
        arr[0]++;
      } else if (sz == 1) {
        one++;
      } else {
        arr[1]++;
      }
    }
  }
  int64_t ans = one * 1ll * n * 2 - one * one;
  cout << arr[0] * arr[0] + 2 * arr[0] * arr[1] + 2 * arr[1] * arr[1] + ans  << endl;
}
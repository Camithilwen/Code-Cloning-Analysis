#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dis[2][N];
vector<int> g[N];

void bfs(int be, int id) {
  queue<int> q;
  q.push(be);
  dis[id][be] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : g[u]) {
      if (!dis[id][v]) {
        dis[id][v] = dis[id][u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  int n, x, y, u, v, res = 0;
  cin >> n >> x >> y;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bfs(x, 0);
  bfs(y, 1);
  for (int i = 1; i <= n; i++) {
    if (dis[0][i] < dis[1][i]) res = max(res, dis[1][i] - 2);
  }
  cout << res << endl;
  return 0;
}

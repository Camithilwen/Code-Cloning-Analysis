#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m, n | m) {
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
      int a, b; cin >> a >> b; --a; --b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    vector<int> dist(n, 3);
    queue<int> Q;
    Q.push(0);
    dist[0] = 0;
    while (!Q.empty()) {
      int v = Q.front(); Q.pop();
      for (int w : graph[v]) {
        if (dist[w] == 3) {
          dist[w] = dist[v] + 1;
          Q.push({w});
        }
      }
    }
    int ans = 0;
    for (int d : dist)
      if (d < 3) ++ans;
    cout << ans - 1 << endl;
  }
}
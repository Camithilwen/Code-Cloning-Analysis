#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int n, u, v;
  cin >> n >> u >> v;
  vector<int> graph[n];
  for (int a, b; cin >> a >> b; ) {
    graph[a - 1].emplace_back(b - 1);
    graph[b - 1].emplace_back(a - 1);
  }
  int takahashi[n], aoki[n], parent[n], result = 0;
  auto bfs = [&](int start, int* distance) {
    queue<int> q;
    q.emplace(start);
    distance[start] = 0;
    vector<bool> visited(n);
    visited[start] = true;
    parent[start] = start;
    do {
      for (auto next : graph[q.front()]) {
        if (!visited[next]) {
          parent[next] = q.front();
          distance[next] = distance[q.front()] + 1;
          visited[next] = true;
          q.emplace(next);
        }
      }
      q.pop();
    } while (!q.empty());
  };
  bfs(u - 1, takahashi);
  bfs(v - 1, aoki);
  if (aoki[u - 1] != 1) {
    for (int i = 0; i < n; ++i) {
      if (takahashi[i] <= aoki[i]) {
        result = max(result, aoki[parent[parent[i]]] + 1);
      }
    }
  }
  cout << result;
  return 0;
}

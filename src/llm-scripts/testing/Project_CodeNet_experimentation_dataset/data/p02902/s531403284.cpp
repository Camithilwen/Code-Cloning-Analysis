#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> G[1010];
bool H[1010][1010];
bool visited[1010];

vector<int> path;
vector<int> cycle;

void dfs(int v) {
  visited[v] = true;
  path.push_back(v);
  for (int u : G[v]) {
    if (!cycle.empty()) continue;
    if (find(path.begin(), path.end(), u) != path.end()) {
      cycle = path;
      return;
    } else {
      dfs(u);
    }
  }
  path.pop_back();
}

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    H[a][b] = true;
  }

  for (int i = 0; i < N; i++) {
    if (visited[i]) continue;
    path.clear();
    dfs(i);
    if (cycle.size() > 0) {
      while (!H[cycle[cycle.size() - 1]][cycle[0]]) cycle.erase(cycle.begin());
      bool f = true;
      while (f) {
        f = false;
        bool used[1010] = {};
        for (int u : cycle) used[u] = true;

        int from, to;
        for (int i = 0; i < cycle.size(); i++) {
          int v = cycle[i];
          for (int u = 0; u < N; u++) {
            if (!used[u]) continue;
            if (u == v) continue;
            if (u == cycle[(i + 1) % cycle.size()]) continue;
            if (H[v][u]) {
              f = true;
              from = v, to = u;
              break;
            }
          }
        }

        if (f) {
          vector<int> tmp;
          tmp.push_back(from);
          while (to != tmp[0]) {
            tmp.push_back(to);
            for (int u : G[to]) {
              if (used[u] && H[to][u]) {
                to = u;
                break;
              }
            }
          }
          cycle = tmp;
        }
      }
      cout << cycle.size() << endl;
      for (int v : cycle) {
        cout << v + 1 << endl;
      }
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}
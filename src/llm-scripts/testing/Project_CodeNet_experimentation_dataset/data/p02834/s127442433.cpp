#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

void dfs(vector<vector<int>>& G, int u, vector<int>& dist) {
  for (auto v : G[u]) {
    if (dist[v] != -1) continue;
    dist[v] = dist[u] + 1;
    dfs(G, v, dist);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  int N, u, v;
  cin >> N >> u >> v;
  --u, --v;

  vector<vector<int>> G(N);
  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  vector<int> distT(N, -1);
  distT[u] = 0;
  dfs(G, u, distT);

  vector<int> distA(N, -1);
  distA[v] = 0;
  dfs(G, v, distA);

  int answer = 0;
  rep(i, N) {
    if (distT[i] < distA[i]) {
      answer = max(answer, distA[i] - 1);
    }
  }
  cout << answer << endl;
  return 0;
}

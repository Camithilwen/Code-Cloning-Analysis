// Graph: Adjacency list
#include<vector>
typedef std::vector<std::vector<int>> Graph;
// Utility
const Graph reverse(const Graph& g) {
  Graph result(g.size());
  for(int u = 0; u < g.size(); ++u) for(auto v: g.at(u)) result.at(v).push_back(u);
  return result;
}
void postorder_dfs(const Graph& g, int current, std::vector<bool>& visited, std::vector<int>& result) {
  visited.at(current) = true;
  for(auto next: g.at(current)) if(!visited.at(next)) postorder_dfs(g, next, visited, result);
  result.push_back(current);
}
std::vector<int> postorder(const Graph& g) {
  std::vector<bool> visited(g.size(), false);
  std::vector<int> result;
  for(int v = 0; v < g.size(); ++v) if(!visited[v]) postorder_dfs(g, v, visited, result);
  return result;
}
// Strongly Connected Components: Kosaraju's algorithm O(V + E)
void scc_dfs(const Graph& g, int current, int group, std::vector<bool>& visited, std::vector<int>& result) {
  visited.at(current) = true;
  result.at(current) = group;
  for(auto next: g.at(current)) if(!visited.at(next)) scc_dfs(g, next, group, visited, result);
}
std::vector<int> scc(const Graph& g) {
  auto order = postorder(g);
  auto rg = reverse(g);
  std::vector<bool> visited(g.size(), false);
  std::vector<int> result(g.size());
  int group = 0;
  for(auto v = order.rbegin(); v != order.rend(); ++v) if(!visited.at(*v)) scc_dfs(rg, *v, group++, visited, result);
  return result;
}

#include<bits/stdc++.h>
using namespace std;
int main() {
  int V, E;
  cin >> V >> E;

  Graph g(V);
  for(int i = 0; i < E; ++i) {
    int s, t;
    cin >> s >> t;
    g[s].push_back(t);
  }

  auto group = scc(g);

  int Q;
  cin >> Q;
  for(int i = 0; i < Q; ++i) {
    int u, v;
    cin >> u >> v;
    cout << (group[u] == group[v] ? 1 : 0) << endl;
  }
}
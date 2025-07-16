#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

struct Edge {
  int from, to;
};

vector<vector<Edge>> ReadDirectedGraph(
    int n, int m, bool is_one_indexed=false) {
  vector<vector<Edge>> graph(n);
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    if (is_one_indexed) {
      v1--;
      v2--;
    }
    graph[v1].push_back(Edge({v1, v2}));
  }
  return graph;
}

vector<int> StronglyConnectedComponents(const vector<vector<Edge>>& graph) {
  int n = graph.size();
  vector<int> vs;
  vector<int> visited1(n);
  function<void(int)> dfs1 = [&](int v) {
    if (visited1[v]) return;
    visited1[v] = 1;
    for (const auto& e : graph[v]) dfs1(e.to);
    vs.push_back(v);
  };
  for (int v = 0; v < n; v++) dfs1(v);
  reverse(vs.begin(), vs.end());

  vector<vector<Edge>> r_graph(n);
  for (int v = 0; v < n; v++) {
    for (const auto& e : graph[v]) {
      r_graph[e.to].push_back(Edge({e.to, e.from}));
    }
  }

  vector<int> to_id(n);
  int current_id = 0;
  vector<int> visited2(n);
  function<void(int)> dfs2 = [&](int v) {
    if (visited2[v]) return;
    visited2[v] = 1;
    to_id[v] = current_id;
    for (const auto& e : r_graph[v]) dfs2(e.to);
  };
  for (int v : vs) {
    if (!visited2[v]) {
      dfs2(v);
      current_id++;
    }
  }
  return to_id;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  auto graph = ReadDirectedGraph(n, m, false);
  auto to_scc_id = StronglyConnectedComponents(graph);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    if (to_scc_id[v1] == to_scc_id[v2]) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
}


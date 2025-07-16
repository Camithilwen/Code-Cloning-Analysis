#include <bits/stdc++.h>
using namespace std;

template <typename Graph>
struct StronglyConnectedComponents {
  Graph &g;
  int n;
  vector<vector<int>> gg;
  vector<vector<int>> rg;
  vector<bool> used;
  vector<int> order;
  vector<int> comp;
  StronglyConnectedComponents(Graph &g)
    : g(g), n(g.n), gg(n), rg(n), used(n), order(n), comp(n, -1) {
    for (int v = 0; v < n; v++) {
      for (auto e : g[v]) {
        gg[v].emplace_back(e.to);
        rg[e.to].emplace_back(v);
      }
    }
  }
  void dfs1(int v) {
    if (used[v]) return;
    used[v] = true;
    for (int u : gg[v]) dfs1(u);
    order.push_back(v);
  }
  void dfs2(int v, int c) {
    if (comp[v] != -1) return;
    comp[v] = c;
    for (int u : rg[v]) dfs2(u, c);
  }
  vector<int> build() {
    for (int i = 0; i < n; i++) {
      dfs1(i);
    }
    reverse(order.begin(), order.end());
    int ptr = 0;
    for (int v : order) {
      if (comp[v] == -1) dfs2(v, ptr), ptr++;
    }
    return comp;
  }
};

struct UnWeightedGraph {
  struct Edge {
    int to;
    Edge(int to) : to(to) {}
  };
  vector<vector<Edge>> edges;
  int n;
  UnWeightedGraph(int n) : n(n) {
    edges.assign(n, vector<Edge>());
  }
  void add_edge(int v, int u) {
    edges[v].emplace_back(u);
  }
  vector<Edge> &operator[](int x) {
    return edges[x];
  }
};

int main() {
  int V, E; cin >> V >> E;
  auto graph = UnWeightedGraph(V);
  for (int i = 0; i < E; i++) {
    int s, t; cin >> s >> t;
    graph.add_edge(s, t);
  }
  auto scc = StronglyConnectedComponents<UnWeightedGraph>(graph);
  auto ans = scc.build();
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int v, u; cin >> v >> u;
    cout << (ans[v] ==  ans[u]) << '\n';
  }
  return 0;
}


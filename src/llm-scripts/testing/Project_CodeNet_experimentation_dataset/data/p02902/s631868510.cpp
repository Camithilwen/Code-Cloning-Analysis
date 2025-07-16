#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

std::vector<std::vector<int>> StronglyConnectedComponents(
    const std::vector<std::vector<int>>& graph) {
  int n = graph.size();
  std::vector<int> nodes;
  std::vector<bool> visited(n);
  std::function<void(int)> dfs = [&](int u) {
    visited[u] = true;
    for (int v : graph[u]) {
      if (!visited[v]) {
        dfs(v);
      }
    }
    nodes.push_back(u);
  };
  for (int u = 0; u < n; ++u) {
    if (!visited[u]) dfs(u);
  }
  std::vector<std::vector<int>> rgraph(n);
  for (int u = 0; u < n; ++u) {
    for (int v : graph[u]) {
      rgraph[v].push_back(u);
    }
  }
  std::vector<bool> rvisited(n);
  std::vector<std::vector<int>> sccs;
  std::function<void(std::vector<int>&, int)> rdfs = [&](std::vector<int>& scc,
                                                         int u) {
    rvisited[u] = true;
    scc.push_back(u);
    for (int v : rgraph[u]) {
      if (!rvisited[v]) {
        rdfs(scc, v);
      }
    }
  };
  for (int i = n - 1; i >= 0; --i) {
    int u = nodes[i];
    if (!rvisited[u]) {
      std::vector<int> scc;
      rdfs(scc, u);
      sccs.push_back(scc);
    }
  }
  return sccs;
}

int main() {
  in(int, n, m);
  vector<vector<int>> graph(n);
  rep(i, m) {
    in(int, a, b);
    graph[a - 1].push_back(b - 1);
  }
  vector<vector<int>> sccs = StronglyConnectedComponents(graph);
  for (const vector<int>& scc : sccs) {
    if (scc.size() == 1) continue;
    set<int> scc_nodes(all(scc));
    int node = scc[0];
    map<int, int> next;
    map<int, int> prev;
    for (int n : scc_nodes) dbg(n);
    while (true) {
      for (int child : graph[node]) {
        if (scc_nodes.count(child) == 0) continue;
        next[node] = child;
        prev[child] = node;
        if (next.count(child) != 0) goto out;
        node = child;
        break;
      }
    }
 out:
    node = scc[0];
    if (prev.count(node) == 0) {
      while (true) {
        int child = next[node];
        next.erase(node);
        if (prev[child] != node) break;
        prev.erase(child);
        node = child;
      }
    }
    rep(u, n) for (int v : graph[u]) {
      if (next.count(u) > 0 && next.count(v) > 0) {
        int c = next[u];
        while (c != v) {
          int nc = next[c];
          next.erase(c);
          prev.erase(c);
          c = nc;
        }
        next[u] = v;
        prev[v] = u;
      }
    }
    vector<int> v;
    int u = next.begin()->first;
    do {
      v.push_back(u);
      u = next[u];
    } while (u != next.begin()->first);
    out(v.size());
    for (int u : v) out(u + 1);
    return 0;
  }
  out(-1);
}

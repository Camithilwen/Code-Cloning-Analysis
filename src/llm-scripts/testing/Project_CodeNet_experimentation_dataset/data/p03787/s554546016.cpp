#include<bits/stdc++.h>
using namespace std;

using Weight = long long;
using Vertex = int;
struct Edge {Vertex from, to; Weight weight;};
using Graph = std::vector<std::vector<Edge>>;

std::vector<std::vector<Vertex>> connected_component(const Graph& G) {
  std::vector<std::vector<Vertex>> cc;
  std::vector<bool> used(G.size());
  std::function<void(int)> dfs = [&](int v) {
    cc.back().push_back(v);
    used[v] = true;
    for(const auto& e: G[v]) if(!used[e.to]) dfs(e.to);
  };
  for(Vertex v = 0; v < G.size(); ++v) if(!used[v]) {
    cc.push_back(std::vector<Vertex>());
    dfs(v);
  }
  return cc;
}

using I = long long;

I com2(I n) {return n * (n - 1) / 2;}

bool check(const auto& G, auto s) {
  vector<int> color(G.size(), -1);
  function<bool(Vertex, int)> dfs = [&](auto v, auto c) {
    if(color[v] != -1) return color[v] == c;
    color[v] = c;
    c ^= 1;
    for(const auto& e: G[v]) if(!dfs(e.to, c)) return false;
    return true;
  };
  return dfs(s, 0);
}

int main() {
  I N, M;
  cin >> N >> M;
  Graph G(N);
  for(auto i=0; i<M; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    G[u].push_back({u, v});
    G[v].push_back({v, u});
  }

  auto cc = connected_component(G);
  auto V = N - count_if(begin(cc), end(cc), [](const auto& v) {return v.size() == 1;});
  auto ans = N * N - V * V;
  I twocol = 0, obscure = 0;
  for(auto c: cc) if(c.size() != 1) {
    if(check(G, *begin(c))) ++twocol;
    else                    ++obscure;
  }
  ans += 2 * twocol + obscure;
  ans += 4 * com2(twocol) + 2 * com2(obscure);
  ans += 2 * twocol * obscure;
  cout << ans << endl;
}

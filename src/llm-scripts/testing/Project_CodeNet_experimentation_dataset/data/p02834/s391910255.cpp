#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

template< typename T = int >
struct Edge {
  int from, to;
  T cost;
  int idx;

  Edge() = default;

  Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

  operator int() const { return to; }
};

template< typename T = int >
struct Graph {
  vector< vector< Edge< T > > > g;
  int es;

  Graph() = default;

  explicit Graph(int n) : g(n), es(0) {}

  size_t size() const {
    return g.size();
  }

  void add_directed_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es++);
  }

  void add_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es);
    g[to].emplace_back(to, from, cost, es++);
  }

  void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
    for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1);
      if(weighted) cin >> c;
      if(directed) add_directed_edge(a, b, c);
      else add_edge(a, b, c);
    }
  }
};

/**
 * @brief BFS(幅優先探索)
 */
template< typename T >
vector< T > bfs(const Graph< T > &g, int s) {
  T max_cost = 0, beet = 0;
  for(auto &es : g.g) {
    for(auto &e : es) max_cost = max(max_cost, e.cost);
  }
  ++max_cost;
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);
  vector< queue< int > > ques(max_cost + 1);
  dist[s] = 0;
  ques[0].emplace(s);
  for(T cost = 0; cost <= beet; cost++) {
    auto &que = ques[cost % max_cost];
    while(!que.empty()) {
      int idx = que.front();
      que.pop();
      if(dist[idx] < cost) continue;
      for(auto &e : g.g[idx]) {
        auto next_cost = cost + e.cost;
        if(dist[e.to] <= next_cost) continue;;
        dist[e.to] = next_cost;
        beet = max(beet, dist[e.to]);
        ques[dist[e.to] % max_cost].emplace(e.to);
      }
    }
  }
  return dist;
}


int main(){
    int n,u,v;
    cin >> n >> u >> v;
    u--;v--;
    Graph<int> g(n);
    g.read(n-1,-1,false,false);
    auto dista = bfs(g,v);
    auto distt = bfs(g,u);
    int M = 0;
    rep(i,n){
        if(dista[i]>distt[i])chmax(M,dista[i]);
    }
    cout << M-1 << endl;
    return 0;
}

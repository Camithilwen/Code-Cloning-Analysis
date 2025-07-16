#include <iostream>
#include <vector>
#include <stack>
#include <bitset>
#include <utility>
#include <algorithm>

using namespace std;

const int kNil = -1;
const int kMaxV = 100010;

enum class Color {
  kWhite,
  kGrey,
  kBlack,
};

template <class T>
struct Edge {
  using w_type = T;
  Edge(int u, int v, w_type w): u(u), v(v), w(w) { }
  int u, v;
  w_type w;
  bool operator<(const Edge<T> & rhs) const {
    if (w != rhs.w) { return w < rhs.w; }
    if (u != rhs.u) { return u < rhs.u; }
    return v < rhs.v;
  }
};

template <class Edge>
void ArticulationPointsVisit(
    const typename vector<Edge>::size_type node_now,
    typename vector<Edge>::size_type & time,
    const vector<vector<Edge>> & adjacency_list,
    vector<int> & d,
    vector<int> & low,
    vector<Color> & color,
    vector<int> & parent,
    bitset<kMaxV> & bs_aps) {
  color[node_now] = Color::kGrey;
  d[node_now] = time;
  low[node_now] = time++;
  unsigned child_num = 0;
  for (const auto & e: adjacency_list[node_now]) {
    if (color[e.v] == Color::kWhite) {
      ++child_num;
      parent[e.v] = e.u;
      ArticulationPointsVisit(e.v, time, adjacency_list, d, low, color, parent, bs_aps);
      low[e.u] = min(low[e.u], low[e.v]);

      if (parent[e.u] == kNil && child_num >= 2) {
        bs_aps.set(e.u);
      }
      if (parent[e.u] != kNil && d[e.u] <= low[e.v]) {
        bs_aps.set(e.u);
      }
    } else if (parent[e.u] != e.v) {
      low[e.u] = min(low[e.u], d[e.v]);
    }
  }
  color[node_now] = Color::kBlack;
}

template <class Edge>
bitset<kMaxV> ArticulationPoints(const vector<Edge> & edges,
                 typename vector<Edge>::size_type node_num) {
  using size_type = typename vector<Edge>::size_type;

  vector<vector<Edge>> adjacency_list(node_num, vector<Edge>());
  for (const auto & e: edges) {
    adjacency_list[e.u].push_back(e);
    adjacency_list[e.v].emplace_back(e.v, e.u, e.w);
  }

  size_type time = 0;
  vector<int> d(node_num);
  vector<int> low(node_num);
  vector<Color> color(node_num, Color::kWhite);
  vector<int> parent(node_num, kNil);
  bitset<kMaxV> bs_aps;

  for (unsigned i = 0; i < node_num; ++i) {
    if (color[i] == Color::kWhite) {
      ArticulationPointsVisit(i, time, adjacency_list, d, low, color, parent, bs_aps);
    }
  }

  return bs_aps;
}

int main(int argc, char const *argv[]) {
  using w_type = unsigned;

  vector<Edge<w_type>> edges;
  unsigned V, E;
  cin >> V >> E;
  for (unsigned i = 0; i < E; ++i) {
    unsigned u, v;
    w_type w;
    cin >> u >> v;
    edges.emplace_back(u, v, 1);
  }

  auto bs_aps = ArticulationPoints(edges, V);
  for (unsigned i = 0; i < V; ++i) {
    if (bs_aps.test(i)) {
      cout << i << endl;
    }
  }

  return 0;
}
// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define forever for (;;)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
template<typename A> using V = std::vector<A>;
template<typename A> using F = std::function<A>;
template<typename A, typename B> using P = std::pair<A, B>;
using pii = P<int, int>;
using vi = V<int>;
using vd = V<double>;
using vs = V<std::string>;
using vpii = V<pii>;
using vvi = V<vi>;
using vvpii = V<vpii>;
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979;
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
constexpr bool odd(const int n) { return n & 1; }
constexpr bool even(const int n) { return ~n & 1; }
template<typename T> std::istream &operator>>(std::istream &is, std::vector<T> &v) { for (T &x : v) is >> x; return is; }
template<typename A, typename B> std::istream &operator>>(std::istream &is, std::pair<A, B> &p) { is >> p.first; is >> p.second; return is; }
using namespace std;
// clang-format on

using Weight = int;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(const int s = 0, const int d = 0, const Weight w = 0) : src(s), dst(d), weight(w) {}
};

using Edges = std::vector<Edge>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

class Graph {
  std::vector<Edges> g;
  using iterator = std::vector<Edges>::iterator;
  using const_iterator = std::vector<Edges>::const_iterator;

public:
  Graph(const int size = 0) : g(size) {}
  size_t size() const { return g.size(); }
  const Edges &operator[](const int i) const { return g[i]; }
  void addArc(const int src, const int dst, const Weight w = 1) { g[src].emplace_back(src, dst, w); }
  void addEdge(const int node1, const int node2, const Weight w = 1) {
    addArc(node1, node2, w);
    addArc(node2, node1, w);
  }
  iterator begin() { return g.begin(); }
  const_iterator begin() const { return g.begin(); }
  iterator end() { return g.end(); }
  const_iterator end() const { return g.end(); }
};

std::vector<int> kosaraju(const Graph &g) {
  int n = g.size(), m = 0;
  Graph rg(n);
  std::vector<int> stk, cmp(n, -1), added(n), visited(n), ord(n);
  for (auto &es : g) {
    for (auto &e : es) rg.addArc(e.dst, e.src, e.weight);
    m += es.size();
  }
  stk.resize(n + m);
  m = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i]) continue;
    int s = 0;
    stk[s++] = i;
    while (s != 0) {
      int v = stk[s - 1];
      visited[v] = true;
      bool pushed = false;
      for (auto &e : g[v]) {
        if (!visited[e.dst]) {
          stk[s++] = e.dst;
          pushed = true;
        }
      }
      if (pushed) continue;
      int t = stk[s - 1];
      if (!added[t]) {
        added[t] = true;
        ord[n - ++m] = t;
      }
      --s;
    }
  }
  int k = 0;
  for (int u : ord) {
    if (cmp[u] != -1) continue;
    int s = 0;
    stk[s++] = u;
    while (s != 0) {
      int v = stk[--s];
      cmp[v] = k;
      for (auto &e : rg[v]) {
        if (cmp[e.dst] == -1) stk[s++] = e.dst;
      }
    }
    ++k;
  }
  return cmp;
}

main {
  int n, m;
  cin >> n >> m;
  Graph g(n);
  while (m--) {
    int s, t;
    cin >> s >> t;
    g.addArc(s, t);
  }
  int q;
  cin >> q;
  vi scc = kosaraju(g);
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << (scc[u] == scc[v]) << endl;
  }
}
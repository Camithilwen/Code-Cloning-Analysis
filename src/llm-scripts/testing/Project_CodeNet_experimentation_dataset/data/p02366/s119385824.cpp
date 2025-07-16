// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979;
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
bool odd(const int &n) { return n & 1; }
bool even(const int &n) { return ~n & 1; }
template<typename T> int len(const T &v) { return v.size(); }
template<typename T = int> T in() { T x; cin >> x; return x; }
template<typename T = int> T in(T &&x) { T z(forward<T>(x)); cin >> z; return z; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &x : v) is >> x; return is; }
template<typename A, typename B> istream &operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second; }
template<typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v) { int n = v.size(); rep(i, n) os << v[i] << (i == n - 1 ? "" : "\n"); return os; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { int n = v.size(); rep(i, n) os << v[i] << (i == n - 1 ? "" : " "); return os; }
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << p.first << ' ' << p.second; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
// clang-format on

using Weight = int;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(const int &s = 0, const int &d = 0, const Weight &w = 0) : src(s), dst(d), weight(w) {}
};

using Edges = vector<Edge>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

class Graph {
  vector<Edges> g;

public:
  Graph(const int &size = 0) : g(size) {}
  size_t size() const { return g.size(); }
  const Edges &operator[](const int &i) const { return g[i]; }
  Edges &operator[](const int &i) { return g[i]; }
  void addArc(const int &src, const int &dst, const Weight &w = 1) { g[src].emplace_back(src, dst, w); }
  void addEdge(const int &node1, const int &node2, const Weight &w = 1) {
    addArc(node1, node2, w);
    addArc(node2, node1, w);
  }
  auto begin() { return g.begin(); }
  auto end() { return g.end(); }
};

template<typename T> vector<T> nub(const vector<T> &xs) {
  set<T> s(xs.begin(), xs.end());
  vector<T> ys(s.begin(), s.end());
  return ys;
}

vector<int> articulationPoints(const Graph &g) {
  int n = g.size(), id = 0;
  vector<int> ord(n), low(n), arts;
  function<void(int)> dfs = [&](int v) {
    low[v] = ord[v] = ++id;
    for (auto &e : g[v]) {
      int w = e.dst;
      if (ord[w] == 0) {
        dfs(w);
        cmin(low[v], low[w]);
        if (ord[v] == 1 && ord[w] != 2) arts.emplace_back(v);
        if (ord[v] != 1 && ord[v] <= low[w]) arts.emplace_back(v);
      } else {
        cmin(low[v], ord[w]);
      }
    }
  };
  rep(i, n) if (ord[i] == 0) id = 0, dfs(i);
  return arts;
}

main {
  int n, m;
  cin >> n >> m;
  Graph g(n);
  rep(i, m) {
    int s, t;
    cin >> s >> t;
    g.addEdge(s, t);
  }
  vector<int> arts = articulationPoints(g);
  arts = nub(arts);
  for (auto &v : arts) cout << v << endl;
}


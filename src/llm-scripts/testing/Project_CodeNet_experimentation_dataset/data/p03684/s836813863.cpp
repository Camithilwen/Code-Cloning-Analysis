#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
typedef tuple<ll, ll, ll> Point;
vector<Point> Points[2];
typedef tuple<ll, ll, ll> Edge;
vector<Edge> Edges;
vector<ll> Parent, Rank;
ll R;

void init() {
  Parent.resize(N, -1);
  Rank.resize(N, 0);
}
ll root(ll v) {
  if (Parent[v] == -1) return v;
  return Parent[v] = root(Parent[v]);
}
bool same(ll u, ll v) { return root(u) == root(v); }
void unite(ll u, ll v) {
  u = root(u);
  v = root(v);
  if (u == v) return;
  if (Rank[u] < Rank[v]) swap(u, v);
  Parent[v] = u;
  if (Rank[u] == Rank[v]) ++Rank[u];
}
int main() {
  cin >> N;
  for (ll v = 0; v < N; ++v) {
    ll x, y;
    cin >> x >> y;
    Points[0].push_back(Point(x, y, v));
    Points[1].push_back(Point(y, x, v));
  }
  for (ll k : {0, 1}) sort(Points[k].begin(), Points[k].end());
  for (ll k : {0, 1})
    for (ll i = 0; i < N - 1; ++i) {
      ll x, y, u, x2, y2, v;
      tie(x, y, u) = Points[k][i];
      tie(x2, y2, v) = Points[k][i + 1];
      Edges.push_back(Edge(min(abs(x2 - x), abs(y2 - y)), u, v));
    }
  sort(Edges.begin(), Edges.end());
  init();
  for (Edge edge : Edges) {
    ll d, u, v;
    tie(d, u, v) = edge;
    if (!same(u, v)) {
      unite(u, v);
      R += d;
    }
  }
  cout << R << endl;
  return 0;
}

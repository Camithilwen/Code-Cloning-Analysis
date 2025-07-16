#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())

struct UnionFind {
  vector<int> par;
  UnionFind(int n) : par(n) { par.assign(n, -1); }

  int root(int a) {
    if (par[a] < 0)
      return a;
    return par[a] = root(par[a]);
  }
  int size(int a) { return -par[root(a)]; }
  void unite(int a, int b) {
    int ra = root(a), rb = root(b);
    if (ra == rb)
      return;
    if (par[a]>par[b])
      swap(a, b);
    par[ra] += par[rb];
    par[rb] = ra;
    return;
  }
  bool same(int a, int b) {
    int ra = root(a), rb = root(b);
    return ra == rb;
  }
};
UnionFind uft(100001);

struct edge {
  ll cost;
  int n1;
  int n2;
  bool operator<(const edge& right) const {
    return cost<=right.cost;
  }
};

int main() {
  int N;
  cin >> N;
  vector<pair<ll,int>> X(N),Y(N);
  rep(i,N) {
    ll x,y;
    cin >> x >> y;
    X[i] = {x,i};
    Y[i] = {y,i};
  }
  set<edge> S;
  sort(all(X));
  sort(all(Y));
  rep1(i,N-1) {
    S.insert({X[i].first-X[i-1].first, X[i].second, X[i-1].second});
    S.insert({Y[i].first-Y[i-1].first, Y[i].second, Y[i-1].second});
  }
  ll ans = 0;
  while (!S.empty()) {
    auto it = S.begin();
    S.erase(it);
    if (uft.same(it->n1,it->n2)) {
      continue;
    }
    uft.unite(it->n1,it->n2);
    ans += it->cost;
  }
  print(ans);
  return 0;
}
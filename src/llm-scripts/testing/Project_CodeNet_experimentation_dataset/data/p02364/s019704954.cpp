#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
template<class T> using vv=vector<vector< T > >;

struct UF {
  vector<int> par;
  vector<int> sizes;
  UF(int n) : par(n), sizes(n, 1) {
    rep(i,n) par[i] = i;
  }
  int root(int x) {
    if (x == par[x]) return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
      return;
    }
    if (sizes[x] < sizes[y]) {
      swap(x, y);
    }
    par[y] = x;
    sizes[x] += sizes[y];
    sizes[y] = 0;
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  int size(int x) {
    return sizes[root(x)];
  }
}; // UF

int V, E;
vvi edge;
ll cost;

void kruskal() {
  cost = 0;
  UF uf(V);
  rep (i, E) {
    auto e = edge[i];
    if (uf.same(e[1], e[2])) {
      continue;
    }
    uf.unite(e[1], e[2]);
    cost += e[0];
    if (uf.size(e[1]) == V) {
      break;
    }
  }
  return;
}

int main() {
  scanf("%d %d", &V, &E);
  edge.assign(E, vi(3));
  rep (i, E) {
    int s, t, w;
    scanf("%d %d %d", &s, &t, &w);
    edge[i][0] = w;
    edge[i][1] = s;
    edge[i][2] = t;
  }
  sort(all(edge));
  kruskal();
  printf("%lld\n", cost);

  return 0;
}
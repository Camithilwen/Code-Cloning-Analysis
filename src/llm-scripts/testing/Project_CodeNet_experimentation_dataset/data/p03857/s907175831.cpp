#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <functional>
#include <bitset>

using namespace std;
using lli = long long int;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (lli i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (lli i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

struct UnionFind {
  vector<int> c, s;
  UnionFind(size_t n) : c(n), s(n, 1) { iota(begin(c), end(c), 0); }
  int root(int i) { return c[i] == i ? i : (c[i] = root(c[i])); }
  bool same(int i, int j) { return root(i) == root(j); }
  void unite(int i, int j) {
    i = root(i); j = root(j);
    if (i != j) {
      if (s[i] > s[j]) { c[j] = i; s[i] += s[j]; }
      else { c[i] = j; s[j] += s[i]; }
    }
  }
  int size(int i) { return s[root(i)]; }
};

lli n, k, l;
int main() {
  cin >> n >> k >> l;
  UnionFind ufp(n+1), ufr(n+1), ufm(n+1);
  for (lli i=0; i<k; ++i) {
    lli u, v; cin >> u >> v;
    ufp.unite(u, v);
  }
  for (lli i=0; i<l; ++i) {
    lli u, v; cin >> u >> v;
    ufr.unite(u, v);
  }
  map<pair<lli, lli>, lli> m;
  for (lli i=1; i<=n; ++i) {
    m[make_pair(ufp.root(i), ufr.root(i))]++;
  }
  for (lli i=1; i<=n; ++i) {
    cout << m[make_pair(ufp.root(i), ufr.root(i))] << '\n';
  }
  return 0;
}


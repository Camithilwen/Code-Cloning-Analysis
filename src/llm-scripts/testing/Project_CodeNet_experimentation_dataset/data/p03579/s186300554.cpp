#include <bits/stdc++.h>

using namespace std;

class UnionFind {
 public:
  std::vector<int> parent;

  UnionFind(int n) : parent(n, -1) {}

  int root(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = root(parent[x]);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  int size(int x) { return -parent[root(x)]; }

  bool unite(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx == ry) return false;
    if (parent[rx] > parent[ry]) std::swap(rx, ry);
    parent[rx] += parent[ry];
    parent[ry] = rx;
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  UnionFind uf(2 * N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    uf.unite(a, b + N);
    uf.unite(a + N, b);
  }
  if (uf.issame(0, N)) {
    cout << 1LL * N * (N - 1) / 2 - M << '\n';
  } else {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if (uf.issame(0, i)) cnt++;
    }
    // cout << cnt << '\n';
    cout << 1LL * cnt * (N - cnt) - M << '\n';
  }
  return 0;
}

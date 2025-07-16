#include <bits/stdc++.h>
using namespace std;

template<typename T, typename E> struct LazySegmentTree {
  using F = function<T(T, T)>;
  using G = function<T(T, E)>;
  using H = function<E(E, E)>;
  using P = function<E(E, int)>;

  int n;
  T ti;
  E ei;
  F f;
  G g;
  H h;
  P p;
  vector<T> data;
  vector<E> lazy;

  LazySegmentTree(int n_, F f, G g, H h, T ti = INT_MAX, E ei = INT_MAX,
                  P p = [](E a, int b) { return a; })
      : f(f), g(g), h(h), ti(ti), ei(ei), p(p) {
    init(n_);
  }
  void init(int n_) {
    n = 1;
    while (n < n_) n *= 2;
    data.assign(n * 2 - 1, ti);
    lazy.assign(n * 2 - 1, ei);
  }
  void build(vector<T> v) {
    for (int i = 0; i < v.size(); ++i) data[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; --i) {
      data[i] = f(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }
  inline void eval(int len, int k) {
    if (lazy[k] == ei) return;
    if (k * 2 + 1 < n * 2 - 1) {
      lazy[k * 2 + 1] = h(lazy[k * 2 + 1], lazy[k]);
      lazy[k * 2 + 2] = h(lazy[k * 2 + 2], lazy[k]);
    }
    data[k] = g(data[k], p(lazy[k], len));
    lazy[k] = ei;
  }
  T update(int a, int b, E x, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    eval(r - l, k);
    if (b <= l || r <= a) return data[k];
    if (a <= l && r <= b) {
      lazy[k] = h(lazy[k], x);
      return g(data[k], p(lazy[k], r - l));
    }
    T vl = update(a, b, x, k * 2 + 1, l, (l + r) / 2);
    T vr = update(a, b, x, k * 2 + 2, (l + r) / 2, r);
    return data[k] = f(vl, vr);
  }
  T query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    eval(r - l, k);
    if (b <= l || r <= a) return ti;
    if (a <= l && r <= b) return data[k];
    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return f(vl, vr);
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, q; cin >> n >> q;
  const int INF = INT_MAX;
  LazySegmentTree<int, int>::F f = [&](int a, int b) { return min(a, b); };
  LazySegmentTree<int, int>::G g = [&](int a, int b) { return (b == INF) ? a : b; };
  LazySegmentTree<int, int>::H h = [&](int a, int b) { return (b == INF) ? a : b; };
  LazySegmentTree<int, int>::P p = [&](int a, int b) { return (a == INF) ? a : a * b; };

  LazySegmentTree<int, int> seg(n, f, g, h);
  for (int i = 0; i < q; ++i) {
    int com; cin >> com;
    if (com) {
      int i; cin >> i;
      cout << seg.query(i, i + 1) << endl;
    } else {
      int s, t, x; cin >> s >> t >> x;
      seg.update(s, t + 1, x);
    }
  }
  return 0;
}


#include <iostream>
using namespace std;
#include <vector>
#include <functional>
template<class T, class Lazy> struct LazySegTree {
  private:
  public:
    int size;
    vector<T> v; vector<Lazy> lazy;
    vector<int> seg_size;
    using F = function<T(T,T)>;
    using G = function<Lazy(Lazy,Lazy)>;
    using H = function<T(T,Lazy,int)>;
    F f; G g; H h;
    T default_value; Lazy default_lazy;
  public:
    LazySegTree(int n, T default_value, Lazy default_lazy, F f, G g, H h)
      : default_value(default_value), default_lazy(default_lazy), f(f), g(g), h(h) {
      size = 1;
      while (size < n) size *= 2;

      v.resize(2 * size - 1, default_value);
      lazy.resize(4 * size - 1, default_lazy);
      seg_size.resize(2 * size - 1, 1);

      for (int i = 0; i < size - 1; ++i) {
        int j = size - 2 - i;
        seg_size[j] = seg_size[2 * j + 1] + seg_size[2 * j + 2];
      }
    }
    void update(int index, T val) {
      update(index, index+1, default_lazy);
      index = index + size - 1;
      v[index] = val;
      while (index > 0) {
        index = (index - 1) / 2;
        v[index] = f(v[2 * index + 1], v[2 * index + 2]);
      }
    }
    void eval(int index) {
      v[index] = h(v[index], lazy[index], seg_size[index]);

      lazy[2 * index + 1] = g(lazy[index], lazy[2 * index + 1]);
      lazy[2 * index + 2] = g(lazy[index], lazy[2 * index + 2]);

      lazy[index] = default_lazy;
    }
    T query(int l, int r) { return query(l, r, 0, size, 0); }
    T query(int l, int r, int cur_l, int cur_r, int index) {
      // [l, r)に対するクエリ
      eval(index);
      if (cur_r <= l || r <= cur_l) return default_value;
      if (l <= cur_l && cur_r <= r) return v[index];

      // 左右を見ていく
      int mid = (cur_l + cur_r) / 2;
      return f(
          query(l, r, cur_l, mid, 2 * index + 1),
          query(l, r, mid, cur_r, 2 * index + 2));
    }
    void update(int l, int r, Lazy x) { update(l, r, x, 0, size, 0); }
    void update(int l, int r, Lazy x, int cur_l, int cur_r, int index) {
      // [l, r)に対して操作する

      eval(index);
      if (cur_r <= l || r <= cur_l) return;
      if (l <= cur_l && cur_r <= r) {
        lazy[index] = x;
        eval(index);
        return;
      }
      // 左右を見ていく
      int mid = (cur_l + cur_r) / 2;
      update(l, r, x, cur_l, mid, 2 * index + 1);
      update(l, r, x, mid, cur_r, 2 * index + 2);
      v[index] = f(v[2 * index + 1], v[2 * index + 2]);
    }
};

// // 範囲和
// LazySegTree<long long, int> T(N, 0, 0,
//     [](long long a, long long b) {return a + b;},
//     [](int a, int b) {return a + b;},
//     [](long long a, int b, int size) {return a + b * size;});
// // chmin
// LazySegTree<ll, ll> T(N, INF, -1,
//     [](ll a, ll b) {return min(a, b);},
//     [](ll a, ll b) { return a == -1 ? b : a;},
//     [](ll a, ll lz, int size) {return lz == -1 ? a : lz;});

#define in(v) v; cin >> v;
void ins() {}
template<class T,class... Rest>void ins(T& v,Rest&... rest){cin>>v;ins(rest...);}
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)

int main() {
  int in(N); int in(Q);

  // 範囲和
  LazySegTree<int, int> T(N, 2147483647, -1,
      [](int a, int b) {return min(a, b);},
      [](int par_lz, int lz) {return par_lz == -1 ? lz : par_lz;},
      [](int a, int lz, int size) {return lz == -1 ? a : lz;});

  rep(i, Q) {
    int com;
    ins(com);

    if (com == 0) {
      int s, t, x;
      ins(s, t, x);
      ++t;
      T.update(s, t, x);
    } else {
      int in(idx);
      cout << T.query(idx, idx+1) << endl;
    }
  }

  return 0;
}


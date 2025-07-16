#include <algorithm>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define fst first
#define snd second

/* clang-format off */
template <class T, size_t D> struct _vec { using type = vector<typename _vec<T, D - 1>::type>; };
template <class T> struct _vec<T, 0> { using type = T; };
template <class T, size_t D> using vec = typename _vec<T, D>::type;
template <class T> vector<T> make_v(size_t size, const T& init) { return vector<T>(size, init); }
template <class... Ts> auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }
/* clang-format on */

template <class I>
class SegmentTree {
 public:
  using Op = function<I(const I&, const I&)>;

 private:
  int n;
  vector<I> dat;
  Op op;
  I e;

 public:
  SegmentTree(int n_, const Op& op, const I& e) : op(op), e(e) {
    n = 1;
    while (n < n_) n *= 2;
    dat.resize(2 * n - 1, e);
  }
  SegmentTree(const vector<I>& init, const Op& op, const I& e)
      : SegmentTree(init.size(), op, e) {
    for (int i = 0; i < init.size(); i++) {
      dat[i + n - 1] = init[i];
    }
    for (int i = n - 2; i >= 0; i--) {
      dat[i] = op(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }
  const I& operator[](int k) const { return dat[k + n - 1]; }
  void update(int k, const I& a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = op(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }
  // [a, b)
  I query(int a, int b) const {
    a += n - 1;
    b += n - 1;
    I vl = e;
    I vr = e;
    while (a < b) {
      if ((a & 1) == 0) vl = op(vl, dat[a]);
      if ((b & 1) == 0) vr = op(dat[b - 1], vr);
      a = a / 2;
      b = (b - 1) / 2;
    }
    return op(vl, vr);
  }
  // query(0, i) >= x となる最小のi
  int kth(const I& x) const {
    int k = 0;
    I v = e;
    while (k < n - 1) {
      I t = op(v, dat[k * 2 + 1]);
      if (x <= t) {
        k = k * 2 + 1;
      } else {
        v = t;
        k = k * 2 + 2;
      }
    }
    return k - (n - 1) + 1;
  }
};

int main() {
#ifdef LOCAL
  ifstream cin("in.txt");
#endif
  int N, Q;
  while (cin >> N >> Q) {
    int M = Q + 2;
    vector<ll> x(M);
    for (int i = 0; i < M; i++) cin >> x[i], --x[i];
    vector<ll> dsum(M);
    dsum[0] = 0;
    for (int i = 1; i < M; i++) {
      dsum[i] = dsum[i - 1] + abs(x[i] - x[i - 1]);
    }
    auto op = [](ll a, ll b) { return min(a, b); };
    ll inf = numeric_limits<ll>::max();
    vector<ll> dp(M);
    dp[M - 1] = 0;
    SegmentTree<ll> addSeg(N, op, inf), subSeg(N, op, inf);
    addSeg.update(x[M - 1], dp[M - 1] + dsum[M - 2] + x[M - 1]);
    subSeg.update(x[M - 1], dp[M - 1] + dsum[M - 2] - x[M - 1]);
    for (int i = M - 2; i >= 1; i--) {
      dp[i] = min({dsum[M - 1] - dsum[i],  // 先頭を最後まで持っていく
                   addSeg.query(x[i - 1], N) - dsum[i] - x[i - 1],
                   subSeg.query(0, x[i - 1] + 1) - dsum[i] + x[i - 1]});
      addSeg.update(x[i], min(addSeg[x[i]], dp[i] + dsum[i - 1] + x[i]));
      subSeg.update(x[i], min(subSeg[x[i]], dp[i] + dsum[i - 1] - x[i]));
    }
    cout << dp[1] << endl;
  }
  return 0;
}

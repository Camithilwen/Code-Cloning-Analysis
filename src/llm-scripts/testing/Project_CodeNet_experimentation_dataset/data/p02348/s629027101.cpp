#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

template <typename _Tp>
struct LazySegmentTree {
  _Tp n;
  vector<_Tp> node, lazy;

  LazySegmentTree(vector<_Tp> const& v) {
    _Tp sz = v.size();
    n = 1;
    while (sz > n) n *= 2;
    node.resize(2*n-1);
    lazy.resize(2*n-1, -1);

    for (int i = 0; i < sz; ++i) {
      node[i+n-1] = v[i];
    }
/*
    for (int i = n-2; i >= 0; --i) {
      node[i] = node[i*2+1] + node[i*2+2];
    }
    */
  }

  void eval(int k, int l, int r) {
    if (lazy[k] != -1) {
      node[k] = lazy[k]; // 自分自身に遅延評価を反映

      // 最下段でないならば評価を伝搬させる。
      if (r - l > 1) {
        lazy[2*k+1] = lazy[k];
        lazy[2*k+2] = lazy[k];
      }

      lazy[k] = -1;
    }
  }

  void update(int a, int b, _Tp value, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    eval(k,l,r);

    // 範囲外ならば切る。
    if (b <= l || r <= a) {
      // cout << 1 << endl;
      return;
    }

    if (a <= l && r <= b) {
      lazy[k] = value;
      eval(k,l,r);
      return;
    } else {
      update(a,b,value,2*k+1,l,(r+l)/2);
      update(a,b,value,2*k+2,(l+r)/2,r);
      node[k] = value;
    }
  }

  _Tp get(int idx, int k = 0, int l = 0, int r = -1) {
    int a = idx, b = idx+1;
    if (r < 0) {
      r = n;
    }

    eval(k,l,r);

    // cout << a << " "<< b << " " << l << " " << r << endl;

    if (a <= l && r <= b) {
      return node[k];
    }

    if (b <= l || r <= a) return -1;
    else {
      auto lv = get(idx, 2*k+1, l, (l+r)/2);
      auto rv = get(idx, 2*k+2, (l+r)/2, r);
      return max(lv, rv);
    }
  }
};

ll fi = (1L << 31) - 1;

int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> v(n, fi);
  LazySegmentTree<ll> seg_tree(v);
  rep(i, q) {
    int com;
    cin >> com;
    if (com == 0) {
      int s,t,n;
      cin >> s >> t >> n;
      seg_tree.update(s,t+1,n);
    } else {
      int idx;
      cin >> idx;
      cout << seg_tree.get(idx) << "\n";
    }
  }
}



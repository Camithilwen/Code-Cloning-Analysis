#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
#include<functional>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

template<typename T>
void sort_u(T& v) {
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(),v.end()), v.end());
}

template<typename T, typename DT=T>
struct monoid_factory { 
  using value_type = T; 
  using operator_type = DT;
  using oa_type = std::function<void(operator_type&,operator_type)>;
  using va_type = std::function<void(value_type&,operator_type)>;
  using vo_type = std::function<value_type(value_type,operator_type)>;
  using vv_type = std::function<value_type(value_type,value_type)>;
  value_type ve;
  operator_type oe;
  oa_type op_assign;
  va_type v_assign;
  vo_type v_op;
  vv_type v_v;
  monoid_factory(value_type in_ve, operator_type in_oe, oa_type&& in_oa,
    va_type&& in_va, vo_type&& in_vo, vv_type in_vv): ve(in_ve), oe(in_oe),
    op_assign(in_oa), v_assign(in_va), v_op(in_vo), v_v(in_vv) {}
};

// lazy_seg_tree
template<typename MonoidFactory>
struct lazy_seg_tree {
  using T  = typename MonoidFactory::value_type;
  using OT = typename MonoidFactory::operator_type;
  std::vector<T> data_;
  std::vector<OT> lazy_;
  int NN;
  MonoidFactory mf;
  
  lazy_seg_tree(int N, MonoidFactory const& in_m): mf(in_m)  {
    NN=1;
    while(NN<N+2) NN<<=1;
    data_.assign(NN*2-1, mf.ve);
    lazy_.assign(NN*2-1, mf.oe);
  }
  
  void eval(int k) {
    if(lazy_[k] == mf.oe) return;
    if(k*2+1 < NN*2-1) {
      mf.op_assign(lazy_[2*k+1], lazy_[k]);
      mf.op_assign(lazy_[2*k+2], lazy_[k]);
    }
    mf.v_assign(data_[k], lazy_[k]);
    lazy_[k] = mf.oe;
  }

  T update(int a, int b, OT x, int k, int l, int r) {
    if(b <= l || r <= a) {
      eval(k);
      return data_[k];
    }
    if(a <= l && r <= b) {
      mf.op_assign(lazy_[k], x);
      return mf.v_op(data_[k], lazy_[k]);
    }
    eval(k);
    int m = (l+r)/2;
    T vl = update(a, b, x, k*2+1, l, m);
    T vr = update(a, b, x, k*2+2, m, r);
    return data_[k] = mf.v_v(vl, vr);
  }

  T query(int a, int b, int k, int l, int r) {
    if(b <= l || r <= a) return mf.ve;
    eval(k);
    if(a <= l && r <= b) return data_[k];
    int m = (l+r)/2;
    T vl = mf.ve, vr = mf.ve;
    if(!(m <= a || b <= l)) vl = query(a, b, k*2+1, l, m);
    if(!(r <= a || b <= m)) vr = query(a, b, k*2+2, m, r);
    return mf.v_v(vl, vr);
  }
  
  void update(int a, int b, OT x){ update(a, b, x, 0, 0, NN); }
  T query(int a, int b){ return query(a, b, 0, 0, NN); }
};

struct C {
  int l, r, v;
  C(int S, int T, int X): l(std::max(0,S-X)), r(std::max(0, T-X)), v(X) {}
};

int const INF = 1e9+5;

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N, Q; std::cin >> N >> Q;
  std::vector<int> xs(1, 0);
  std::vector<C> cond;
  for(int i = 0; i < N; ++i) {
    int S, T, X; std::cin >> S >> T >> X;
    if(X >= T) continue;
    cond.emplace_back(S, T, X);
    xs.push_back(cond.back().l);
    xs.push_back(cond.back().r);
  }
  sort_u(xs); 
  for(auto& c: cond) {
    c.l = std::lower_bound(xs.begin(), xs.end(), c.l) - xs.begin();
    c.r = std::lower_bound(xs.begin(), xs.end(), c.r) - xs.begin();
  }
  
  auto ch_min = [](int& o1, int o2)->void { if(o1 > o2) o1 = o2; };
  auto op_min = [](int x, int y)->int { return std::min(x, y); };
  monoid_factory<int> mf(INF, INF, ch_min, ch_min, op_min, op_min);
  lazy_seg_tree<monoid_factory<int>> lst(xs.size(), mf);
  for(auto& c: cond) lst.update(c.l, c.r, c.v);
  for(int i = 0; i < Q; ++i) {
    int D; std::cin >> D;
    int d = std::upper_bound(xs.begin(), xs.end(), D) - xs.begin();
    int ans = lst.query(d-1, d);
    if(ans == INF) ans = -1;
    std::cout << ans << "\n";
  }
  return 0;
}

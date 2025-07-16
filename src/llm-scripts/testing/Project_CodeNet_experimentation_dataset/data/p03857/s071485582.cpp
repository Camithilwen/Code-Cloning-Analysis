#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for(int i = 1, i##_len = (n); i < i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define PRINT(A) std::cout << (#A) << ":" << (A) << std::endl;
using namespace std;
#define repi(itr, ds) for(auto itr = ds.begin(); itr != ds.end(); itr++)

// vector
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for(T &x : vec) is >> x;
  return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "{";
  for(int i = 0; i < vec.size(); i++) {
    os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
  }
  os << "}\n   ";
  return os;
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
  os << "{";
  repi(itr, map_var) {
    os << *itr;
    itr++;
    if(itr != map_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
  os << "{";
  repi(itr, set_var) {
    os << *itr;
    itr++;
    if(itr != set_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}

#define DUMPOUT cerr

void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
  DUMPOUT << head;
  if(sizeof...(Tail) > 0) {
    DUMPOUT << ", ";
  }
  dump_func(std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define dump(...)                                                             \
  DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                             \
          << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]" << endl \
          << "    ",                                                          \
      dump_func(__VA_ARGS__)
#else
#define DEB if(false)
#define dump(...)
#endif

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9;

class UnionFind {
 public:
  vector<ll> par;
  vector<ll> siz;

  // Constructor
  UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
    for(ll i = 0; i < sz_; ++i) par[i] = i;
  }
  void init(ll sz_) {
    par.resize(sz_);
    siz.assign(sz_, 1LL);
    for(ll i = 0; i < sz_; ++i) par[i] = i;
  }

  // Member Function
  // Find
  ll root(ll x) {
    while(par[x] != x) {
      x = par[x] = par[par[x]];
    }
    return x;
  }

  // Union(Unite, Merge)
  bool merge(ll x, ll y) {
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    return true;
  }

  bool issame(ll x, ll y) {  // 連結判定
    return root(x) == root(y);
  }

  ll size(ll x) {  // 素集合のサイズ
    return siz[root(x)];
  }
};

int main() {
  int N, K, L;
  cin >> N >> K >> L;
  auto road = UnionFind(N);
  auto railway = UnionFind(N);
  REP(i, K) {
    int p, q;
    cin >> p >> q;
    p--;
    q--;
    road.merge(p, q);
  }
  REP(i, L) {
    int r, s;
    cin >> r >> s;
    r--;
    s--;
    railway.merge(r, s);
  }
  auto roots = map<pair<int, int>, int>();
  REP(i, N) {
    pair<int, int> p = {road.root(i), railway.root(i)};
    roots[p]++;
  }
  REP(i, N) {
    pair<int, int> p = {road.root(i), railway.root(i)};
    int cnt = roots[p];
    cout << cnt;
    if(i != N - 1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}

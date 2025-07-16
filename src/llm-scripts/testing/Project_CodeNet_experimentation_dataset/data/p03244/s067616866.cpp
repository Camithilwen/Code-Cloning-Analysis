#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using vi = vector<int>;

constexpr char newl = '\n';
constexpr double eps = 1e-10;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)
#define RF0(i,b) RFO(i,0,b)
#define fi first
#define se second
#define show(x) cout << #x << " = " << x << '\n';
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define sz(x) (int)(x).size()
#define YesNo {cout<<"Yes";}else{cout<<"No";}
#define YESNO {cout<<"YES";}else{cout<<"NO";}
#define v(T) vector<T>

template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
template<class T> bool lcmp(const pair<T, T>& l, const pair<T, T>& r) {
  return l.first < r.first;
}
template<class T> istream& operator>>(istream& i, v(T)& v) {
  F0R(j, sz(v)) i >> v[j];
  return i;
}
template<class A, class B> istream& operator>>(istream& i, pair<A, B>& p) {
  return i >> p.first >> p.second;
}
template<class A, class B, class C> istream& operator>>(istream& i, tuple<A, B, C>& t) {
  return i >> get<0>(t) >> get<1>(t) >> get<2>(t);
}
template<class T> ostream& operator<<(ostream& o, const vector<T>& v) {
  F0R(i, v.size()) {
    o << v[i] << ' ';
  }
  o << newl;
  return o;
}
template<class T1, class T2> ostream& operator<<(ostream& o, const map<T1, T2>& m) {
  for (auto& p : m) {
    o << p.first << ": " << p.second << newl;
  }
  o << newl;
  return o;
}

#if 1


// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  unordered_map<int, int> a, b;

  F0R(i, n) {
    int v;
    cin >> v;
    if (i & 1) {
      ++a[v];
    }
    else {
      ++b[v];
    }
  }
  vector<pair<int,int>> c, d;
  for (auto& p : a) c.emplace_back(p.second, p.first);
  for (auto& p : b) d.emplace_back(p.second, p.first);
  sort(rrng(c), lcmp<int>);
  sort(rrng(d), lcmp<int>);
  c.emplace_back(0, -1);
  d.emplace_back(0, -1);

  int r;
  if (c[0].second != d[0].second)
    r = n - c[0].first - d[0].first;
  else {
    r = n - max(c[0].first + d[1].first, c[1].first + d[0].first);
  }
  cout << r;
}
#endif

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

template <typename U>
map<U, int> primeFactorization(U n) {

  map<U, int> rs;

  while (!(n & 1)) {
    n >>= 1;
    rs[2]++;
  }

  for (U i = 3; i * i <= n; /*NOP*/) {
    auto q = n / i;
    auto r = n - i * q;
    if (r == 0) {
      rs[i]++;
      n = q;
    }
    else {
      i += 2;
    }
  }

  if (n > 1) {
    rs[n]++;
  }

  return rs;
}

template<typename T>
vector<T> getCompositeNums(map<T, int> primeNums) {

  vector<T> results;

  if (primeNums.empty()) {
    return results;
  }

  // どの素数を何個ずつ掛け合わせるか
  auto cur(primeNums);
  for (auto& c : cur) {
    c.second = 0;
  }

  auto it = cur.begin();
  while (true) {
    if (++it == cur.end()) {
      u64 com = 1;
      for (auto& c : cur) {
        com *= pow<u64>(c.first, c.second);
#if 0
        cout << c.first << "," << c.second << '\n';
#endif
      }
      if (com > 1) {
        results.push_back(com);
#if 0
        cout << com << '\n';
#endif
      }

      bool end = false;
      while (true) {
        if (it == cur.begin()) {
          end = true;
          break;
        }
        it--;
        if (++(it->second) > primeNums[it->first]) {
          it->second = 0;
          continue;
        }
        break;
      }
      if (end) {
        break;
      }
    }
  }

  sort(results.begin(), results.end());
  return results;
}

// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  auto cn = getCompositeNums(primeFactorization(M));
  cn.insert(cn.begin(), 1);
  //cout << cn;
  
  M /= *lower_bound(rng(cn), N);
  cout << M;
}
#endif

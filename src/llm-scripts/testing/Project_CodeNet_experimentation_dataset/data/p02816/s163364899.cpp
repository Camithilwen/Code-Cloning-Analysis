#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()

template<class T>
static inline std::vector<T> ndvec(size_t&& n, T val) { return std::vector<T>(n, std::forward<T>(val)); }
template<class... Tail>
static inline auto ndvec(size_t&& n, Tail&&... tail) {
  return std::vector<decltype(ndvec(std::forward<Tail>(tail)...))>(n, ndvec(std::forward<Tail>(tail)...));
}
template<class Cond> struct chain {
  Cond cond; chain(Cond cond) : cond(cond) {}
  template<class T> bool operator()(T& a, const T& b) const { if(cond(a, b)) { a = b; return true; } return false; }
};
template<class Cond> chain<Cond> make_chain(Cond cond) { return chain<Cond>(cond); }

#include <vector>
using u64 = unsigned long long;

struct hash_bases {
  static const u64 MOD = (1ull << 61) - 1;
  const int N;
  std::vector<std::vector<u64>> bases;
  
  inline static u64 mod(u64 x) {
    x = (x >> 61) + (x & MOD);
    if(x >= MOD) {
      x -= MOD;
    }
    return x;
  }

  inline static u64 mul(u64 a, u64 b) {
    u64 ac = a >> 31;
        a  = a & ((1ull << 31) - 1);
    u64 bc = b >> 31;
        b  = b & ((1ull << 31) - 1);
    u64 x = ac * b + bc * a;;
    x = ac * bc * 2 + (x >> 30) + ((x & ((1ull << 30) - 1)) << 31) + a * b;
    return mod(x);
  }
  
  hash_bases(std::vector<u64> bs, int M) : N(bs.size()), bases(M, std::vector<u64>(N, 1)) {
    for(int i = 1; i < M; i++) {
      for(int j = 0;j < N; j++){
        bases[i][j] = mul(bases[i - 1][j], bs[j]);
      }
    }
  }

  u64 operator()(int i, int r) {
    return bases[r][i];
  }
} bases(std::vector<u64> { 9973, 10007 }, 202020);

struct rhash {
  static const u64 MOD = hash_bases::MOD;
  std::vector<u64> h;
  u64 len;

  rhash() : h(bases.N), len(0) {}
  rhash(u64 x): h(bases.N), len(1) {
    x = hash_bases::mod(x);
    for(int i = 0; i < bases.N; i++) {
      h[i] = x;
    }
  }

  rhash next(u64 r) const {
    rhash ans;
    for(int i = 0;i < bases.N; i++) { 
      ans.h[i] = hash_bases::mul(h[i], bases(i, r));
    }
    ans.len = len + r;
    return ans;
  }

  rhash& operator+=(const rhash& r) {
    for(int i = 0;i < bases.N; i++) {
      h[i] += r.h[i];
      if(h[i] >= MOD) h[i] -= MOD;
    }
    len = std::max(len, r.len);
    return (*this);
  }

  rhash& operator-=(const rhash& r) {
    for(int i = 0;i < bases.N; i++) {
      if(h[i] < r.h[i]) {
        h[i] = h[i] + MOD - r.h[i];
      }
      else {
        h[i] = h[i] - r.h[i];
      }
    }
    return (*this);
  }

  rhash operator+(const rhash& r) const { return rhash(*this) += r; }
  rhash operator-(const rhash& r) const { return rhash(*this) -= r; }
  bool operator==(const rhash& r) const {
    bool OK = true;
    for(int i = 0;i < bases.N; i++){
      OK &= h[i] == r.h[i];
    }
    return OK;
  }
};

int main() {
  i64 N;
  cin >> N;
  vector<i64> A(N);
  rep(i,0,N) cin >> A[i];
  vector<i64> B(N);
  rep(i,0,N) cin >> B[i];
  vector<rhash> sum(N * 2);
  rep(i,0,N * 2 - 1) {
    sum[i + 1] = sum[i].next(1) + rhash(A[i % N] ^ A[(i + 1) % N]);
  }
  rhash bh;
  rep(i,0,N) {
    bh = bh.next(1) + rhash(B[i % N] ^ B[(i + 1) % N]);
  }
  rep(i,0,N) {
    if(sum[i + N] - sum[i].next(N) == bh) {
      cout << i << " " << (A[i] ^ B[0]) << endl;
    }
  }
}

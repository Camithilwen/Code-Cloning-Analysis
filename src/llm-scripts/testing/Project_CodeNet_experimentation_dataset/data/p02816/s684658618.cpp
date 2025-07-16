#include <bits/stdc++.h>

using namespace std;

template <typename T>
T random(T lo, T hi) {
  std::random_device rd;
  std::uniform_int_distribution<T> uid(lo, hi);
  return uid(rd);
}

class RollingHash {
 private:
  const uint64_t mod = (UINT64_C(1) << 61) - 1;
  static inline uint64_t base = random(UINT32_C(10007), UINT32_MAX);
  std::vector<uint64_t> hashes, pows;

  inline uint64_t add(uint64_t a, uint64_t b) const {
    a += b;
    if (a >= mod) a -= mod;
    return a;
  }

  inline uint64_t sub(uint64_t a, uint64_t b) const {
    if (a < b) a += mod;
    a -= b;
    return a;
  }

  inline uint64_t mul(uint64_t a, uint64_t b) const {
    uint64_t ah = a >> 31, al = a & ((UINT64_C(1) << 31) - 1), bh = b >> 31,
             bl = b & ((UINT64_C(1) << 31) - 1), m = ah * bl + al * bh,
             v = (ah * bh << 1) + (m >> 30) +
                 ((m & ((UINT64_C(1) << 30) - 1)) << 31) + al * bl;
    v = (v & ((UINT64_C(1) << 61) - 1)) + (v >> 61);
    return v;
  }

 public:
  template <typename T>
  RollingHash(const T &S) : hashes(S.size() + 1, 0), pows(S.size() + 1, 0) {
    pows[0] = 1;
    for (size_t i = 0; i < S.size(); i++) {
      pows[i + 1] = mul(pows[i], base);
      hashes[i + 1] = add(mul(hashes[i], base), S[i]);
    }
    // cout << base << '\n';
  }

  // S[l, r)
  uint64_t slice(int l, int r) const {
    return sub(hashes[r], mul(hashes[l], pows[r - l]));
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  vector<int> S(N), T(N);
  for (int i = 0; i < N; i++) {
    S[i] = A[i] ^ A[(i + 1) % N];
    T[i] = B[i] ^ B[(i + 1) % N];
  }
  for (int i = 0; i < N; i++) {
    S.emplace_back(S[i]);
  }
  RollingHash rhs(S), rht(T);
  for (int i = 0; i < N; i++) {
    if (rhs.slice(i, i + N) == rht.slice(0, N)) {
      cout << i << ' ' << (A[i] ^ B[0]) << '\n';
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#define debug(...) \
  { cerr << "# " << __VA_ARGS__ << "\n"; }
#else
#define debug(...)
#define FPEN
#endif
const int maxn = 200009;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef pair<int, int> pi;
typedef unsigned long long ui64;
const i64 MOD = 119 << 23 | 1;
struct hashing {
  static constexpr int dimensions = 4;
  static constexpr int mod = (1u << 31) - 1;
  vector<vector<int>> hashes, p;
  static const vector<int> &get_bases() {
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    static vector<int> bases;
    while (bases.size() < dimensions) {
      bases.emplace_back(uniform_int_distribution<int>((int)1e9, mod - 1)(rng));
    }
    return bases;
  }
  hashing(const vector<int> &s) : hashes(dimensions), p(dimensions) {
    int n = s.size();
    const vector<int> &bases = get_bases();
    for (int d = 0; d < dimensions; ++d) {
      hashes[d].resize(n + 1);
      p[d].resize(n + 1);
      p[d][0] = 1;
      long long base = bases[d];
      for (int i = 0; i < n; i++) {
        hashes[d][i + 1] = (hashes[d][i] * base + s[i]) % mod;
        p[d][i + 1] = p[d][i] * base % mod;
      }
    }
  }
  vector<int> get_hash(int i, int len) {
    vector<int> res;
    for (int d = 0; d < dimensions; ++d) {
      int hash = (int)((hashes[d][i + len] + (long long)hashes[d][i] * (mod - p[d][len])) % mod);
      res.emplace_back(hash);
    }
    return res;
  }
};
class {
 public:
  void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), sa(n), sb(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
      sa[i] = a[i] ^ a[(i + 1) % n];
      sb[i] = b[i] ^ b[(i + 1) % n];
      sa.push_back(sa[i]);
    }
    hashing A(sa), B(sb);
    for (int i = 0; i < n; ++i) {
      if (A.get_hash(i, n - 1) != B.get_hash(0, n - 1))
        continue;
      int v = a[i] ^ b[0];
      cout << i << ' ' << v << '\n';
    }
  }
} NSPACE;
int main() {
  FPEN;
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}
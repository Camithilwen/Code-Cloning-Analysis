#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
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
template <class T> inline void chmin(T &a, const T& b) { if (b < a) a = b; }
template <class T> inline void chmax(T &a, const T& b) { if (b > a) a = b; }
/* clang-format on */

const ll MOD = 1e9 + 7;

int main() {
#ifdef DEBUG
  ifstream cin("in.txt");
#endif
  int N, X;
  while (cin >> N >> X) {
    vector<int> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    sort(S.begin(), S.end());
    vector<ll> dp(X + 1, 0);
    for (ll x = 0; x <= X; x++) dp[x] = x;
    for (int i = 0; i < N; i++) {
      int m = S[i];
      vector<ll> ndp(X + 1, 0);
      for (ll x = 0; x <= X; x++) {
        ndp[x] = (dp[x] * i % MOD + dp[x % m]) % MOD;
      }
      dp.swap(ndp);
    }
    cout << dp[X] << endl;
  }
  return 0;
}

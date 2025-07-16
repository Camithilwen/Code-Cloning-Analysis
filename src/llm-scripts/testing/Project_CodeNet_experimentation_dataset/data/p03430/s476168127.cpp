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

string S;

int dp[310][310][310];

int solve(int a, int b, int r) {
  if (a > b) return 0;
  int& res = dp[a][b][r];
  if (res != -1) return res;
  if (a == b) return (S[a] == S[b] || r > 0) ? 1 : 0;
  res = 0;
  chmax(res, solve(a + 1, b, r));
  chmax(res, solve(a, b - 1, r));
  if (S[a] == S[b]) {
    chmax(res, solve(a + 1, b - 1, r) + 2);
  } else if (r > 0) {
    chmax(res, solve(a + 1, b - 1, r - 1) + 2);
  }
  return res;
}

int main() {
#ifdef DEBUG
  ifstream ifs("in.txt");
  cin.rdbuf(ifs.rdbuf());
#endif
  int K;
  while (cin >> S >> K) {
    memset(dp, -1, sizeof(dp));
    cout << solve(0, S.size() - 1, K) << endl;
  }
  return 0;
}

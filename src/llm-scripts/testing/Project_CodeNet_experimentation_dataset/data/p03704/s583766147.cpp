#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <locale>
#include <iostream>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template <typename T> int len(const T &x) { return x.size(); }

template<typename T>
vector<T> table(int n, T v) { return vector<T>(n, v); }

template <class... Args>
auto table(int n, Args... args) {
  auto val = table(args...);
  return vector<decltype(val)>(n, move(val));
}

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "YES"; }
  string_type do_falsename() const { return "NO"; }
};

ll tens[32];

ll dp(const int digit, const ll D, bool zero) {
  if (digit == 1) return (D == 0 ? 10 : 0);
  if (digit == 0) return (D == 0 ? 1 : 0);
  if (abs(D) > tens[digit]) return 0;
  ll res = 0;
  for (int diff = -9; diff <= 9; ++diff) {
    int count = 10 - abs(diff) - (zero ? 1 : 0);
    ll nD = D - diff * (tens[digit - 1] - 1);
    if (nD % 10 == 0) res += dp(digit - 2, nD / 10, false) * count;
  }
  return res;
}

void solve(const ll D) {
  tens[0] = 1;
  REP(i,18) tens[i + 1] = tens[i] * 10;
  ll res = 0;
  for (int digit = 1; digit <= 18; ++digit) {
    res += dp(digit, D, true);
  }
  cout << res << endl;
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll D;
	scanf("%lld", &D);
	solve(D);
	return 0;
}

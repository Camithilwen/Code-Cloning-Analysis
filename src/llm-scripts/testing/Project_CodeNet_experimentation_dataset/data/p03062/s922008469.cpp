#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), s(n + 1);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) s[i + 1] = s[i] + abs(a[i]);

  ll minus = INFL, minus_cnt = 0;
  rep(i, 0, n) {
    if (a[i] == 0) {
      minus = INFL;
      minus_cnt = 0;
    } else {
      minus = min(minus, abs(a[i]));
      if (a[i] < 0) ++minus_cnt;
    }
  }
  cout << s[n] - (minus_cnt % 2 == 0 ? 0 : minus * 2) << endl;
}
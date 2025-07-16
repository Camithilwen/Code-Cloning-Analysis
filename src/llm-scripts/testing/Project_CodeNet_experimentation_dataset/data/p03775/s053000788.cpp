#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  ll n;
  cin >> n;

  ll ans = INFL;
  auto d = [](ll x) {
    ll res = 0;
    while (x) {
      res++;
      x /= 10;
    }
    return res;
  };
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      ll a = d(i);
      ll b = d(n / i);
      ll f = max(a, b);
      ans = min(ans, f);
    }
  }
  cout << ans << endl;
  return 0;
}

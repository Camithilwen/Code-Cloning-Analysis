#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {
  ll n;
  cin >> n;
  ll m = (ll)sqrt((double)n);

  auto d = [](ll x) {
    ll res = 0;
    while (x) {
      x /= 10;
      res++;
    }
    return res;
  };

  rrep(i, 1, m + 1) {
    if (n % i == 0) {
      cout << max(d(i), d(n / i)) << '\n';
      return 0;
    }
  }
  return 0;
}

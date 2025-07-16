#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  int N;
  int64_t x;
  cin >> N >> x;

  vector<int64_t> a(N);
  rep(i, N) { cin >> a[i]; }

  sort(a.begin(), a.end());
  rep(i, N - 1) { a[i + 1] += a[i]; }

  auto p = lower_bound(a.begin(), a.end(), x);
  if (p == a.end()) {
    cout << N - 1 << endl;
  } else if (*p > x) {
    cout << p - a.begin() << endl;
  } else {
    cout << p - a.begin() + 1 << endl;
  }

  return 0;
}
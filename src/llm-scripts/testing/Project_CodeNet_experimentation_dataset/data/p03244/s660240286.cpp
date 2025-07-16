#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];

  unordered_map<int, int> odd, even;
  rep(i, 0, n) {
    if (i & 1)
      odd[a[i]]++;
    else
      even[a[i]]++;
  }

  vector<pair<int, int>> o, e;
  for (auto p : odd) { o.emplace_back(p.second, p.first); }
  for (auto p : even) { e.emplace_back(p.second, p.first); }
  sort(o.rbegin(), o.rend());
  sort(e.rbegin(), e.rend());
  o.emplace_back(0, n / 2);
  e.emplace_back(0, n / 2);

  if (o[0].second == e[0].second) {
    cout << n - o[0].first - max(o[1].first, e[1].first) << endl;
  } else {
    cout << n - o[0].first - e[0].first << endl;
  }
  return 0;
}
#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define int long long int
constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

void solve() {
  int M;
  cin >> M;
  int ans = 0;
  int sum = 0;

  while (M--) {
    int c, d; cin >> d >> c;
    ans += c;
    sum += d*c;
  }

  ans -= 1;
  ans += (sum - 1)/9;

  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

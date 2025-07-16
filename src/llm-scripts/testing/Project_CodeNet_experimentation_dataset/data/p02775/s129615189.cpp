#include <algorithm>
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
  string s;
  cin >> s;

  vector<int> dp0(s.size() + 1), dp1(s.size() + 1);
  dp0[0] = 0;
  dp1[0] = 1;
  rep(i, s.size()) {
    int a = s[i] - '0';
    dp0[i + 1] = min(dp0[i] + a, min(dp1[i] + a + 1, dp1[i] + 10 - a));
    dp1[i + 1] = dp1[i] + 10 - a - 1;
    if (a < 9) {
      dp1[i + 1] = min(dp1[i + 1], min(dp0[i] + a + 1, dp1[i] + a + 2));
    }
  }

  // irep(i, s.size()) { cerr << " " << dp0[i] << " " << dp1[i] << "\n"; }

  cout << dp0[s.size()] << endl;
  return 0;
}
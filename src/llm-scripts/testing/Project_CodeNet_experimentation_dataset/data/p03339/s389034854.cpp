#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> west_sum(n);
  vector<int> east_sum(n);

  for (int i = 1; i < n; i++) {
    if (s[i-1] == 'W') {
      west_sum[i] = west_sum[i-1] + 1;
    } else {
      west_sum[i] = west_sum[i-1];
    }
  }

  for (int i = n-2; i >= 0; i--) {
    if (s[i+1] == 'E') {
      east_sum[i] = east_sum[i+1] + 1;
    } else {
      east_sum[i] = east_sum[i+1];
    }
  }

  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      ans = min(ans, east_sum[i]);
    } else if (i == n-1) {
      ans = min(ans, west_sum[i]);
    } else {
      ans = min(ans, west_sum[i] + east_sum[i]);
    }
  }

  cout << ans << endl;

  return 0;
}
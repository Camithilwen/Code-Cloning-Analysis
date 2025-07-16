#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  rep(i, n) cin >> x[i];

  int ans = 2e9;
  for (int l = 0; l + k - 1 < n; ++l) {
    int r = l + k - 1;
    if (x[l] >= 0) ans = min(ans, x[r]);
    else if (x[r] <= 0) ans = min(ans, -x[l]);
    else if (x[r] + x[l] >= 0) ans = min(ans, -2 * x[l] + x[r]);
    else ans = min(ans, 2 * x[r] - x[l]);
  }
  cout << ans << endl;
  return 0;
}
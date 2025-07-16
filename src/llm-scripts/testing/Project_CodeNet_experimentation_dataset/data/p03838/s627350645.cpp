#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll x, y;
  cin >> x >> y;
  ll absdif = abs(abs(x) - abs(y)), ans = 1e10;
  if (x <= y) ans = min(ans, y - x);                     // 0,0
  if (-1 * x <= y) ans = min(ans, y + x + 1);            // 1,0
  if (x <= -1 * y) ans = min(ans, -1 * y - x + 1);       // 0,1
  if (-1 * x <= -1 * y) ans = min(ans, -1 * y + x + 2);  // 1,1
  cout << ans << endl;
  return 0;
}

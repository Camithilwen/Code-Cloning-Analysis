#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll x,y;
  cin >> x >> y;
  ll ans = 999999999999;
  if (y - x >= 0) {
    ans = min(ans,y-x);
  }
  if ((-y) - x >= 0) {
    ans = min(ans,(-y)-x+1);
  }
  if (y - (-x) >= 0) {
    ans = min(ans,y-(-x)+1);
  }
  if ((-y) - (-x) >= 0) {
    ans = min(ans,(-y) - (-x)+2);
  }
  cout << ans << endl;
  return 0;
}
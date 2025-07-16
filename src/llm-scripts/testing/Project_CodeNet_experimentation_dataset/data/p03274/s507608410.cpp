#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = (s); i < n; ++i)
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  rep(i,0,n) cin >> x[i];
  int ans = 1000000000;
  rep(i,0,n-k+1) {
    int a = x[i], b = x[i+k-1];
    if (b < 0) {
      ans = min(ans, abs(a));
    } else if (a >= 0) {
      ans = min(ans, b);
    } else {
      ans = min(ans, b-a + min(abs(a), abs(b)));
    }
  }
  cout << ans << endl;
  return 0;
}
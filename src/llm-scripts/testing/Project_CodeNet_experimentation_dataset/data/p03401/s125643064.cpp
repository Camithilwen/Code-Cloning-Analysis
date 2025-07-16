#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = (s); i < (n); i++)
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n+2, 0);
  rep(i,1,n+1) cin >> a[i];
  int k = 0;
  rep(i,0,n+1) {
    k += abs(a[i] - a[i+1]);
  }
  rep(i,1,n+1) {
    int ans = k - abs(a[i-1] - a[i]) - abs(a[i] - a[i+1]);
    ans += abs(a[i-1] - a[i+1]);
    cout << ans << "\n";
  }
  return 0;
}
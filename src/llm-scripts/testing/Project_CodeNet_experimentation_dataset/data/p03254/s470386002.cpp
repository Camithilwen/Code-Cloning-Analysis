#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

signed main() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(),a.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if(i == n - 1) {
      if(x == a[i]) ans++;
      break;
    }

    if(a[i] <= x) {
      x -= a[i];
      ans++;
    } else {
      break;
    }

  }
  cout << ans << endl;
}
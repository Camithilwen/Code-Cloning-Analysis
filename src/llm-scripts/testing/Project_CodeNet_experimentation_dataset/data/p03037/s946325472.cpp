#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    int lmax = 0, rmin = n;
    rep(i,m) {
      int l, r;
      cin >> l >> r;
      lmax = max(lmax, l);
      rmin = min(rmin, r);
    }
    int ans = rmin - lmax + 1;
    if (ans <= 0) ans = 0;
    cout << ans << endl;
    return 0;
}
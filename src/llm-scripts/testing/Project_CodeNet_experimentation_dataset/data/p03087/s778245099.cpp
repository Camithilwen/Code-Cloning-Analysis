#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,q; string s;
  cin >> n >> q >> s;
  vector<int> a(n+1,0);
  rep(i,1,n+1) {
    if (s.substr(i-1,2) == "AC") {
      a[i]++;
    }
    a[i] += a[i-1];
  }
  rep(i,0,q) {
    int l,r;
    cin >> l >> r;
    int ans = a[r] - a[l];
    if (a[l] != a[l-1]) ans++;
    if (a[r] != a[r-1]) ans--;
    cout << ans << endl;
  }
  return 0;
}

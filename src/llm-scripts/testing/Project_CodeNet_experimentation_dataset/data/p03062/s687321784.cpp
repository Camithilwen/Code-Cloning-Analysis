#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  int cnt = 0, cnt_z = 0;
  rep(i,0,n) {
    cin >> a[i];
    if (a[i] < 0) cnt++;
    else if (a[i] == 0) cnt_z++;
  }
  ll ans = 0;
  rep(i,0,n) ans += abs(a[i]);
  if (cnt_z == 0 && cnt % 2 == 1) {
    ll b = 100000000000;
    rep(i,0,n) {
      b = min(b,abs(a[i]));
    }
    ans -= 2*b;
  }
  cout << ans << endl;
  return 0;
}

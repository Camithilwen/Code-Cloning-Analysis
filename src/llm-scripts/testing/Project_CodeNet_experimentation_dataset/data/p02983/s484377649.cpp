#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll l, r;
  cin >> l >> r;
  ll ans = 2018;
  if (r - l >= 2 * 2019) {
    rep(i, 2019) rep(j, 2019) ans = min(ans, (ll)i * j % 2019);
  } else if (r - l >= 2019) {
    vector<int> cnt(2019, 0);
    for (ll i = l; i <= r; ++i) ++cnt[l % 2019];
    rep(i, 2019) rep(j, 2019) {
      if (i == j && cnt[i] == 1) continue;
      ans = min(ans, (ll)i * j % 2019);
    }
  } else {
    for (ll i = l; i <= r; ++i) {
      for (ll j = i + 1; j <= r; ++j) {
        ans = min(ans, i * j % 2019);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
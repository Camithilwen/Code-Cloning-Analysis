#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 4e2 + 10;
const ll mod = 1e9 + 7;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//  freopen("abc.inp", "r", stdin); freopen("abc.out", "w", stdout);

  int l, r; cin >> l >> r;

  if (r - l + 1 >= 2019) cout << 0;
  else {
    ll ans = 2019;

    for (ll i = l; i <= r; ++i)
      for (ll j = i + 1; j <= r; ++j)
        ans = min(ans, (i * j) % 2019);

    cout << ans;
  }

  return 0;
}


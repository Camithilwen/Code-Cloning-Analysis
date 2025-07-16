#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  ll L, R;
  cin >> L >> R;

  if (R - L >= 2019) {
    cout << 0 << endl;
  } else {
    ll ans = 2019;
    for (ll i = L; i < R; i++) {
      for (ll j = i + 1; j <= R; j++) {
        ans = min(ans, (i * j) % 2019);
      }
    }
    cout << ans << endl;
  }
}
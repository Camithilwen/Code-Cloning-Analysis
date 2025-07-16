#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;

int main() {
  ll l, r;
  cin >> l >> r;
  if (r - l + 1 >= 2019) {
    cout << 0 << endl;
    return 0;
  }
  vector<ll> a(r - l + 1);
  rep(i, r - l + 1) { a[i] = (l + i) % 2019; }
  ll ans = inf;
  rep(i, a.size() - 1) {
    for (int j = i + 1; j < a.size(); j++) {
      ll tmp = a[i] * a[j] % 2019;
      if (ans > tmp) ans = tmp;
    }
  }
  cout << ans << endl;

  return 0;
}
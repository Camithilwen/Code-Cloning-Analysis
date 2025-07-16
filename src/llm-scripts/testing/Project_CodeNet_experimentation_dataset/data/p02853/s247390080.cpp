#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define INF 9223372036854775807
#define all(x) (x).begin(), (x).end()

ll ts = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll x, y, ans = 0;
  cin >> x >> y;

  if (x == 1) {
    ans += 300000;
  }

  else if (x == 2) {
    ans += 200000;
  }

  else if (x == 3) {
    ans += 100000;
  }

  if (y == 1) {
    ans += 300000;
  }

  else if (y == 2) {
    ans += 200000;
  }

  else if (y == 3) {
    ans += 100000;
  }

  if (x == 1 && y == 1) {
    ans += 400000;
  }

  cout << ans << "\n";
}
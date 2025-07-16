#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl

void solve() {
  ll n;
  cin >> n;
  ll sm = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 3 == 0 || i % 5 == 0)
      continue;
    sm += i;
  }
  cout << sm << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll test = 1;
  // cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}

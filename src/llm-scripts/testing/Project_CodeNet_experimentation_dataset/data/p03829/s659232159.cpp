#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;
using ULL = unsigned long long;
int main() {
  ULL N, a, b, west, east, chk, ans = 0;
  cin >> N >> a >> b >> west;
  rep(i, 1, N) {
    cin >> east;
    chk = (east - west) * a;
    if (chk > b) {
      ans += b;
    } else {
      ans += chk;
    }
    west = east;
  }
  cout << ans << endl;
  getchar();
}
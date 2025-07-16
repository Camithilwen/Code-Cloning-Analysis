#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int lb = 9, ub = 44;
int v[lb+ub+5][lb+ub+5];

int main () {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int i, j, z, e, pin, p2, p5;
  ll m, ans = 0;
  string s;
  for (i = 1; i <= n; i++) {
    cin >> s;
    m = e = pin = 0;
    for (char ch: s) {
      if (pin) e++;
      if (ch == '.') pin = 1;
      else m = m*10 + ch - '0';
    }
    p2 = -e;
    while (m % 2 == 0) {
      p2++;
      m /= 2;
    }
    p5 = -e;
    while (m % 5 == 0) {
      p5++;
      m /= 5;
    }
    for (int i2 = -lb; i2 <= ub; i2++)
      for (int i5 = -lb; i5 <= ub; i5++)
        if (i2+p2 >= 0 && i5+p5 >= 0) ans += 1LL*v[lb+i2][lb+i5];
    v[lb+p2][lb+p5]++;
  }
  cout << ans;
  return 0;
}
#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;

int main() {
  long long n, x, a, b, tmp, ans = 0;
  cin >> n >> x >> a;

  rep(i, 0, n) {
    if (i < n - 1) {
      cin >> b;
    } else {
      b = 0;
    }
    if (a + b > x) {
      tmp = a + b - x;
      b = b - tmp;
      ans += tmp;
    }
    a = b;
  }

  cout << ans << endl;
  getchar();
}
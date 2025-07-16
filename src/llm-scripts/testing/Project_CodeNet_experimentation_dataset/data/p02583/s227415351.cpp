#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  int n;
  cin >> n;
  vector<long> l(n);
  for (long &x : l) {
    cin >> x;
  }

  long ans = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        long sum = 0;
        long mx = 0;
        sum = l.at(i) + l.at(j) + l.at(k);
        mx = max(l.at(i), max(l.at(j), l.at(k)));
        if (sum <= 2 * mx) {
          continue;
        }

        if (l.at(i) != l.at(j) && l.at(j) != l.at(k) && l.at(k) != l.at(i)) {
          ans++;
        }
      }
    }
  }

  cout << ans << endl;
}

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
  long x;
  cin >> x;
  vector<long> a(n);
  for (long &x : a) {
    cin >> x;
  }
  long count = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a.at(i) + a.at(i + 1) > x) {
      long count_plus = min(a.at(i) + a.at(i + 1) - x, a.at(i + 1));
      count += count_plus;
      a.at(i + 1) -= count_plus;
      if (a.at(i + 1) == 0) {
        long count_plus = a.at(i) - x;
        count += count_plus;
        a.at(i) -= count_plus;
      }
    }
  }
  cout << count << endl;
}

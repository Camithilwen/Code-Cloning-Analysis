#include<bits/stdc++.h>

using namespace std;

const int N = 123456;

int n, a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int type = 1;
  while (1) {
    int even = 0;
    for (int i = 1; i <= n; ++i) {
      if (!(a[i] & 1)) {
        ++even;
      }
    }
    if (even & 1) {
      cout << (type == 1 ? "First" : "Second") << '\n';
      exit(0);
    } else if (!(even & 1) && n - even >= 2) {
      cout << (type == 1 ? "Second" : "First") << '\n';
      exit(0);
    } else {
      for (int i = 1; i <= n; ++i) {
        if (a[i] & 1) {
          if (a[i] == 1) {
            cout << (type == 1 ? "Second" : "First") << '\n';
            exit(0);
          } else {
            --a[i];
          }
        }
      }
      int gcd = 0;
      for (int i = 1; i <= n; ++i) {
        gcd = __gcd(gcd, a[i]);
      }
      for (int i = 1; i <= n; ++i) {
        a[i] /= gcd;
      }
    }
    type = !type;
  }
  return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  int l = 1, r = n;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    if (l < a) {
      l = a;
    }
    if (b < r) {
      r = b;
    }
  }
  if (r < l) {
    cout << 0 << endl;
  } else {
    cout << r - l + 1 << endl;
  }
  return 0;
}

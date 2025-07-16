#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  int res;
  for (int i = n; i <= 999; i++) {
    string str = to_string(i);
    bool ok = true;
    for (int j = 0; j < str.length() - 1; j++) {
      if (str[j] != str[j + 1]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      res = i;
      break;
    }
  }
  cout << res << endl;
  return 0;
}

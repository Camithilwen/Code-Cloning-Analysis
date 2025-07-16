/**
 *    author:  tourist
 *    created: 29.12.2019 21:02:36       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int t = 0; t < 4; t++) {
    vector<int> a(n + 2);
    a[0] = t & 1;
    a[1] = (t & 2) >> 1;
    for (int i = 2; i < n + 2; i++) {
      char c = s[(i - 1) % n];
      if (c == 'o') a[i] = a[i - 1] ^ a[i - 2];
      else a[i] = a[i - 1] ^ a[i - 2] ^ 1;
    }
    if (a[0] == a[n] && a[1] == a[n + 1]) {
      for (int i = 0; i < n; i++) cout << (!a[i] ? 'S' : 'W');
      cout << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}

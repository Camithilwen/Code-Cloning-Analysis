#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string a, b, c;
  cin >> a >> b >> c;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    string x, y, z;
    x = a.at(i); y = b.at(i); z = c.at(i);
    set<string> s{x, y, z};
    if (s.size() == 3) {
      ans += 2;
    } else if (s.size() == 2) {
      ans += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
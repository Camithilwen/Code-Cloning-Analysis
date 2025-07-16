#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  string s;
  int w;
  cin >> s >> w;
  int n = s.length();

  string ans;
  for (int i = 0; i < n; i += w) {
    ans += s[i];
  }
  cout << ans << '\n';

  return 0;
}

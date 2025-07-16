#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, ans;
  int w, i = 0;
  cin >> s >> w;
  while(i < (int)s.size()) {
    ans += s[i];
    i += w;
  }
  cout << ans << "\n";
}
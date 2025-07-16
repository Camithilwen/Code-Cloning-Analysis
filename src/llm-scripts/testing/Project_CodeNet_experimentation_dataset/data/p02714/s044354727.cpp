#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> R, G, B;
  rep(i,n) {
    if(s[i] == 'R') R.push_back(i);
    if(s[i] == 'G') G.push_back(i);
    if(s[i] == 'B') B.push_back(i);
  }

  long long ans = 0;
  for (auto r : R) {
    for (auto g : G) {
      int x = -1, y = -1, z = -1;
      int mi = min(r,g);
      int ma = max(r,g);
      if((r + g)%2 == 0) x = (r + g)/2;
      y = ma + abs(r - g);
      z = mi - abs(r - g);
      int add = B.size();
      if(binary_search(B.begin(),B.end(),x)) add--;
      if(binary_search(B.begin(),B.end(),y)) add--;
      if(binary_search(B.begin(),B.end(),z)) add--;
      ans += add;
    }
  }

  cout << ans << '\n';

}
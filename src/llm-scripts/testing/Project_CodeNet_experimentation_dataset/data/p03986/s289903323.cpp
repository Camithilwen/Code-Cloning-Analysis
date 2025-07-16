#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  int c = 0;
  rep(i, s.size()) {
    if (s[i] == 'T') ++c;
    else --c;
    ans = max(ans, 2 * c);
  }
  cout << ans << endl;
  return 0;
}
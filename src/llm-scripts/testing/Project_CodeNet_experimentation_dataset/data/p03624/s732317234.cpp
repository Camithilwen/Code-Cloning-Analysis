#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  vector<bool> found(26, false);
  rep(i, s.size()) found[s[i] - 'a'] = true;
  int a = -1;
  rep(i, 26) if (found[i] == false) {
    a = i;
    break;
  }
  if (a == -1) cout << "None" << endl;
  else {
    char c = a + 'a';
    cout << c << endl;
  }
  return 0;
}
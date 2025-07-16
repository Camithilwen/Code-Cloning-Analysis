#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  vector<string> s(3);
  rep(i,3) cin >> s[i];

  int cur = 0;
  while (true) {
    string t = s[cur];
    if (t.empty()) {
      cout << char(cur + 'A') << endl;
      return 0;
    }
    s[cur] = t.substr(1,t.size()-1);
    cur = t[0] - 'a';
  }
  return 0;
}
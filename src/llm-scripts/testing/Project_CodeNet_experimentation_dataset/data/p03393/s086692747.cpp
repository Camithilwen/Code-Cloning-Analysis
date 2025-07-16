#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  vector<int> cnt(26, 0);
  for (char c : s) {
    cnt.at(c - 'a')++;
  }
  bool exists = false;
  string res(s);
  bool nextExists = false;
  char next;
  rep(i, cnt.size()) {
    if (cnt.at(i) == 0) {
      nextExists = true;
      next = 'a' + i;
      break;
    }
  }
  if (nextExists) {
    res.push_back(next);
    exists = true;
  } else {
    while (!res.empty()) {
      char c = res.substr(res.size() - 1, 1).c_str()[0];
      res.pop_back();
      cnt.at(c - 'a')--;
      bool replaceExists = false;
      char replace;
      for (int i = c - 'a' + 1; i < cnt.size(); i++) {
        if (cnt.at(i) == 0) {
          replaceExists = true;
          replace = 'a' + i;
          break;
        }
      }
      if (replaceExists) {
        res.push_back(replace);
        exists = true;
        break;
      }
    }
  }
  if (exists) {
    cout << res << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}

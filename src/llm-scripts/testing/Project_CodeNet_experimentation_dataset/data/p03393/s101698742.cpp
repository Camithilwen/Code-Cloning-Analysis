#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  string s;
  cin >> s;

  vector<bool> contains(26, false);
  for (char c : s) {
    contains[c - 'a'] = true;
  }

  if (s.size() < 26) {
    rep(i, 26) {
      if (!contains[i]) {
        cout << s << (char)(i + 'a') << endl;
        return 0;
      }
    }
  } else {
    set<char> t;
    rrep(i, s.size()) {
      char c = s[i];
      auto p = t.upper_bound(c);
      if (p != t.end()) {
        cout << s.substr(0, i) << *p << endl;
        return 0;
      }
      t.insert(c);
    }
  }
  cout << -1 << endl;
  return 0;
}
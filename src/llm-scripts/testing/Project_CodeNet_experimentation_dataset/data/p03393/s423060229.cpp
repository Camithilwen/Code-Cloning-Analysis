#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  if (n < 26) {
    map<char, bool> mp;
    for (auto&& c : s) {
      mp[c] = true;
    }
    for (char c = 'a'; c <= 'z'; c++) {
      if (!mp.count(c)) {
        s += c;
        break;
      }
    }
    cout << s << '\n';
  } else {
    if (s == "zyxwvutsrqponmlkjihgfedcba") {
      cout << -1 << '\n';
    } else {
      string ans;
      for (int i = n - 1; i > 0; i--) {
        if (s[i - 1] < s[i]) {
          ans = s.substr(0, i);
          break;
        }
      }
      map<char, bool> mp;
      for (auto&& c : ans) {
        mp[c] = true;
      }
      debug(ans);
      for (char c = ans.back() + 1; c <= 'z'; c++) {
        if (!mp.count(c)) {
          ans.pop_back();
          ans += c;
          break;
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
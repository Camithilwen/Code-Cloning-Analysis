#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  int alp[27];
  for (int i = 0; i < 26; i++) {
    alp[i] = 0;
  }
  alp[26] = 1;

  cin >> s;
  if (s == "zyxwvutsrqponmlkjihgfedcba") {
    puts("-1");
  } else {
    string ans = "";
    for (int i = 0; i < (int)s.size(); i++) {
      alp[s[i] - 'a']++;
    }

    if (s.size() < 26) {
      for (int i = 0; i < 26; i++) {
        if (alp[i] == 0) {
          ans = s + (char)('a' + i);
          break;
        }
      }
    } else {
      string s_next = s;
      next_permutation(s_next.begin(), s_next.end());
      for (int i = 0; i < (int)s.size(); i++) {
        ans += s_next[i];
        if (s[i] != s_next[i]) break;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
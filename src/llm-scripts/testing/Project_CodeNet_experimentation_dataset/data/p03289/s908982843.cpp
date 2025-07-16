#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  bool ok = true;
  if (s[0] != 'A') ok = false;
  int cnt = 0;
  for (int i = 1; i < s.size(); i++) {
    if (i >= 2 && i <= s.size() - 2) {
      if (s[i] == 'C') {
        cnt++;
        continue;
      }
    }
    if (!islower(s[i])) {
      ok = false;
    }
  }
  if (cnt != 1) ok = false;
  if (ok) cout << "AC" << endl;
  else cout << "WA" << endl;
  return 0;
}
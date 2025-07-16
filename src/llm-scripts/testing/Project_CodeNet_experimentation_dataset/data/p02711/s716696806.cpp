#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  bool ok = false;
  if (s[0] == '7')
    ok = true;
  if (s[1] == '7')
    ok = true;
  if (s[2] == '7')
    ok = true;
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
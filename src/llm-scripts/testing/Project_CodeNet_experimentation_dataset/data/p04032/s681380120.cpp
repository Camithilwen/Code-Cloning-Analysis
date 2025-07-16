#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i=0; i<n-1; i++) {
    if (s[i] == s[i+1]) {
      cout << i+1 << ' ' << i+2 << endl;
      return 0;
    }
  }
  for (int i=0; i<n-2; i++) {
    if (s[i] == s[i+2]) {
      cout << i+1 << ' ' << i+3 << endl;
      return 0;
    }
  }
  cout << -1 << ' ' << -1 << endl;
  return 0;
}

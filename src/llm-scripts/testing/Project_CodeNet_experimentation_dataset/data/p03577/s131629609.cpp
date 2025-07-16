#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n - 8; ++i) {
    cout << s[i];
  }
  puts("");
  return 0;
}

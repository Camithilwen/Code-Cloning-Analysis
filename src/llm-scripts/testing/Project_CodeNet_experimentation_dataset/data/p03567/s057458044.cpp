#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 1; i < n; ++i) {
    if (s[i - 1] == 'A' && s[i] == 'C') {
      cout << "Yes" << '\n';
      return 0;
    }
  }
  puts("No");
  return 0;
}

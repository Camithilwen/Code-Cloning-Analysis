#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
  cin >> s;
  for (int i = 1; i < s.size(); ++i)
    if (s[i - 1] == 'A' && s[i] == 'C') {
      cout << "Yes" << endl;
      return 0;
    }
  cout << "No" << endl;
  return 0;
}

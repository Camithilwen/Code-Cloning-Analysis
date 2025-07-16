#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  if (3 == (int)s.size()) {
    reverse(s.begin(), s.end());
    cout << s << endl;
  }
  else {
    cout << s << endl;
  }
}

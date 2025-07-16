#include <iostream>
#include <string>
using namespace std;

void solve(const string& s) {
  for (int i = 0, j = 1; j < s.size(); ++i, ++j) {
    if (s[i] == s[j]) {
      cout << (i + 1) << " " << (j + 1) << "\n";
      return;
    }
  }
  for (int i = 0, j = 2; j < s.size(); ++i, ++j) {
    if (s[i] == s[j]) {
      cout << (i + 1) << " " << (j + 1) << "\n";
      return;
    }
  }
  cout << "-1 -1\n";
}

int main() {
  string s;
  cin >> s;
  solve(s);
  return 0;
}

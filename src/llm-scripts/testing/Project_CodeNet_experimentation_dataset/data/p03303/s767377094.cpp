#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  int w;
  cin >> s >> w;

  string result;
  for (int i = 0; i < s.size(); i += w) {
    result += s[i];
  }

  cout << result << '\n';
}
#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  array<vector<int>, 26> p;
  for (int i = 0; i < s.size(); ++i) {
    p[s[i] - 'a'].push_back(i);
  }

  int l = -1, r = -1;
  for (int i = 0; i < p.size() && l < 0; ++i) {
    for (int j = 1; j < p[i].size() && l < 0; ++j) {
      if (p[i][j] - p[i][j - 1] <= 2) {
        l = p[i][j - 1] + 1;
        r = p[i][j] + 1;
      }
    }
  }

  cout << l << ' ' << r << '\n';
  return 0;
}
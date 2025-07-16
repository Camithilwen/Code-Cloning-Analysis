#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  int64_t res = 0;
  vector table(20, vector(20, 0));
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    auto pos = s.find(".");
    if (pos == string::npos) {
      s += string(9, '0');
    } else {
      s.erase(s.begin() + pos);
      s += string(9 - ((int)s.size() - pos), '0');
    }
    int64_t x = static_cast<int64_t>(stoll(s));
    pair<int, int> a = make_pair(0, 0);
    while (x % 2 == 0) {
      x /= 2;
      a.first++;
    }
    while (x % 5 == 0) {
      x /= 5;
      a.second++;
    }
    a.first = min(a.first, 18);
    a.second = min(a.second, 18);
    for (int j = 18 - a.first; j < 20; j++) {
      for (int k = 18 - a.second; k < 20; k++) {
        res += table[j][k];
      }
    }
    table[a.first][a.second]++;
  }
  cout << res << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N;
  cin >> N;
  for (int i = N; i < 1000; i++) {
    string s = to_string(i);
    if (s[0] == s[1] && s[1] == s[2]) {
      cout << i << endl;
      return 0;
    }
  }
}

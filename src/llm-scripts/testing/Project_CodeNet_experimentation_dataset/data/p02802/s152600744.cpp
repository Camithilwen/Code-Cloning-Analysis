#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> wa(n), al(n);
  int ac = 0, pe = 0;
  while (m--) {
    int p;
    string s;
    cin >> p >> s;
    p--;
    if (s == "WA") {
      if (al[p] == 0) wa[p]++;
    } else {
      if (al[p] == 0) {
        pe += wa[p];
        ac++;
      }
      al[p] = 1;
    }
  }
  cout << ac << ' ' << pe;
  return 0;
}

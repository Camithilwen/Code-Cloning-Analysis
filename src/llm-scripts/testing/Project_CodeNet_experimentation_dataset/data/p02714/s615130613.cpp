#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll r = 0, g = 0, b = 0;
  for (const auto& c : s) {
    if (c == 'R')
      r++;
    else if (c == 'G')
      g++;
    else
      b++;
  }
  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int k = 2 * j - i;
      if (k <= j || k > n - 1) continue;
      if (s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) {
        cnt++;
      }
    }
  }
  ll ans = r * g * b - cnt;
  cout << ans << '\n';
  return 0;
}
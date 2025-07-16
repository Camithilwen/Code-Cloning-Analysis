#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int N;
  cin >> N;
  repe(i, N, 999) {
    string s = to_string(i);
    bool ok = true;
    rep(j, 1, s.size()) if (s[j - 1] != s[j]) ok = false;
    if (ok) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}

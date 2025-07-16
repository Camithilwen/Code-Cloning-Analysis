#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;

  for (int i = n; i >= 0; --i) {
    string u = s;
    for (int j = i; j < n; ++j) u += t[j];
    bool same_t = true;
    rep(j, n) if (u[u.size() - 1 - j] != t[t.size() - 1 - j]) same_t = false;
    if (same_t) {
      cout << 2 * n - i << endl;
      return 0;
    }
  }
  return 0;
}
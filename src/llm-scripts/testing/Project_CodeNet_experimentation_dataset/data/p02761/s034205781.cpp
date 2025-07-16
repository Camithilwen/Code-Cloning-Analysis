#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n, m;
  cin >> n >> m;
  vector<char> res(n, 0);
  for (int i = 1; i <= m; i++) {
    int s; char c;
    cin >> s >> c;
    s--;
    if (res[s] == 0) res[s] = c;
    else if (res[s] != c) {
      cout << -1 << '\n';
      return;
    }
  }
  if (n > 1) {
    if (res[0] == '0') {
      cout << -1 << '\n';
      return;
    }
    if (res[0] == 0) {
      res[0] = '1';
    }
  }
  for (auto &i : res) {
    if (i == 0) cout << '0';
    else cout << i;
  }
  cout << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    int f = 0;
    for (int j = 0; i + j < n; j++) {
      if (a[j + i] != b[j]) {
        f = 1;
        break;
      }
    }
    if (!f) {
      cout << n + i << '\n';
      return;
    }
  }
  cout << n + n << '\n';
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

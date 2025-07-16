#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void MAIN() {
  int n;
  cin >> n;
  vector<vector<int>> a(3, vector<int>(n));
  vector<vector<int>> d(3, vector<int>(n));
  for (auto &i : a) {
    for (auto &j : i) cin >> j;
    sort(all(i));
  }
  for (int i = n - 1; i >= 0; i--) {
    d[2][i] = 1;
    if (i != n - 1) d[2][i] += d[2][i + 1];
  }
  for (int i = 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      int p = upper_bound(all(a[i + 1]), a[i][j]) - a[i + 1].begin();
      if (p != n) d[i][j] = d[i + 1][p];
      if (j != n - 1) d[i][j] += d[i][j + 1];
    }
  }
  cout << d[0][0] << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}

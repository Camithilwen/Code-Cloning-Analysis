#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
constexpr int INF = 2e9 + 1;
int main() {
  int n, l, q;
  cin >> n;
  vector<int> x(n);
  rep(i,n) cin >> x[i];
  cin >> l >> q;
  vector<vector<int>> to(32, vector<int>(n, 0));
  x.emplace_back(INF);
  rep(i, n) {
    auto itr = lower_bound(x.begin(), x.end(), x[i] + l);
    if (*itr > x[i] + l) itr--;
    to[0][i] = itr - x.begin();
  }
  for (int i = 0; i < 31; i++) {
    for (int j = 0; j < n; j++) to[i + 1][j] = to[i][to[i][j]];
  }

  while (q--) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    if (a > b) swap(a, b);
    int res = 0;
    for (int i = 31; i >= 0; i--) {
      if (to[i][a] < b) {
        res += 1 << i;
        a = to[i][a];
      }
    }
    cout << res + 1 << endl;
  }
  return 0;
} 
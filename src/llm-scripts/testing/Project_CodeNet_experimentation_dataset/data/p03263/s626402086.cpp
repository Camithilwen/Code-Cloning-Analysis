#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w)), ans;
  rep(i, h) rep(j, w) cin >> a[i][j];

  rep(i, h - 1) rep(j, w) {
    if (a[i][j] % 2 == 1) {
      ans.push_back({i + 1, j + 1, i + 2, j + 1});
      // cout << i + 1 << " " << j + 1 << " " << i + 2 << " " << j + 1 << endl;
      a[i][j]--;
      a[i + 1][j]++;
    }
  }
  rep(i, w - 1) {
    if (a[h - 1][i] % 2 == 1) {
      ans.push_back({h, i + 1, h, i + 2});
      // cout << h - 1 << " " << i + 1 << " " << h - 1 << " " << i + 2 << endl;
      a[h - 1][i]--;
      a[h - 1][i + 1]++;
    }
  }

  cout << ans.size() << endl;
  rep(i, ans.size()) rep(j, 4) printf("%d%c", ans[i][j], (j == 3 ? '\n' : ' '));
  // rep(i, h) rep(j, w)
  //     fprintf(stderr, "%d%c", a[i][j], (j == w - 1 ? '\n' : ' '));
  return 0;
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define shosu(n) setprecision(n)
using namespace std;

char ss[12][12];

void dfs(int x, int y) {
  if (x < 0 || y < 0 || x >= 12 || y >= 12 || ss[y][x] == '0')
    return;
  ss[y][x] = '0';
  dfs(x + 1, y);
  dfs(x - 1, y);
  dfs(x, y + 1);
  dfs(x, y - 1);
}
int main() {
  int n, ans = 0;
  while (cin >> ss[0][0]) {
    ans = 0;
    rep(i, 12) rep(j, 12) {
      if (i == 0 && j == 0)
        ;
      else
        cin >> ss[i][j];
    }
    rep(i, 12) rep(j, 12) {
      if (ss[i][j] == '1') {
        ans++;
        dfs(j, i);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
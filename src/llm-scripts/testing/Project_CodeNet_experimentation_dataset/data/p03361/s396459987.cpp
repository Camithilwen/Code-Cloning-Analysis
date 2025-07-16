#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  rep(i, h) rep(j, w) cin >> s[i][j];

  bool able = true;
  int di[] = {1, 0, -1, 0};
  int dj[] = {0, 1, 0, -1};
  rep(i, h) rep(j, w) {
    if (s[i][j] == '.') continue;
    bool is_dot = true;
    rep(k, 4) {
      int ni = i + di[k];
      int nj = j + dj[k];
      if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
      if (s[ni][nj] == '#') is_dot = false;
    }
    if (is_dot) able = false;
  }
  if (able) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
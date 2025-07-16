#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;

  vector<vector<int>> s(h, vector<int>(w));
  rep(i, h) rep(j, w) {
    if (i < b && j < a || i >= b && j >= a) s[i][j] = 0;
    else s[i][j] = 1;
  }
  rep(i, h) {
    rep(j, w) cout << s[i][j];
    cout << endl;
  }
  return 0;
}
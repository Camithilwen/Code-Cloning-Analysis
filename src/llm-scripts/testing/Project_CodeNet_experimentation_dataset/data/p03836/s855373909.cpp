#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  string ans;
  auto move = [&](int h, int w) {
    rep(i, abs(h)) ans += (h > 0 ? 'U' : 'D');
    rep(i, abs(w)) ans += (w > 0 ? 'R' : 'L');
  };

  int h1 = ty - sy, w1 = tx - sx;
  move(h1, w1);

  int h2 = sy - ty, w2 = sx - tx;
  move(h2, w2);

  int h3 = ty - sy, w3 = tx - sx;
  ans += (w3 > 0 ? 'L' : 'R');
  h3 += (h3 > 0 ? 1 : -1);
  w3 += (w3 > 0 ? 1 : -1);
  move(h3, w3);
  ans += (h3 > 0 ? 'D' : 'U');

  int h4 = sy - ty, w4 = sx - tx;
  ans += (w4 > 0 ? 'L' : 'R');
  h4 += (h4 > 0 ? 1 : -1);
  w4 += (w4 > 0 ? 1 : -1);
  move(h4, w4);
  ans += (h4 > 0 ? 'D' : 'U');

  cout << ans << endl;
  return 0;
}

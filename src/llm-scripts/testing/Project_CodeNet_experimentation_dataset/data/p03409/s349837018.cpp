#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n, x, y;
  cin >> n;
  vector<P> red, blue;
  vector<bool> is_pair_red(n, false), is_pair_blue(n, false);
  rep(i, n) {
    cin >> x >> y;
    red.emplace_back(y, x);
  }
  rep(i, n) {
    cin >> x >> y;
    blue.emplace_back(x, y);
  }
  sort(red.rbegin(), red.rend());
  sort(blue.begin(), blue.end());

  ll ans = 0;
  rep(i, n) {
    rep(j, n) {
      if (is_pair_red[j] || is_pair_blue[i]) continue;
      int bx = blue[i].first, by = blue[i].second;
      int rx = red[j].second, ry = red[j].first;
      if (rx < bx && ry < by) {
        is_pair_red[j] = true;
        is_pair_blue[i] = true;
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

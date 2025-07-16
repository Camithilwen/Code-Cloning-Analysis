#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  rep(i, n) cin >> x.at(i);
  vector<int> minus;
  vector<int> plus;
  rep(i, n) {
    int xx = x.at(i);
    if (xx >= 0) {
      plus.push_back(xx);
    } else {
      minus.push_back(-xx);
    }
  }
  reverse(minus.begin(), minus.end());
  ll res = 1L << 30;
  // マイナスから折り返す
  rep(i, min((int) minus.size(), k)) {
    ll tmp = 0;
    tmp += 2 * minus.at(i);
    int plusCnt = k - 1 - i;
    if (plusCnt > (int) plus.size()) {
      continue;
    }
    if (plusCnt > 0) {
      tmp += plus.at(plusCnt - 1);
    }
    res = min(res, tmp);
  }
  // プラスから折り返す
  rep(i, min((int) plus.size(), k)) {
    ll tmp = 0;
    tmp += 2 * plus.at(i);
    int minusCnt = k - 1 - i;
    if (minusCnt > (int) minus.size()) {
      continue;
    }
    if (minusCnt > 0) {
      tmp += minus.at(minusCnt - 1);
    }
    res = min(res, tmp);
  }
  // 全部どちらかの場合
  if ((int) minus.size() >= k) {
    res = min(res, (ll) minus.at(k - 1));
  }
  if ((int) plus.size() >= k) {
    res = min(res, (ll) plus.at(k - 1));
  }
  cout << res << endl;
  return 0;
}
